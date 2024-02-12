import os
import shutil

directory_to_remove = "./bin/build64"

def chmod_recursive(directory):
    for root, dirs, files in os.walk(directory):
        for dir in dirs:
            dir_path = os.path.join(root, dir)
            os.chmod(dir_path, 0o755)
        for file in files:
            file_path = os.path.join(root, file)
            os.chmod(file_path, 0o644)

def run_clean():
    try:
        chmod_recursive(directory_to_remove)
        shutil.rmtree(directory_to_remove)
        print(f"Successfully removed directory: {directory_to_remove}")
    except FileNotFoundError:
        print(f"Directory {directory_to_remove} does not exist.")
    except Exception as e:
        print(f"An error occurred while removing directory {directory_to_remove}: {e}")
    
run_clean()
