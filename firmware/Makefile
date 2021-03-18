BOARD?=adafruit:nrf52:feather52832
PORT := $(shell ls /dev/tty.SLAB_USBtoUART)
BAUD_RATE = 115200
BUILD=build

.PHONY: default lint all flash clean

default: lint all flash clean

lint:
	cpplint --extensions=ino --filter=-legal/copyright *.ino

all:
	arduino-cli compile --fqbn $(BOARD) --output-dir $(BUILD) ./

flash:
	adafruit-nrfutil dfu genpkg --dev-type 0x0052 --application $(BUILD)/*.hex dfu-package.zip
	adafruit-nrfutil dfu serial --package dfu-package.zip -p $(PORT) -b $(BAUD_RATE)

clean:
	rm -rf build
	rm dfu-package.zip
