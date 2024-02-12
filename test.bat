@echo off

rem Set the directory where the test executables are located
set TEST_DIRECTORY=bin\build64\Tests

rem Loop through all .test.exe files in the specified directory and its subfolders
for /r "%TEST_DIRECTORY%" %%F in (*.test.exe) do (
    for /f "delims=" %%L in ('%%F') do (
        echo Hello: %%L
    )
)
