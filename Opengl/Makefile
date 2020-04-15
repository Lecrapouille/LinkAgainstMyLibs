PROJECT = LinkMyLibraries
TARGET = OpenGL
DESCRIPTION = Link My OpenGL library
BUILD_TYPE = debug

P=..
M=$(P)/.makefile
include $(M)/Makefile.header

OBJS += main.o
PKG_LIBS += openglcppwrapper
VPATH += src
INCLUDES += -Isrc

all: $(TARGET)

include $(M)/Makefile.footer
