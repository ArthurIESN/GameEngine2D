# Makefile for your project

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -I/opt/homebrew/include/SDL2 -I/opt/homebrew/include/SDL2_image -I./include

# Linker flags
LDFLAGS = -L/opt/homebrew/lib -lSDL2 -lSDL2_image

# Source directory
SRC_DIR = src

# Source files (all .c files in the src directory and its subdirectories)
SRC_FILES = $(shell find $(SRC_DIR) -name '*.c')

# Output directory
BUILD_DIR = build
BUILD_DEBUG_DIR = build/debug

# Output executable name
EXECUTABLE = $(BUILD_DIR)/game
EXECUTABLE_DEBUG = $(BUILD_DEBUG_DIR)/debug_game

# Default target
.DEFAULT_GOAL := all

# Rules to build the executable in debug mode
debug: CFLAGS += -g -DDEBUG -DDEBUG_COLLIDER
debug: clean $(EXECUTABLE_DEBUG)

$(EXECUTABLE_DEBUG): $(SRC_FILES) main.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Rules to build the executable in release mode
all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC_FILES) main.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(EXECUTABLE) $(EXECUTABLE_DEBUG)

.PHONY: all clean debug
