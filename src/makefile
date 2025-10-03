CC = gcc
CFLAGS = -Wall -Wextra -g
INCLUDES = -Icontroller -Imodel -Iview -Iutils

OUTPUT = ../output
SUBDIRS = controller model view utils

TARGET = program

SRC = $(wildcard *.c controller/*.c model/*.c view/*.c utils/*.c)
OBJ = $(patsubst %.c,$(OUTPUT)/%.o,$(SRC))

all: $(TARGET)

$(OUTPUT):
	mkdir -p $(OUTPUT)
	for dir in $(SUBDIRS); do \
		mkdir -p $(OUTPUT)/$$dir; \
	done

$(TARGET): $(OBJ) | $(OUTPUT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJ)

$(OUTPUT)/%.o: %.c | $(OUTPUT)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OUTPUT)
	rm -f $(TARGET)
