@echo OFF
set MATLAB_DIR=C:\Program Files\MATLAB\R2018b

REM set FLAGS=-g
call "%MATLAB_DIR%\bin\mex.bat" %FLAGS% faceStringCHL.cpp faceStringCHL_wrapper.cpp faceStringCHL_mycode.cpp -outdir ..\Library

pause