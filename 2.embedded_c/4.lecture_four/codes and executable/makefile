CC= arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -gdwarf-2
INCS= -I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As= $(wildcard *.s)
AsOBJ= $(As:.s=.o)
project_name= toogle_led_m4
all: $(project_name).bin
	@echo "__________build is done__________"
%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@
%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
$(project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker.ld $(OBJ) $(AsOBJ) $(LIBS) -o $@ -Map=mapfile.map
	cp $(project_name).elf $(project_name).axf
$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.elf *.bin
clean:
	rm *.elf *.bin