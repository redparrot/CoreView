@echo off

for /f "delims=" %%i in ('dir/b/s/a-d *.user') do (del %%i)
for /f "delims=" %%i in ('dir/b/s/a-d *.ncb') do (del %%i)
for /f "delims=" %%i in ('dir/b/s/a-d *.sdf') do (del %%i)
for /f "delims=" %%i in ('dir/b/s/a-d *.vspx') do (del %%i)

for /r . %%a in (.) do @if exist "%%a\ipch" rd /s /q "%%a\ipch"
for /r . %%a in (.) do @if exist "%%a\Release" rd /s /q "%%a\Release"
for /r . %%a in (.) do @if exist "%%a\Debug" rd /s /q "%%a\Debug"
for /r . %%a in (.) do @if exist "%%a\.svn" rd /s /q "%%a\.svn"
