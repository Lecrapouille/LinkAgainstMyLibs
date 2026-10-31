# Links against the library OpenGlassBox, installed on the system and found by
# pkg-config. The build goes to ../build/<configuration>/bin.

PROJECT_NAME := LinkMyLibraries
PROJECT_VERSION := 1.0.0
COMPILATION_MODE ?= release
CXX_STANDARD := c++17
PKG_CONFIG_STATIC := 1
BUILD_DIR := ../build

TARGETS := OpenGlassBox
OpenGlassBox.DESCRIPTION := Link OpenGlassBox Library
OpenGlassBox.SOURCES := src/main.cpp
OpenGlassBox.INCLUDES := src
OpenGlassBox.PKG_CONFIG := OpenGlassBox
OpenGlassBox.DEFINES := VIRTUAL=
OpenGlassBox.CXXFLAGS := -Wno-unused-variable

M ?= ../.makefile
include $(M)/MyMakefile.mk
