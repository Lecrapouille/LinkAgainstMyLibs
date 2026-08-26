P=..
M=$(P)/.makefile

PROJECT_NAME := LinkMyLibraries
PROJECT_VERSION := 1.0.0
TARGET_NAME := Forth
TARGET_DESCRIPTION := Link My Forth library
COMPILATION_MODE := release

include $(M)/project/Makefile

SRC_FILES += src/main.cpp
PKG_LIBS += simforth
VPATH += src
INCLUDES += src

include $(M)/rules/Makefile
