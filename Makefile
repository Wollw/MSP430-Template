TARGET = main

SRC = $(wildcard *.c)

MSPDEBUG = mspdebug
MSPPROGRAMMER = rf2500

CC = msp430-gcc

# Compiler flag to set the C Standard level.
#     gnu89 = c89 plus GCC extensions
#     gnu99 = c99 plus GCC extensions
CSTANDARD = -std=gnu99

all: build
	
install: build
	$(MSPDEBUG) $(MSPPROGRAMMER) "erase"
	$(MSPDEBUG) $(MSPPROGRAMMER) "prog $(TARGET).elf"

build:
	$(CC) $(CSTANDARD) -oS -o $(TARGET).elf $(SRC)

debug:
	$(CC) $(CSTANDARD) -oS -g -o $(TARGET).elf $(SRC)

mspdebug:
	$(MSPDEBUG) $(MSPPROGRAMMER)


clean:
	rm $(TARGET).elf
