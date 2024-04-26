PROJECT = LinkMyLibraries
TARGET = Zipper
DESCRIPTION = Link Zipper Library
BUILD_TYPE = release

P=..
M=$(P)/.makefile
include $(M)/Makefile.header

OBJS += main.o
PKG_LIBS += zipper
VPATH += src
INCLUDES += -Isrc

all: $(TARGET)

include $(M)/Makefile.footer
