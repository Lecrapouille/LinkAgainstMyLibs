P=..
M=$(P)/.makefile

PROJECT_NAME := LinkMyLibraries
PROJECT_VERSION := 1.0.0
TARGET_NAME := Zipper
TARGET_DESCRIPTION := Link Zipper Library
COMPILATION_MODE := release

include $(M)/project/Makefile

SRC_FILES += src/main.cpp
PKG_LIBS += zipper
VPATH += src
INCLUDES += src

include $(M)/rules/Makefile
