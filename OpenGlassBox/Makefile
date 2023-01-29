PROJECT = LinkMyLibraries
TARGET = OpenGlassBox
DESCRIPTION = Link OpenGlassBox Library
BUILD_TYPE = release

P=..
M=$(P)/.makefile
include $(M)/Makefile.header

OBJS += main.o
PKG_LIBS += openglassbox
VPATH += src
INCLUDES += -Isrc

DEFINES += -Wno-unused-variable
DEFINES += -DVIRTUAL=

all: $(TARGET)

include $(M)/Makefile.footer
