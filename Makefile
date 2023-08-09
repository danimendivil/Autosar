CC=arm-none-eabi-gcc
MACH=cortex-m0
CFLAGS= -c -mcpu=$(MACH) -std=gnu11 -O0
LDFLAGS= -nostdlib -T stm32_ls.ld -Wl,-Map=final.map

LNFLAGS  = --inline-suppr       # comments to suppress lint warnings
LNFLAGS += --quiet              # spit only useful information
LNFLAGS += --std=c99            # check against C11
LNFLAGS += --template=gcc       # display warning gcc style
LNFLAGS += --force              # evaluate all the #if sentences
LNFLAGS += --platform=unix32    # lint againt a unix32 platform, but we are using arm32
LNFLAGS += --cppcheck-build-dir=Build/checks

# Directorio de construcción
BUILD_DIR = Build

# Lista de archivos fuente (agrega aquí tus archivos fuente)
SOURCE_FILES = app/main.c app/stm32_startup.c

# Genera una lista de los archivos objeto basados en los nombres de los archivos fuente
OBJECTS = $(addprefix $(BUILD_DIR)/,$(SOURCE_FILES:.c=.o))

# Carpeta que contiene los archivos de cabecera
INCLUDE_DIR = Autosar

# Regla para compilar todos los archivos objeto
all: $(BUILD_DIR)/final.elf

# Regla para compilar un archivo objeto
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $< -o $@

# Regla para crear el archivo ejecutable
$(BUILD_DIR)/final.elf: $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

# Regla para limpiar los archivos objeto y el ejecutable
clean:
	rm -rf $(BUILD_DIR)

# Regla para cargar el archivo ejecutable en el microcontrolador
flash: $(BUILD_DIR)/final.elf
	openocd -f board/st_nucleo_g0.cfg -c "program $^ verify reset" -c shutdown

lint :
	mkdir -p Build/checks
	cppcheck --addon=misra.json --suppressions-list=.msupress $(LNFLAGS) app
