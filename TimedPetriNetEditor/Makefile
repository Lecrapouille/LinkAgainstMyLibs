# Links against the library TimedPetriNet, installed on the system and found by
# pkg-config. The build goes to ../build/<configuration>/bin.

PROJECT_NAME := LinkMyLibraries
PROJECT_VERSION := 1.0.0
COMPILATION_MODE ?= release
CXX_STANDARD := c++17
BUILD_DIR := ../build

TARGETS := TimedPetriNetEditor
TimedPetriNetEditor.DESCRIPTION := Link TimedPetriNetEditor Library
TimedPetriNetEditor.SOURCES := src/main.cpp
TimedPetriNetEditor.INCLUDES := src
TimedPetriNetEditor.PKG_CONFIG := TimedPetriNet

M ?= ../.makefile
include $(M)/MyMakefile.mk
