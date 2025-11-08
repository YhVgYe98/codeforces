USE_LANG ?= cpp
Q ?= main

ifeq ($(USE_LANG), cpp)
    COMPILER      := g++
    SOURCE_EXT    := .cc
    TEMPLATE_FILE := ./template/main.cc
    COMPILE_FLAGS := -std=c++17 -Wall
    RELEASE_FLAGS := -O2
    DEBUG_FLAGS   := -DDEBUG -g -fsanitize=address,undefined
else ifeq ($(USE_LANG), rust)
    COMPILER      := rustc
    SOURCE_EXT    := .rs
    TEMPLATE_FILE := ./template/main.rs
	COMPILE_FLAGS := --crate-type bin -C
    RELEASE_FLAGS := opt-level=3
    DEBUG_FLAGS   := debuginfo=2 -C overflow-checks=on
else
    $(error Unsupported language: $(USE_LANG))
endif

SRC := $(Q)$(SOURCE_EXT)
TARGET_DEBUG := $(Q)_debug.out
TARGET := $(Q).out

IN_FILE := $(Q)_in.txt
OUT_FILE := $(Q)_out.txt

.PHONY: all new test-build test build run clean clean-all help

# ==============================================================================
# Main Targets
# ==============================================================================

# Default target: test
all: test

# Create a new source file and a input file from a template.
new:
	@if [ -f "$(SRC)" ]; then \
		echo "Error: Source file '$(SRC)' already exists." >&2; \
		exit 1; \
	fi
	@if [ -f "$(IN_FILE)" ]; then \
		echo "Error: Input file '$(IN_FILE)' already exists." >&2; \
		exit 1; \
	fi
	@if [ ! -f "$(TEMPLATE_FILE)" ]; then \
		echo "Error: Template file '$(TEMPLATE_FILE)' not found." >&2; \
		exit 1; \
	fi
	@echo "Creating new source file '$(SRC)' from template..."
	@cp '$(TEMPLATE_FILE)' '$(SRC)'
	@touch '$(IN_FILE)'
	@echo "File '$(SRC)' created successfully."


# Compile in DEBUG mode, run with input from $(IN_FILE),output to $(OUT_FILE)
# This is the primary target for local testing.
test: $(TARGET_DEBUG) $(IN_FILE)
	@echo "===== Running '$(TARGET)' with '$(IN_FILE)' ====="
	./'$(TARGET_DEBUG)' < '$(IN_FILE)' 1> '$(OUT_FILE)'
	@echo "===== Done ====="

# Build the release version of the executable.
build: $(TARGET)

# Compile for release and run.
run: build
	@echo "===== Running RELEASE build of '$(TARGET)' ====="
	./'$(TARGET)'

# Compile in DEBUG mode
$(TARGET_DEBUG): $(SRC)
	@echo "===== Compiling '$(SRC)' in DEBUG mode (with sanitizers) ====="
	$(COMPILER) $< $(COMPILE_FLAGS) $(DEBUG_FLAGS) -o '$(TARGET_DEBUG)'
	@echo "===== Build complete ====="

# Compile in RELEASE mode
$(TARGET): $(SRC)
	@echo "===== Compiling '$(SRC)' for RELEASE ====="
	$(COMPILER) $< $(COMPILE_FLAGS) $(RELEASE_FLAGS) -o '$(TARGET)'
	@echo "===== Build complete ====="

$(IN_FILE):
	@touch '$(IN_FILE)'

# ==============================================================================
# Cleanup Targets
# ==============================================================================

# Clean up all generated files.
clean:
	@echo "===== Cleaning up generated files for '$(Q)' ====="
	rm -f '$(TARGET)' '$(TARGET_DEBUG)' '$(OUT_FILE)'

clean-all:
	@echo "===== Deleting ALL files for '$(Q)' (source, input, output, binary) ====="
	rm -f *.out *.o *_in.txt *_out.txt

# ==============================================================================
# Help
# ==============================================================================

help:
	@echo "Unified Makefile for Competitive Programming"
	@echo ""
	@echo "Usage: make [TARGET] [Q=QUESTION_NAME]"
	@echo ""
	@echo "Core Targets:"
	@echo "  new          - Create a new source file from template. Arg: Q."
	@echo "  test         - Compile in DEBUG mode and run with problem1_in.txt (Most common)."
	@echo "  build        - Compile for submission (Optimized, no debug info)."
	@echo "  run          - Compile for submission and run."
	@echo "  clean        - Remove generated files for the specified question."
	@echo "  clean-all    - Remove all generated files."
	@echo "  help         - Show this help message."
	@echo ""
	@echo "Variables:"
	@echo "  Q=<name>     - Specify the question name (default: 'main')."
	@echo "               Ex: make test Q=problem1"
	@echo "  USE_LANG=cpp/rust - Specify the language (default: 'cpp')."
	@echo ""
	@echo "Example Workflow:"
	@echo "  1. make new Q=problem1   # Creates problem1.cc"
	@echo "  2. (edit problem1.cc and create problem1_in.txt)"
	@echo "  3. make test Q=problem1 # Compile, run, and debug"


