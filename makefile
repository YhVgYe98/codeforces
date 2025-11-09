USE_LANG ?= cpp
Q ?= main

SRC_BASE      := $(Q)
IN_FILE       := $(SRC_BASE)_in.txt
OUT_FILE      := $(SRC_BASE)_out.txt
TEMPLATE_DIR  := ./template

# ===================================================

.PHONY: all new test build run clean clean-all help

all: test

new:
	@if [ -f "$(SRC)" ]; then \
		echo "Error: Source file '$(SRC)' already exists." >&2; exit 1; \
	fi
	@if [ ! -f "$(TEMPLATE_FILE)" ]; then \
		echo "Error: C++ template file '$(TEMPLATE_FILE)' not found." >&2; exit 1; \
	fi
	@echo "Creating new C++ source file '$(SRC)'..."
	@cp '$(TEMPLATE_FILE)' '$(SRC)'
	@touch '$(IN_FILE)'
	@echo "Files '$(SRC)' and '$(IN_FILE)' created successfully."

test: _run_test

build: _build_debug

run: _run_release

clean: _clean

clean-all:
	@echo "===== Deleting ALL generated files (input, output, binary, etc.) ====="
	rm -f *.out *.o *_in.txt *_out.txt
	rm -rf '$(TARGET_DIR)'  # For Rust
	rm -rf __pycache__/ # For Python

LANG_MAKEFILE := makefile-$(USE_LANG)
ifeq ($(wildcard $(LANG_MAKEFILE)),)
    $(error Unsupported language '$(USE_LANG)'. Missing file '$(LANG_MAKEFILE)'.)
endif
include $(LANG_MAKEFILE)

# makefile-$(USE_LANG) need below
# var: $(SRC) $(IN_FILE)
# target: _build_debug _run_release _run_test _clean
