import os
import subprocess
from dataclasses import dataclass

TEST_DIRECTORY = "bin/build64/Tests"

@dataclass
class TestFile:
    filename: str
    path: str

def run_tests(test_directory):
    test_files = discover_test_files(test_directory)

    for test_file in test_files:
        run_test(test_file)

    print("Done")

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
        if output_lines:
            print(f"Running {test_file.path}:")
            for line in output_lines:
                print(f"  {line}")

    except subprocess.CalledProcessError as e:
        print(f"Error running {test_file.path}: {e}")


run_tests(test_directory=TEST_DIRECTORY)
