# Links two examples against the library Compages, installed on the system
# and found by pkg-config. The build goes to ../build/<configuration>/bin.

PROJECT_NAME := LinkMyLibraries
PROJECT_VERSION := 1.0.0
COMPILATION_MODE ?= release
CXX_STANDARD := c++20
BUILD_DIR := ../build

TARGETS := Triangle HeadlessCompute

Triangle.DESCRIPTION := Compages triangle example
Triangle.SOURCES := Triangle/main.cpp src/GpuContext.cpp
Triangle.INCLUDES := src
Triangle.PKG_CONFIG := Compages glfw3

HeadlessCompute.DESCRIPTION := Compages headless compute example
HeadlessCompute.SOURCES := HeadlessCompute/main.cpp src/GpuContext.cpp
HeadlessCompute.INCLUDES := src
HeadlessCompute.PKG_CONFIG := Compages glfw3

M ?= ../.makefile
include $(M)/MyMakefile.mk
