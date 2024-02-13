
import os
import subprocess
from dataclasses import dataclass
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

def remove_suffix(input_str, suffix):
    if input_str.endswith(suffix):
        return input_str[:-len(suffix)]
    return input_str

def path_to_id(path):
    id = path.replace("\\", "/")
    id = id.replace("/Debug/", "/")
    id = id.replace("/src/", "/")

    parts = id.split("/Tests/")
    if len(parts) > 1:
        id = id.split("/Tests/")[1]
    
    if id.startswith("src/"):
        id = id[len("src/"):]

    id = remove_suffix(id, '.c')
    id = remove_suffix(id, '.exe')
    id = remove_suffix(id, '.test')

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
    file_failure_count = 0

    for file_results in test_file_results:
        if len(file_results.results) == 0:
            file_failure_count += 1
            
        for result in file_results.results:
            if result.status == Status.FAIL:
                file_failure_count += 1
                break

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
                    path=path.replace("\\", "/")
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

    if len(tests) == 0:
        status = Status.FAIL

    filename = test_file.filename.replace('.test.exe', '.test.c')

    relative_path = get_relative_path(test_file)
    last_slash_index = relative_path.rfind('/')
    relative_path = relative_path[:last_slash_index + 1]

    return TestFileResult(
        raw=lines,
        filename=filename,
        relative_path=relative_path,
        status=status,
        results=tests,
        summary=summary
    )

def get_relative_path(test_file):
    path = test_file.path

    path = path.replace("bin/build64/Tests", "src")
    path = path.replace(".test.exe", ".test.c")
    path = path.replace("/Debug/", "/")

    return path

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

    print(f'{get_icon(test_file_result.status)} {gray(test_file_result.relative_path)}{test_file_result.filename}')

    if len(test_file_result.results) == 0:
        print(italic("   No tests found"))

    for result in test_file_result.results:
        print_test_result(result)

def print_test_result(test_result):
    name = f'{test_result.function_name}:{test_result.line_number}'
    print(f'  {get_icon(test_result.status)} {gray(name)}{": " if test_result.message != "" else ""}{test_result.message}')

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
    print(f'Tests:      {red(str(test_failures) + " failed, ") if test_failures > 0 else ""}{green(str(test_passes) + " passed, " if test_passes > 0 else "")}{str(test_total)} total')

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

def gray(text):
    return ansi(90, text)

def italic(text):
    return ansi(3, text)

def ansi(id, text):
    return f'\033[{id}m{text}\033[0m'

def test(test_directory, query = '*'):
    query = sys.argv[1] if len(sys.argv) > 1 else '*'

    suite_result = run_tests(
        test_directory=test_directory,
        query=query
    )

    success = suite_result.files_summary['failures'] == 0
    return 0 if success else 1
