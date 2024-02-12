import subprocess

def run_start():
    try:
        # Define the path to the executable
        executable_path = "bin/build64/Debug/TicTacToe.exe"

        # Run the executable
        subprocess.run(executable_path, check=True)
        print("TicTacToe.exe executed successfully.")
    except subprocess.CalledProcessError as e:
        print(f"Error: Execution of TicTacToe.exe failed with return code {e.returncode}.")
        print(f"Output: {e.output.decode()}")

# Example usage
run_start()
