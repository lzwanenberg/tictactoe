@echo off

rem Set the directory where the Python scripts are located
set COMMANDS_DIR=commands

rem Get the first argument passed to the script
set COMMAND=%1

rem Shift the arguments to remove the first one
shift

for /f "tokens=1,* delims= " %%a in ("%*") do set ALL_BUT_FIRST=%%b

rem Check if a matching Python script exists in the commands directory
if exist "%COMMANDS_DIR%\%COMMAND%.py" (
    rem Execute the Python script with the remaining arguments
    python "%COMMANDS_DIR%\%COMMAND%.py" %ALL_BUT_FIRST%
) else (
    echo Error: Command "%COMMAND%" not found
    exit /b 1
)
