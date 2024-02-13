import subprocess

def initialize():
    try:
        command = [
            "cmake",
            "-G", "Visual Studio 17 2022",
            "-A", "x64",
            "-S", ".",
            "-B", "./bin/build64"
        ]
        
        subprocess.run(command, check=True)
        return 0
    except subprocess.CalledProcessError as e:
        return 1
