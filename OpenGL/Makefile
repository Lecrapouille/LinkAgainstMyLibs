P=..
M=$(P)/.makefile

PROJECT_NAME := LinkMyLibraries
PROJECT_VERSION := 1.0.0
TARGET_NAME := OpenGL
TARGET_DESCRIPTION := Link My OpenGL Library
COMPILATION_MODE := release
CXX_STANDARD := --std=c++14

include $(M)/project/Makefile

SRC_FILES += src/BasicWindow.cpp src/main.cpp
PKG_LIBS += openglcppwrapper
VPATH += src
INCLUDES += src

include $(M)/rules/Makefile
