BOARD?=adafruit:nrf52:feather52832
PORT := $(shell ls /dev/tty.SLAB_USBtoUART)
BAUD_RATE = 115200

.PHONY: lint compile upload clean

default: lint compile upload clean

lint:
	cpplint --extensions=ino --filter=-legal/copyright,-readability/todo,-readability/casting,-whitespace/line_length *.ino

compile:
	arduino-cli compile --fqbn $(BOARD) ./

upload:
	adafruit-nrfutil dfu genpkg --dev-type 0x0052 --application ./.*.hex dfu-package.zip
	adafruit-nrfutil dfu serial --package dfu-package.zip -p $(PORT) -b $(BAUD_RATE)

clean:
	rm -f .*.elf
	rm -f .*.hex
	rm -f *.zip
