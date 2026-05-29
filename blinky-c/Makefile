PORT = /dev/ttyACM0

all:
	avr-gcc -mmcu=atmega328p -Os -o main.elf main.c
	avr-objcopy -O ihex -R .eeprom main.elf main.hex

flash: all
	avrdude -p m328p -c arduino -P $(PORT) -b 115200 -U flash:w:main.hex:i

clean:
	rm -f *.elf *.hex
