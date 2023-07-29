CC=arm-none-eabi-gcc
MACH=cortex-m0
CFLAGS= -c -mcpu=$(MACH) -std=gnu11 -O0

main.o:main.c   
    $(CC) $(CFLAGS) -o $@ $^