# Links against the library zipper, installed on the system and found by
# pkg-config. The build goes to ../build/<configuration>/bin.

PROJECT_NAME := LinkMyLibraries
PROJECT_VERSION := 1.0.0
COMPILATION_MODE ?= release
CXX_STANDARD := c++20
BUILD_DIR := ../build

TARGETS := Zipper
Zipper.DESCRIPTION := Link Zipper Library
Zipper.SOURCES := src/main.cpp
Zipper.INCLUDES := src
Zipper.PKG_CONFIG := zipper

M ?= ../.makefile
include $(M)/MyMakefile.mk
