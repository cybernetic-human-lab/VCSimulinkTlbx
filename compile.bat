@echo OFF
set MATLAB_DIR=C:\Program Files\MATLAB\R2018b

REM set FLAGS=-g
call "%MATLAB_DIR%\bin\mex.bat" %FLAGS% faceString.cpp faceString_wrapper.cpp -outdir Library
call "%MATLAB_DIR%\bin\mex.bat" %FLAGS% gazeString.cpp gazeString_wrapper.cpp -outdir Library
call "%MATLAB_DIR%\bin\mex.bat" %FLAGS% pawnPos.c pawnPos_wrapper.c -outdir Library
call "%MATLAB_DIR%\bin\mex.bat" %FLAGS% AUsMaleBML.cpp AUsMaleBML_wrapper.cpp -outdir Library
call "%MATLAB_DIR%\bin\mex.bat" %FLAGS% AUsFemaleBML.cpp AUsFemaleBML_wrapper.cpp -outdir Library
call "%MATLAB_DIR%\bin\mex.bat" %FLAGS% breathingJSON.cpp breathingJSON_wrapper.cpp -outdir Library

pause