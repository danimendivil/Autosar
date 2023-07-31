CC=arm-none-eabi-gcc
MACH=cortex-m0
CFLAGS= -c -mcpu=$(MACH) -std=gnu11 -O0
LDFLAGS= -nostdlib -T stm32_ls.ld -Wl,-Map=final.map

all:main.o stm32_startup.o final.elf

main.o:main.c
	$(CC) -c $(CFLAGS) -o $@ $^    

stm32_startup.o:stm32_startup.c
	$(CC) -c $(CFLAGS) -o $@ $^ 

clean:
	rm -rf *.o* *.elf*

final.elf:main.o stm32_startup.o
	$(CC) $(LDFLAGS) -o $@ $^ 

flash:
	openocd -f board/st_nucleo_g0.cfg -c "program final.elf verify reset" -c shutdown

