import argparse
from lib.get_test_id import get_test_id
from config.config import Config
import sys
import os
from procedures.initialize import initialize
from procedures.build import build
from procedures.test import test
from io import StringIO

description ="""
Test hook that can be configured to be executed e.g. on file save.
The hook will only run if a .c file is provided. In this case the hook
will build the project and reinitialize if necessary. This is usually
the case if a new *.test.c file has been added, as it has not yet been
discovered by CMake.
"""

def greet(path):
    """
    
    Args:
        path (str): Path to the file that might need testing.

    Returns:
        int: exit code 0 if successful, otherwise 1
    """
    print(get_test_id("john"))

def is_c_file(path):
    return path.endswith('c')

def inject_debug_directory(path):
    last_slash_index = path.rfind("/") 
    return f"{path[:last_slash_index]}{Config.DEBUG_DIRECTORY}{path[last_slash_index:]}"

def get_exe_path(id):
    return inject_debug_directory(f"{Config.TEST_DIRECTORY}/{id}.test.exe")

def executeable_exists(path):
    return os.path.exists(path)

def run(path):
    if not is_c_file(path):
        return Config.EXIT_SUCCESS

    id = get_test_id(path)
    exe_path = get_exe_path(id)
    exe_exists = executeable_exists(exe_path)

    if not exe_exists:
        init_result = initialize()
        if init_result == Config.EXIT_FAILURE:
            return
    
    os.system('clear')

    build_result = build()

    if build_result == Config.EXIT_FAILURE:
        return Config.EXIT_FAILURE

    os.system('clear')

    test(
        test_directory=Config.TEST_DIRECTORY,
        query=exe_path
    )

def main():
    parser = argparse.ArgumentParser(description=description)
    parser.add_argument('path', metavar='PATH', type=str, help='Relative path to the file to test')
    args = parser.parse_args()

    exit_code = run(path=args.path)
    sys.exit(exit_code)

if __name__ == "__main__":
    main()
