g++ travel.cpp -o std -g
@echo off
for /L %%i in (0,1,30) do (
	@echo %%i
	mk_tem <salesman%%i.in >input.txt
	del salesman%%i.in
	copy input.txt salesman%%i.in
	del input.txt
	std <salesman%%i.in >salesman%%i.out
)
pause