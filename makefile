prefix = cf_
name = temp_project
lang = rust

.PHONY: all clean open_vscode create_project

all: create_project open_vscode

open_vscode: 
	code .\$(prefix)$(name)\



required_files = 
ifeq ($(lang), cpp)
	required_files = .\$(prefix)$(name)\main.cc .\$(prefix)$(name)\CMakeLists.txt 
else
	required_files = .\$(prefix)$(name)\src\main.rs
endif
create_project: $(required_files)


.\$(prefix)$(name)\main.cc:
	mkdir $(prefix)$(name)
	@type .\solution_temple\src\main.cc			>.\$(prefix)$(name)\main.cc

.\$(prefix)$(name)\CMakeLists.txt:
	@echo cmake_minimum_required(VERSION 3.10)	>.\$(prefix)$(name)\CMakeLists.txt
	@echo project($(prefix)$(name))						>>.\$(prefix)$(name)\CMakeLists.txt
	@echo add_executable($(prefix)$(name) main.cc)		>>.\$(prefix)$(name)\CMakeLists.txt

.\$(prefix)$(name)\src\main.rs:
	cargo new $(prefix)$(name)
	@type .\solution_temple\src\main.rs			>.\$(prefix)$(name)\src\main.rs
	@type .\solution_temple\duipai.py			>.\$(prefix)$(name)\duipai.py

clean:
	del /s /q $(prefix)$(name)
	rmdir /s /q $(prefix)$(name)