@echo OFF
set MATLAB_DIR=C:\Program Files\MATLAB\R2016a


set FLAGS=-g

call "%MATLAB_DIR%\bin\mex.bat" %FLAGS% faceString.cpp faceString_wrapper.cpp

call "%MATLAB_DIR%\bin\mex.bat" %FLAGS% gazeString.cpp gazeString_wrapper.cpp

call "%MATLAB_DIR%\bin\mex.bat" %FLAGS% pawnPos.c pawnPos_wrapper.c

call "%MATLAB_DIR%\bin\mex.bat" %FLAGS% AUsMaleBML.cpp AUsMaleBML_wrapper.cpp

call "%MATLAB_DIR%\bin\mex.bat" %FLAGS% AUsFemaleBML.cpp AUsFemaleBML_wrapper.cpp




