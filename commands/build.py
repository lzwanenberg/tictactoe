import subprocess
import sys

def run_cmake_build():
    try:
        command = [
            "cmake",
            "--build", "./bin/build64",
            "--config", "Debug"
        ]

        command.extend(sys.argv[1:])

        subprocess.run(command, check=True)
        print("CMake build command executed successfully.")
    except subprocess.CalledProcessError as e:
        print(f"Error: CMake build command failed with return code {e.returncode}.")
        print(f"Output: {e.output.decode()}")

run_cmake_build()
