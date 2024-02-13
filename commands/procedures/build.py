import subprocess
import sys

def build():
    try:
        command = [
            "cmake",
            "--build", "./bin/build64",
            "--config", "Debug"
        ]
        subprocess.run(command, check=True)
        return 0
    except subprocess.CalledProcessError as e:
        return 1
