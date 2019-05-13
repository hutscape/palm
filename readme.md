# Palm

> Measure UV, temperature and humidity outdoors with a keychain 🗝 hanging on a backpack 🎒.

> Users can sync the logged data from the keychain through their mobile phone/browser or press a button to display the current sensor values.

- **Wireless:**	BLE
- **Sensors:**	2 (`VEML6075` for UV and `Si7021` for temperature and humidity)
- **Power:**	`CR2032` [coin cell with on-off switch](https://www.adafruit.com/product/1871) or CR2016
- **Processor:**	`NRF52` on [Adafruit Bluefruit LE](https://www.adafruit.com/product/2661)
- **Modules:** 3 (MCU, display, sensor)
- **Firmware:**	[Arduino NRF52](https://github.com/sandeepmistry/arduino-nRF5)
- **OTA?**	No
- **Works without connectivity?**	Display 3 sensor values using an [LCD screen](https://www.adafruit.com/product/3502)
- **BOM Total Items:**	*Pending*
- **BOM Unique Items:** *Pending*
- **PCB Manufacturing vendor:**	*Pending*
- **BOM vendor:** *Pending*
- **Total vendors:** *Pending*
- **Total units:** 1

## Getting Started

1. Wire up the hardware components

    ![](components/display-sensors/schematic.png)
1. Flash the [firmware](components/display-sensors/main.ino) to display UV, temperature and humidity values

    ![](components/display-sensors/console.png)
1. See the UV, temperature and humidity values values being displayed every second

    ![](components/display-sensors/prototype.jpg)
