@echo OFF
set LIB_NAME=VCSimulinkTlbx
set USER_MATLAB_DIR=%USERPROFILE%\Documents\MATLAB
set INSTALL_DIR=%USER_MATLAB_DIR%\%LIB_NAME%
mkdir %INSTALL_DIR%

echo copying files to %INSTALL_DIR%
REM pause

copy VCTlbx.slx     %INSTALL_DIR%
copy slblocks.m        %INSTALL_DIR%
copy pawnPos.mexw64    %INSTALL_DIR%
copy gazeString.mexw64 %INSTALL_DIR%
copy faceString.mexw64 %INSTALL_DIR%
copy AUsMaleBML.mexw64   %INSTALL_DIR%
copy AUsFemaleBML.mexw64 %INSTALL_DIR%
copy breathingJSON.mexw64 %INSTALL_DIR%
