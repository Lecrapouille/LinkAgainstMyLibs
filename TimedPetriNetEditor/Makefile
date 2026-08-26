P=..
M=$(P)/.makefile

PROJECT_NAME := LinkMyLibraries
PROJECT_VERSION := 1.0.0
TARGET_NAME := TimedPetriNetEditor
TARGET_DESCRIPTION := Link TimedPetriNetEditor Library
COMPILATION_MODE := release
CXX_STANDARD := --std=c++17

include $(M)/project/Makefile

SRC_FILES += src/main.cpp
PKG_LIBS += TimedPetriNet
VPATH += src
INCLUDES += src

include $(M)/rules/Makefile
