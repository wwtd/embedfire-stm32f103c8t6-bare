TOOLS = arm-none-eabi
AS = $(TOOLS)-as
CC = $(TOOLS)-gcc -mcpu=cortex-m3 -mthumb -g
LD = $(TOOLS)-ld.bfd
OBJCOPY = $(TOOLS)-objcopy
DUMP = $(TOOLS)-objdump
GDB = $(TOOLS)-gdb

OBJS = blink.o locore.o

all: blink.bin blink.dump

blink.dump:	blink.elf
	$(DUMP) -d blink.elf > blink.dump

blink.bin:	blink.elf
	$(OBJCOPY) blink.elf blink.bin -O binary

blink.elf: 	$(OBJS)
	$(LD) -T blink.lds -o blink.elf $(OBJS)

locore.o:	locore.s
	$(AS) locore.s -o locore.o

blink.o:	blink.c
	$(CC) -c blink.c

stlink: all
	st-flash erase
	st-flash write blink.bin 0x08000000

clean:
	rm -f *.o blink.elf blink.bin blink.dump
