# Links against the library MyLogger, installed on the system and found by
# pkg-config. The build goes to ../build/<configuration>/bin.

PROJECT_NAME := LinkMyLibraries
PROJECT_VERSION := 1.0.0
COMPILATION_MODE ?= release
BUILD_DIR := ../build

TARGETS := Logger
Logger.DESCRIPTION := Link My Logger Library
Logger.SOURCES := src/main.cpp
Logger.INCLUDES := src
Logger.PKG_CONFIG := mylogger

M ?= ../.makefile
include $(M)/MyMakefile.mk
