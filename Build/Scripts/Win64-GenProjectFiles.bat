@echo off
pushd "%~dp0\..\premake"

echo Generating Visual Studio project files...
call "Win64/premake5.exe" --file="ProjectFiles.lua" vs2022

popd
pause