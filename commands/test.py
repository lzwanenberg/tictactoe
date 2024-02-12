import os
import subprocess
from dataclasses import dataclass, field
from enum import Enum
from typing import List

TEST_DIRECTORY = "bin/build64/Tests"

class TestStatus(Enum):
    PASS = 'PASS'
    FAIL = 'FAIL'

class TestFileStatus(Enum):
    OK = 'OK'
    FAIL = 'FAIL'

class TestSummaryItem(Enum):
    Tests = 'Tests'
    Failures = 'Failures'
    Ignored = 'Ignored'

@dataclass
class TestFile:
    filename: str
    path: str

@dataclass
class TestFunctionResult:
    raw: str
    line_number: int
    function_name: str
    status: TestStatus
    message: str

@dataclass
class TestFileResult:
    raw: List[str]
    filename: str
    relative_path: str
    results: List[TestFunctionResult]
    status: TestFileStatus
    summary: dict 

def run_tests(test_directory):
    test_files = discover_test_files(test_directory)
    test_file_results = []

    for test_file in test_files:
        result = run_test(test_file)
        print("")
        print_test_file_result(result)
        test_file_results.append(result)

def discover_test_files(test_directory):
    test_files = []
    for root, _, files in os.walk(test_directory):
        for file in files:
            if file.endswith(".test.exe"):
                path = os.path.join(root, file)
                test_file = TestFile(
                    filename=file,
                    path=path
                )
                test_files.append(test_file)

    return test_files

def run_test(test_file):
    try:
        result = subprocess.run([test_file.path], capture_output=True, text=True)
        output_lines = result.stdout.splitlines()

        return parse_test_file_result(test_file, output_lines)
    except subprocess.CalledProcessError as e:
        print(f"Error running {test_file.path}: {e}")


def parse_test_file_result(test_file, lines):
    # OK|FAIL
    last_line = lines[len(lines) - 1]
    status = TestFileStatus[last_line]

    # x Tests y Failures z Ignored
    second_to_last_line = lines[len(lines)- 2] 
    summary = parse_summary(second_to_last_line)

    tests = []
    for line in [s for s in lines if ':' in s]:
        test_result = parse_test_result(line)
        tests.append(test_result)

    relative_path = get_relative_path(lines[0])

    return TestFileResult(
        raw=lines,
        filename=test_file.filename,
        relative_path=relative_path,
        status=status,
        results=tests,
        summary=summary
    )

def get_relative_path(line):
    return 'src/' + line.replace("\\", "/").split(".test.c:")[0].split("src/")[1] + ".test.c"


def parse_test_result(line):
    line = line.replace("\\", "/")
    parts = line.split(".test.c:")

    if (len(parts) != 2):
        raise "Couldn't parse line: '" + line + "'"

    subparts = parts[1].split(":")

    line_number = int(subparts[0].strip())
    function_name = subparts[1].strip()
    status = TestStatus[subparts[2].strip()]
    message = "" if status == TestStatus.PASS else subparts[3].strip()

    return TestFunctionResult(
        raw=line,
        line_number=line_number,
        function_name=function_name,
        status=status,
        message=message
    )

def parse_summary(string):
    words = string.split()

    return {
        TestSummaryItem.Tests: int(words[0]),
        TestSummaryItem.Failures: int(words[2]),
        TestSummaryItem.Ignored: int(words[4]),
    }

def print_test_file_result(test_file_result):
    print(f'{get_icon(test_file_result.status)} {test_file_result.relative_path}')

    for result in test_file_result.results:
        print_test_result(result)

def print_test_result(test_result):
    print(f'  {get_icon(test_result.status)} {test_result.function_name}:{test_result.line_number}{": " if test_result.message != "" else ""}{test_result.message}')

def get_icon(status):
    match status:
        case TestFileStatus.OK:
            return "✔"
        
        case TestFileStatus.FAIL:
            return "❌"

        case TestStatus.PASS:
            return "✔"
        
        case TestStatus.FAIL:
            return "❌"
        
        case _:
            return "?"


run_tests(test_directory=TEST_DIRECTORY)
