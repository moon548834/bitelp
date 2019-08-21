#!Makefile

C_SOURCES = $(shell find . -name "*.c")
C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))
S_SOURCES = $(shell find . -name "*.s")
S_OBJECTS = $(patsubst %.s, %.o, $(S_SOURCES))

CC = gcc
LD = ld
ASM = nasm

C_FLAGS = -c -Wall -m32 -ggdb -gstabs+ -nostdinc -fno-builtin -fno-stack-protector -I include
LD_FLAGS = -T scripts/kernel.ld -m elf_i386 -nostdlib
ASM_FLAGS = -f elf -g -F stabs

all: $(S_OBJECTS) $(C_OBJECTS) link update_image

print:
	echo $(C_OBJECTS) 
%.o:%.c
	@echo compiling $<
	$(CC) $(C_FLAGS) $< -o $@
%.o:%.s
	@echo compiling $< 
	$(ASM) $(ASM_FLAGS) $<
link:
	$(LD) $(LD_FLAGS) $(S_OBJECTS) $(C_OBJECTS) -o bitelp

.PHONY:update_image
update_image:
	sudo mount floppy.img /mnt/boot/grub
	sudo cp bitelp /mnt/boot
	sudo cp bitelp /mnt/boot/grub
	sudo cp bitelp /mnt/boot/grub/boot
	sleep 1
	sudo umount /mnt/boot/grub

.PHONY:qemu
qemu:
	qemu-system-i386 -fda floppy.img -boot a


.PHONY:clean
clean:
	rm $(S_OBJECTS) $(C_OBJECTS) 

