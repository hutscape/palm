# Palm

> Measure UV and barometric pressure outdoors with a keychain.

- **Wireless:**	BLE
- **Sensors:**	`VEML6075` for UV and `BME280` for atmospheric pressure
- **Power:**	CR2032 coin cell
- **Processor:**	NRF52
- **Firmware:**	Arduino NRF52
- **OTA?**	No
- **Works without connectivity?**	*Not yet*
- **BOM Total Items:**	*Not yet*
- **BOM Unique Items:** *Not yet*
- **Manufacturer Name:**	*Not yet*

## References 📚

## UV Sensor

1. [Arduino UV Index Meter - Working with Ultraviolet Light](https://www.youtube.com/watch?v=dBljvUBZqI8)
    - UV sensor on a wearable or garment is useful to alert the wearer for harmful sun exposure
1. [SENS-43UV analog UV sensor](https://abra-electronics.com/sensors/sensors-light-imaging-en/sens-43uv-analog-ultra-violet-light-sensor-module-for-5v-microcontrollers.html)
1. [Analog UV Light Sensor Breakout - GUVA-S12SD](https://www.adafruit.com/product/1918) from Adafruit
1. [SI1145 Digital UV Index / IR / Visible light sensor breakout board](https://www.adafruit.com/product/1777) from Adafruit with `I2C` bus connection
1. [VEML6070 breakout board](https://www.adafruit.com/product/2899) with `I2C`

## Barometric pressure sensor

1. [Adafruit BME280](https://www.adafruit.com/product/2652) breakout board frmo Adafruit with `I2C` or `SPI`
1. [What's the difference between the BMP280 and the BME280 atmospheric sensors](https://www.youtube.com/watch?v=0aL1PxK3rkE)
    - BME has both temeprature and humidity sensor

## Processor

1. [Adafruit Feather 32u4 Bluefruit LE](https://learn.adafruit.com/adafruit-feather-32u4-bluefruit-le/overview) with USB or LiPo JST connector

## Coin Cell

1. [20mm Coin Cell Breakout w/On-Off Switch (CR2032)](https://www.adafruit.com/product/1871)

## Firmware

1. [nRF52 Arduino](https://github.com/sandeepmistry/arduino-nRF5)
1. [SI1145 Arduino library](https://github.com/adafruit/Adafruit_SI1145_Library/blob/master/examples/si1145test/si1145test.ino) by Adafruit
1. [VEML6070 Arduino firmware library](https://github.com/adafruit/Adafruit_VEML6070)
