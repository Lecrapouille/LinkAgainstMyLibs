PROJECT = LinkMyLibraries
TARGET = Forth
DESCRIPTION = Link My Forth library
BUILD_TYPE = release

P=..
M=$(P)/.makefile
include $(M)/Makefile.header

OBJS += main.o
PKG_LIBS += simforth
VPATH += src
INCLUDES += -Isrc

all: $(TARGET)

include $(M)/Makefile.footer
