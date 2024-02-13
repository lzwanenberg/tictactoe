import sys
from config.config import Config
from procedures.test import test

if __name__ == "__main__":
    query = sys.argv[1] if len(sys.argv) > 1 else '*'
    exit_code = test(
        test_directory=Config.TEST_DIRECTORY,
        query=query
    )
    sys.exit(exit_code)
