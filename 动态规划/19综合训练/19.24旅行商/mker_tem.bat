g++ travel.cpp -o std -g
@echo off
for /L %%i in (1,1,10) do (
	@echo %%i
	std <salesman%%i.in	>salesman%%i.out
)
pause