PROJECT = LinkMyLibraries
TARGET = Logger
DESCRIPTION = Link My Logger Library
BUILD_TYPE = release

P=..
M=$(P)/.makefile
include $(M)/Makefile.header

OBJS += main.o
PKG_LIBS += mylogger
VPATH += src
INCLUDES += -Isrc

all: $(TARGET)

include $(M)/Makefile.footer
