CC = gcc
CFLAGS = -Wall -Wextra -g
INCLUDES = -Icontroller -Imodel -Iview -Iutils

OUTPUT = ../output
SUBDIRS = controller model view utils

UNAME_S := $(shell uname -s 2>/dev/null || echo UNKNOWN)
ifeq ($(findstring MINGW,$(UNAME_S)),MINGW)
    MKDIR_P = mkdir -p
else ifeq ($(findstring MSYS,$(UNAME_S)),MSYS)
    MKDIR_P = mkdir -p
else ifeq ($(UNAME_S),UNKNOWN)
    ifeq ($(OS),Windows_NT)
        HAS_POWERSHELL := $(shell where powershell.exe > /dev/null 2>&1 && echo yes || echo no)
        ifeq ($(HAS_POWERSHELL),yes)
            MKDIR_P = powershell -NoProfile -Command "New-Item -ItemType Directory -Force -Path"
        else
            MKDIR_P = mkdir
        endif
    else
        MKDIR_P = mkdir -p
    endif
else
    MKDIR_P = mkdir -p
endif

EXE_SUFFIX =
ifeq ($(OS),Windows_NT)
    EXE_SUFFIX = .exe
endif

TARGET = $(OUTPUT)/program$(EXE_SUFFIX)

SRC = $(wildcard *.c controller/*.c model/*.c view/*.c utils/*.c)
OBJ = $(patsubst %.c,$(OUTPUT)/%.o,$(SRC))

.PHONY: all clean start

all: $(TARGET)

$(OUTPUT):
	@$(MKDIR_P) $(OUTPUT) $(addprefix $(OUTPUT)/,$(SUBDIRS))

$(TARGET): $(OBJ) | $(OUTPUT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJ)

$(OUTPUT)/%.o: %.c | $(OUTPUT)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	-rm -rf $(OUTPUT)

start: all
	@echo "--- Iniciando o programa ---"
	$(TARGET)