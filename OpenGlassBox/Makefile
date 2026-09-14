P=..
M=$(P)/.makefile

PROJECT_NAME := LinkMyLibraries
PROJECT_VERSION := 1.0.0
TARGET_NAME := OpenGlassBox
TARGET_DESCRIPTION := Link OpenGlassBox Library
COMPILATION_MODE := release

include $(M)/project/Makefile

# The public headers use std::optional.
CXX_STANDARD := --std=c++17

SRC_FILES += src/main.cpp
PKG_LIBS += --static OpenGlassBox
VPATH += src
INCLUDES += src

DEFINES += -Wno-unused-variable
DEFINES += -DVIRTUAL=

include $(M)/rules/Makefile
