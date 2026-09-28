P=..
M=$(P)/.makefile

PROJECT_NAME := LinkMyLibraries
PROJECT_VERSION := 1.0.0
TARGET_NAME := OpenGL
TARGET_DESCRIPTION := Compages link examples (triangle + headless compute)
COMPILATION_MODE := release

include $(M)/project/Makefile

ORCHESTRATOR_MODE := 1
DIRS_WITH_MAKEFILE := Triangle HeadlessCompute

include $(M)/rules/Makefile
