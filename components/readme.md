# Components

## Main Components

### Hardware

1. [nRF52 BLE MCU](https://cdn-learn.adafruit.com/assets/assets/000/052/793/original/microcontrollers_revgsch.png?1523067417) breakout board
    - [`AP2112`](https://cdn-shop.adafruit.com/product-files/2471/AP2112.pdf) - Low dropout linear regulator
    - [`MCP73831`](https://cdn.sparkfun.com/assets/learn_tutorials/6/9/5/MCP738312.pdf) - LiOn/LiPo charge management controller
    - [`CP2104`](https://www.silabs.com/documents/public/data-sheets/cp2104.pdf) - USB to UART bridge
    - `4u20329`
    - `4u20317`
1. [VEML6075 UV Sensor](https://cdn-learn.adafruit.com/assets/assets/000/062/587/original/adafruit_products_schem.png?1537993764) breakout board
    - [`MIC5225-3.3`](http://ww1.microchip.com/downloads/en/DeviceDoc/mic5225.pdf) - Low dropout regulator
    - [`VEML6075 1.7V-3.6V`](https://www.vishay.com/docs/84304/veml6075.pdf) - UVA and UVB light sensor
    - [`2N7002DW`](http://www.farnell.com/datasheets/1900920.pdf) - N-channel enhancement mode field effect transistor
1. [SHARP Memory display](https://github.com/adafruit/Adafruit-Sharp-Memory-Display) breakout board

### Firmware

## Component experiments

1. [UV sensor VEML6075](uv-sensor
  ) with nRF52 breakout board
1. Hello world blinky with Adafruit Bluefruit [NRF52 breakout board](nrf52)
1. [Hello world with nRF52 breakout board and SHARP display](sharp-display)
1. [Display UV sensor values](display-uv)
1. [Display UV sensor with LiPo](display-uv-lipo)
