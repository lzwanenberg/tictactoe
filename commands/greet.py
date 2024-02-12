# ./commands/greet.py

import sys

def greet(name):
    print("Hello, " + name)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python greet.py <name>")
        sys.exit(1)

    name = sys.argv[1]
    greet(name)
