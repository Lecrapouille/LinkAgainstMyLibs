P=..
M=$(P)/.makefile

PROJECT_NAME := LinkMyLibraries
PROJECT_VERSION := 1.0.0
TARGET_NAME := ExtendedForth
TARGET_DESCRIPTION := Link My Extended Forth library
COMPILATION_MODE := release
CXX_STANDARD := --std=c++14

include $(M)/project/Makefile

SRC_FILES += src/main.cpp
PKG_LIBS += simforth
VPATH += src
INCLUDES += src

include $(M)/rules/Makefile
