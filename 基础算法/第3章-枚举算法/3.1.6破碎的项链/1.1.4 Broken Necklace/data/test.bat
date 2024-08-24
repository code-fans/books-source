@echo off
if "%1"=="" goto loop
copy beads%1.in beads.in >nul
echo Problem Test %1
beads

fc beads.out beads%1.ans
del beads.in
del beads.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8) do call %0 %%i
:end
