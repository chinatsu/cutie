TARGET = cutie

CPP_SOURCES = cutie.cpp

LIBDAISY_DIR = ../libDaisy
FLAC_DIR = ../flac

SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core

LIBS ?=
LIBDIR ?=

# LIBS += -lFLAC
# LIBDIR += -L $(FLAC_DIR)/build # ??? i don't know


C_INCLUDES ?=
C_INCLUDES += \
-I $(FLAC_DIR)/include \
-I $(FLAC_DIR)/include/FLAC \
-I $(FLAC_DIR)/include/FLAC++ # no idea which ones i actually need. i suspect FLAC++ is enough for my use case but we'll see


include $(SYSTEM_FILES_DIR)/Makefile