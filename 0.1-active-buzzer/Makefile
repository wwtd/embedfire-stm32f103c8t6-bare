CROSS_COMPILE = arm-none-eabi-

INCLUDE_DIRS = ./board ./chip ./app
INCLUDE_FLAGS = $(addprefix -I, $(INCLUDE_DIRS))

CC = $(CROSS_COMPILE)gcc -mcpu=cortex-m3 -mthumb -g $(INCLUDE_FLAGS)
AS = $(CROSS_COMPILE)as
LD = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump -d

SRC_DIRS = app board chip startup
OBJ_DIR = debug
LINKER_SCRIPT = startup/link.lds

TARGET_ELF = $(OBJ_DIR)/output.elf
TARGET_BIN = $(OBJ_DIR)/output.bin
TARGET_LST = $(OBJ_DIR)/output.lst

C_SRCS = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
ASM_SRCS = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.s))
C_OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(C_SRCS))
ASM_OBJS = $(patsubst %.s,$(OBJ_DIR)/%.o,$(ASM_SRCS))
OBJS = $(C_OBJS) $(ASM_OBJS)

all:
	make clean
	bear -- make target

target: $(TARGET_ELF) $(TARGET_BIN) $(TARGET_LST)

$(TARGET_ELF): $(OBJS)
	$(LD) -T $(LINKER_SCRIPT) -o $@ $(OBJS)

$(TARGET_BIN): $(TARGET_ELF)
	$(OBJCOPY) -O binary $< $@

$(TARGET_LST): $(TARGET_ELF)
	$(OBJDUMP) -d $< > $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

$(OBJ_DIR)/%.o: %.s
	@mkdir -p $(dir $@)
	$(AS) $< -o $@

clean:
	rm ./compile_commands.json
	rm -rf $(OBJ_DIR)/*

.PHONY: clean

stlink: all
	st-flash erase
	st-flash write $(TARGET_BIN) 0x08000000
