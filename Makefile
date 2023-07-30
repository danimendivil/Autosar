CC=arm-none-eabi-gcc
MACH=cortex-m0
CFLAGS= -c -mcpu=$(MACH) -std=gnu11 -O0

all:main.o stm32_startup.o

main.o:main.c
	$(CC) -c $(CFLAGS) -o $@ $^    

stm32_startup.o:stm32_startup.c
	$(CC) -c $(CFLAGS) -o $@ $^ 

clean:
	rm -rf *.o* *.elf*

