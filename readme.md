# Palm

> Measure UV index outdoors with a keychain 🗝 hanging on a backpack 🎒.

> Users can sync the logged data from the keychain through their mobile phone/browser or press a button to display the current sensor values.

- **Wireless:**	BLE
- **Sensors:**	1 (`VEML6075` for UV)
- **Power:**	`CR2032` [coin cell with on-off switch](https://www.adafruit.com/product/1871) or CR2016
- **Processor:**	`NRF52` on [Adafruit Bluefruit LE](https://www.adafruit.com/product/2661)
- **Modules:** 2 (MCU, sensor)
- **Firmware:**	[Arduino NRF52](https://github.com/sandeepmistry/arduino-nRF5)
- **OTA?**	No
- **Works without connectivity?**	Yes. Display an RGB LED on-board
- **BOM Total Items:**	*Pending*
- **BOM Unique Items:** *Pending*
- **PCB Manufacturing vendor:**	*Pending*
- **BOM vendors:** *Pending*
- **Total vendors:** *Pending*
- **Total units:** 1
- **Total cost:** *Pending*
- **Battery life:** *Pending*
- **Total schedule:** *Pending*

## Getting Started

1. Wire up the hardware components

    ![](firmware/schematic.png)
1. Flash the [firmware](firmware/firmware.ino) to display UV, temperature and humidity values

    ![](firmware/console.png)
1. See the UV, temperature and humidity values values being displayed every second

    ![](firmware/prototype.jpg)

## Others

- [Hardware](hardware)
- [Firmware](firmware)
- Bill of Materials - *Pending*
- Design - *Pending*
- [Power](power.md)
- [Mechanical](mechanical.md)
- [Schedule](schedule.md)
- Live log - *Pending*
- Lessons Learnt - *Pending*
- [References](references.md)
