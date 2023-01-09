PROJECT = LinkMyLibraries
TARGET = OpenGL
DESCRIPTION = Link My OpenGL Library
STANDARD = --std=c++14
BUILD_TYPE = release

P=..
M=$(P)/.makefile
include $(M)/Makefile.header

OBJS += BasicWindow.o main.o
PKG_LIBS += openglcppwrapper
VPATH += src
INCLUDES += -Isrc

all: $(TARGET)

include $(M)/Makefile.footer
