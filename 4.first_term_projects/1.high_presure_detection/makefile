CC= arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2
INCS= -I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As= $(wildcard *.s)
AsOBJ= $(As:.s=.o)
project_name= high_pressure_detection
all: $(project_name).elf
	@echo "__________build is done__________"
	
%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

$(project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) $(LIBS) -o $@ -Map=mapfile.map
	
clean_all:
	rm *.o *.elf 
clean:
	rm *.elf 