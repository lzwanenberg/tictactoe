import subprocess

def run_init():
    try:
        command = [
            "cmake",
            "-G", "Visual Studio 17 2022",
            "-A", "x64",
            "-S", ".",
            "-B", "./bin/build64"
        ]
        
        subprocess.run(command, check=True)
    except subprocess.CalledProcessError as e:
        print(f"Error: CMake command failed with return code {e.returncode}.")
        print(f"Output: {e.output.decode()}")

run_init()
