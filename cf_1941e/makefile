.PHONY: duipai run_test test

mytest = $(shell cd)

test:
	echo $(mytest)

duipai: .\target\release\$(name).exe .\src\bin\std.exe
	python duipai.py


run_test: .\target\release\$(name).exe .\src\bin\std.exe std_in
	.\src\bin\std.exe < std_in > std_out
	.\target\release\cf_1941e.exe < std_in > my_out


.\target\release\$(name).exe: .\src\main.rs
	cargo build --release


.\src\bin\std.exe: .\src\bin\std.cc
	g++ .\src\bin\std.cc -o \src\bin\std.exe
