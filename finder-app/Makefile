# Default to standard gcc if CROSS_COMPILE isn't explicitly set
CC ?= gcc

ifdef CROSS_COMPILE
    CC := $(CROSS_COMPILE)gcc
endif

CFLAGS ?= -Wall -Wextra -O2 -g
TARGET = writer

all: $(TARGET)

$(TARGET): writer.c
	$(CC) $(CFLAGS) writer.c -o $(TARGET)

clean:
	rm -f $(TARGET) *.o *.txt
