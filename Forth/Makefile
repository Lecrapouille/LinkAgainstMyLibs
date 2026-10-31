# Links against the library SimForth, installed on the system and found by
# pkg-config. The build goes to ../build/<configuration>/bin.

PROJECT_NAME := LinkMyLibraries
PROJECT_VERSION := 1.0.0
COMPILATION_MODE ?= release
CXX_STANDARD := c++14
BUILD_DIR := ../build

TARGETS := Forth
Forth.DESCRIPTION := Link My Forth library
Forth.SOURCES := src/main.cpp
Forth.INCLUDES := src
Forth.PKG_CONFIG := simforth

M ?= ../.makefile
include $(M)/MyMakefile.mk
