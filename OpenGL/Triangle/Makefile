P := ..
M := $(P)/../.makefile

PROJECT_NAME := LinkMyLibraries
PROJECT_VERSION := 1.0.0
TARGET_NAME := Triangle
TARGET_DESCRIPTION := Compages triangle example
COMPILATION_MODE := release
CXX_STANDARD := --std=c++20

include $(M)/project/Makefile

SRC_FILES += main.cpp ../src/GpuContext.cpp
PKG_LIBS += Compages glfw3
# Fedora/RHEL: le runtime ne cherche pas /usr/local/lib sans ldconfig — rpath depuis .pc
USER_LDFLAGS += -Wl,-rpath,$(shell pkg-config --variable=libdir Compages)
INCLUDES += ../src

include $(M)/rules/Makefile
