set name=roller
for /l %%i in (1,1,10) do (
	mkd > %name%%%i.in
	%name% <%name%%%i.in >%name%%%i.out
)
pause