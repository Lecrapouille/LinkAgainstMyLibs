PROJECT = LinkMyLibraries
TARGET = ExtendedForth
DESCRIPTION = Link My Extended Forth library
STANDARD = --std=c++14
BUILD_TYPE = release

P=..
M=$(P)/.makefile
include $(M)/Makefile.header

OBJS += main.o
PKG_LIBS += simforth
VPATH += src
INCLUDES += -Isrc
DEFINES += -DPROJECT_DATA_PATH=\"$(PWD)/core:$(PROJECT_DATA_ROOT)/core\"

all: $(TARGET)

include $(M)/Makefile.footer
