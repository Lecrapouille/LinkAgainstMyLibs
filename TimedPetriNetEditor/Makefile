PROJECT = LinkMyLibraries
TARGET = TimedPetriNetEditor
DESCRIPTION = Link TimedPetriNetEditor Library
BUILD_TYPE = release

P=..
M=$(P)/.makefile
include $(M)/Makefile.header

OBJS += main.o
PKG_LIBS += timedpetrinetgui timedpetrinetcore
VPATH += src
INCLUDES += -Isrc

all: $(TARGET)

include $(M)/Makefile.footer
