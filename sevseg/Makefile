MCU		= atmega8
FCPU		= 8000000L
SRC		= main.c ssi.c
OUTFILE		= Test
L_FUSE		= 0xE4
H_FUSE		= 0x99
COMOILER	= avr-gcc
CFLAGS		= -mmcu=$(MCU) -DF_CPU=$(FCPU) -Os -std=gnu99 -Wall -Os -Werror
PROGRAMMER	= usbasp

all: clean
	@echo
	@echo --- Компиляция ---
	@$(COMOILER) $(CFLAGS) -mmcu=$(MCU) -c $(SRC)
	@$(COMOILER) $(CFLAGS) *.o -o $(OUTFILE).elf
	@avr-objcopy -O ihex $(OUTFILE).elf $(OUTFILE).hex
	@echo --- Готово ---
	@echo
	@avr-size -C --format=avr --mcu=$(MCU) $(OUTFILE).elf

clean:
	@rm -fv *.elf *.hex *.o

upload:
	@avrdude -v -p $(MCU) -c $(PROGRAMMER) -U flash:w:$(OUTFILE).hex:i

upload_fuse:
	@avrdude -v -p $(MCU) -c $(PROGRAMMER) -U lfuse:w:$(L_FUSE):m -U hfuse:w:$(H_FUSE):m

upload_all: upload upload_fuse

bu: all upload
