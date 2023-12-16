# Makefile for your project
MAKEFLAGS += --always-make

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
BUILD_DIR := build

# Executable names for different types and modes
EXECUTABLE_NAME := game
EXECUTABLE_VULKAN := $(BUILD_DIR)/vulkan/$(EXECUTABLE_NAME)_vk
EXECUTABLE_OPENGL := $(BUILD_DIR)/opengl/$(EXECUTABLE_NAME)_gl
EXECUTABLE_METAL := $(BUILD_DIR)/metal/$(EXECUTABLE_NAME)_m
EXECUTABLE_DEBUG_VULKAN := $(BUILD_DIR)/vulkan/debug/$(EXECUTABLE_NAME)_vk_debug
EXECUTABLE_DEBUG_OPENGL := $(BUILD_DIR)/opengl/debug/$(EXECUTABLE_NAME)_gl_debug
EXECUTABLE_DEBUG_METAL := $(BUILD_DIR)/metal/debug/$(EXECUTABLE_NAME)_m_debug

# Default target
.DEFAULT_GOAL := all

# Rules to build the executables for different types
vulkan: $(EXECUTABLE_VULKAN)
opengl: $(EXECUTABLE_OPENGL)
metal: $(EXECUTABLE_METAL)
debug: debug_vulkan debug_opengl debug_metal

debug_vulkan: $(EXECUTABLE_DEBUG_VULKAN)
debug_opengl: $(EXECUTABLE_DEBUG_OPENGL)
debug_metal: $(EXECUTABLE_DEBUG_METAL)

$(EXECUTABLE_VULKAN): $(SRC_FILES) main.c
	mkdir -p $(BUILD_DIR)/vulkan
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) -DUSE_VULKAN

$(EXECUTABLE_OPENGL): $(SRC_FILES) main.c
	mkdir -p $(BUILD_DIR)/opengl
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) -DUSE_OPENGL

$(EXECUTABLE_METAL): $(SRC_FILES) main.c
	mkdir -p $(BUILD_DIR)/metal
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) -DUSE_METAL

$(EXECUTABLE_DEBUG_VULKAN): $(SRC_FILES) main.c
	mkdir -p $(BUILD_DIR)/vulkan/debug
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) -DUSE_VULKAN -g -DDEBUG -DDEBUG_COLLIDER

$(EXECUTABLE_DEBUG_OPENGL): $(SRC_FILES) main.c
	mkdir -p $(BUILD_DIR)/opengl/debug
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) -DUSE_OPENGL -g -DDEBUG -DDEBUG_COLLIDER

$(EXECUTABLE_DEBUG_METAL): $(SRC_FILES) main.c
	mkdir -p $(BUILD_DIR)/metal/debug
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) -DUSE_METAL -g -DDEBUG -DDEBUG_COLLIDER

# Rules to build the default executable
all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC_FILES) main.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean vulkan opengl metal debug debug_vulkan debug_opengl debug_metal
