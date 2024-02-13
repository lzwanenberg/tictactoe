import os
import subprocess
from dataclasses import dataclass, field
from enum import Enum
import sys
from typing import List

TEST_DIRECTORY = "bin/build64/Tests"

class Status(Enum):
    PASS = 'PASS'
    FAIL = 'FAIL'

@dataclass
class TestFile:
    filename: str
    path: str

@dataclass
class TestFunctionResult:
    raw: str
    line_number: int
    function_name: str
    status: Status
    message: str

@dataclass
class TestFileResult:
    raw: List[str]
    filename: str
    relative_path: str
    results: List[TestFunctionResult]
    status: Status
    summary: dict 

@dataclass
class TestSuiteResult:
    results: List[TestFileResult]
    files_summary: dict
    functions_summary: dict

def path_to_id(path):
    id = path.replace("\\", "/")
    id = id.replace("/Debug/", "/")
    id = id.replace("/src/", "/")

    parts = id.split("/Tests/")
    if len(parts) > 1:
        id = id.split("/Tests/")[1]
    
    if id.startswith("src/"):
        id = id[len("src/"):]

    id = id.replace(".test.exe", ".test.c")

    return id

        
def should_run(test_file, query_id):
    if query_id == '*':
        return True

    file_id = path_to_id(test_file.path)

    return query_id in file_id

def run_tests(test_directory, query):
    test_files = discover_test_files(test_directory)
    test_file_results = []

    for test_file in test_files:
        if not should_run(test_file, path_to_id(query)):
            continue

        result = run_test(test_file)
        print("")
        print_test_file_result(result)
        test_file_results.append(result)

    suite_result = create_test_suite_result(test_file_results)

    print("")
    print_test_suite_result(suite_result)

    return suite_result

def create_test_suite_result(test_file_results):
    file_count = len(test_file_results)
    file_failure_count = sum(1 for result in test_file_results if result.status == Status.FAIL)
    tests_count = sum(len(result.results) for result in test_file_results)
    test_fail_count = (sum(sum(1 for test in result.results if test.status == Status.FAIL) for result in test_file_results))
    test_pass_count = (sum(sum(1 for test in result.results if test.status == Status.PASS) for result in test_file_results))

    return TestSuiteResult(
        results=test_file_results,
        files_summary={
            "total": file_count,
            "failures": file_failure_count
        },
        functions_summary={
            "total": tests_count,
            "passes": test_pass_count,
            "failures": test_fail_count
        }
    )

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
    status = Status.FAIL if last_line == Status.FAIL.value else Status.PASS

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
    status = Status[subparts[2].strip()]
    message = "" if status == Status.PASS else subparts[3].strip()

    return TestFunctionResult(
        raw=line,
        line_number=line_number,
        function_name=function_name,
        status=status,
        message=message
    )

def parse_summary(string):
    words = string.split()

    total = int(words[0])
    failures = int(words[2])
    ignored = int(words[4])
    passes = total - failures - ignored

    return {
        Status.PASS: passes,
        Status.FAIL: failures
    }

def print_test_file_result(test_file_result):
    print(f'{get_icon(test_file_result.status)} {test_file_result.relative_path}')

    for result in test_file_result.results:
        print_test_result(result)

def print_test_result(test_result):
    print(f'  {get_icon(test_result.status)} {test_result.function_name}:{test_result.line_number}{": " if test_result.message != "" else ""}{test_result.message}')

def print_test_suite_result(suite):
    file_failures = suite.files_summary['failures']
    file_total = suite.files_summary['total']

    test_passes = suite.functions_summary['passes']
    test_failures = suite.functions_summary['failures']
    test_total = suite.functions_summary['total']

    if (not file_total):
        print("No test files found.")
        return

    print(f'Test Files: {red(str(file_failures) + " failed, ") if file_failures > 0 else ""}{str(file_total)} total')
    print(f'Tests:      {red(str(test_failures) + " failed, ") if test_failures > 0 else ""}{green(str(test_passes) + " passed, ")}{str(test_total)} total')

def get_icon(status):
    match status:
        case Status.PASS:
            return green("✔")
        
        case Status.FAIL:
            return red("❌")
        
        case _:
            return "?"

def red(text):
    return ansi(91, text)

def green(text):
    return ansi(92, text)

def ansi(id, text):
    return f'\033[{id}m{text}\033[0m'



def main(test_directory):
    query = sys.argv[1] if len(sys.argv) > 1 else '*'

    suite_result = run_tests(
        test_directory=test_directory,
        query=query
    )

    success = suite_result.files_summary['failures'] == 0
    return 0 if success else 1


if __name__ == "__main__":
    exit_code = main(test_directory=TEST_DIRECTORY)
    sys.exit(exit_code)
