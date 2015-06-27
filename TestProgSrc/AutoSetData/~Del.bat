@echo on
for /r /d %%i in (Debug) do (del /q "%%i"
rd "%%i")
for /r /d %%i in (Release) do (del /q "%%i"
rd "%%i")

for /f "delims=" %%i in ('dir/b/s/a-d *.user') do (del "%%i")
for /f "delims=" %%i in ('dir/b/s/a-d *.ncb') do (del "%%i")
