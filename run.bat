@echo off
g++ -I src main.cpp src/*.cpp -o bin/HospitalSystem
if %errorlevel% NEQ 0 (
	echo Compilation failed!
	pause
	exit /b %errorlevel%
)

echo Compilation suceeded! Executable is in the bin folder
cd bin
pause
HospitalSystem.exe
pause
