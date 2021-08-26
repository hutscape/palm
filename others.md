---
layout: others
title: Others
permalink: /others
sequence: 9

# Lessons
lessons:
  - title: Lessons learnt
    subtitle: Good practices to continue for future projects
    list:
      - name: Mark polarity for power connectors to safe guard against reverse polarity. E.g. JST connector should have <code>+</code> and <code>-</code> labels on silkscreen
      - name: Buy good quality LiPo / battery and power connectors E.g. JST connectors
  - title: V2.0
    subtitle: For next iteration
    list:
      - name: Do not use modules as they are big and bulky. E.g. <a href="https://www.adafruit.com/product/4077">MDBT42Q</a>
      - name: Use DP3T to power on, wireless off and wireless on options instead of 2 switches
      - name: Use a smaller and brighter RGB LED
      - name: Use a single layer board with only SMD parts so that a housing can be catered for the battery at the back
      - name: Use a smaller rechargeable coin cell battery E.g. CR2450

# References
references:
  - topic:  Similar projects
    list:
      - name: QSun app and tracker
        url: https://qsun.co
      - name: UV-badge
        url: https://hackaday.io/project/4706-uv-badge
      - name: "#badgelife"
        url: https://twitter.com/search?q=%23badgelife&src=typed_query on Twitter for various PCB designs

  - topic: Processor
    list:
      - name: nRF52 Adafruit Bluefruit board schematic
        url: https://cdn-learn.adafruit.com/assets/assets/000/052/793/original/microcontrollers_revgsch.png?1523067417
      - name: Adafruit Feather 32u4 Bluefruit LE with USB or LiPo JST connector
        url: https://learn.adafruit.com/adafruit-feather-32u4-bluefruit-le/overview

  - topic: UV Sensor
    list:
      - name: VEML6075 Adafruit Breakout board footprint
        url: https://cdn-learn.adafruit.com/assets/assets/000/062/588/original/adafruit_products_fab.png?1537993768
      - name: VEML6075 Adafruit Breakout board schematic
        url: https://cdn-learn.adafruit.com/assets/assets/000/062/587/original/adafruit_products_schem.png?1537993764
      - name: VEML6075 datasheet from manufacturer Vishay
        url: https://www.vishay.com/docs/84304/veml6075.pdf
      - name: Arduino UV Index Meter - Working with Ultraviolet Light
        url: https://www.youtube.com/watch?v=dBljvUBZqI8
      - name: SENS-43UV analog UV sensor
        url: https://abra-electronics.com/sensors/sensors-light-imaging-en/sens-43uv-analog-ultra-violet-light-sensor-module-for-5v-microcontrollers.html
      - name: Analog UV Light Sensor Breakout from Adafruit
        url: https://www.adafruit.com/product/1918
      - name: SI1145 Digital UV Index / IR / Visible light sensor breakout board from Adafruit with <code>I2C</code> bus connection
        url: https://www.adafruit.com/product/1777
      - name: VEML6070 breakout board with <code>I2C</code>
        url: https://www.adafruit.com/product/2899

  - topic: Other parts used
    list:
      - name: RGB LED SMD datasheet
        url: https://docs-apac.rs-online.com/webdocs/1524/0900766b815247fa.pdf
      - name: Toggle Switch SPDT
        url: https://www.aliexpress.com/item/50Pcs-Mini-7-Pin-On-Off-1P2T-SPDT-MSK-12C02-SMD-Toggle-Slide-Switch-For-MP3/32856542440.html

  - topic: Measuring power consumption
    list:
      - name: Measuring current for nRF52832
        url: https://infocenter.nordicsemi.com/index.jsp?topic=%2Fug_nrf52832_dk%2FUG%2Fnrf52_DK%2Fhw_meas_current.html
      - name: Online Power profiler
        url: https://devzone.nordicsemi.com/nordic/power
      - name: High pulse drain impact on CR2032 coin cell battery capacity
        url: https://www.dmcinfo.com/Portals/0/Blog%20Files/High%20pulse%20drain%20impact%20on%20CR2032%20coin%20cell%20battery%20capacity.pdf
      - name: CR2032 Coin Cell battery life estimation with NRF52 as beacon
        url: https://devzone.nordicsemi.com/f/nordic-q-a/36982/cr2032-coin-cell-battery-life-estimation-with-nrf52-as-beacon
      - name: Using the correct Bluetooth LE Advertising and Connection Parameters for a stable connection
        url: https://developer.apple.com/library/archive/qa/qa1931/_index.html
      - name: nRF52832 Product Specification v1.1
        url: https://infocenter.nordicsemi.com/pdf/nRF52832_PS_v1.1.pdf

  - topic: Humidity, Temperature and Barometric pressure sensor
    list:
      - name: Adafruit BME280 breakout board from Adafruit with <code>I2C</code> or <code>SPI</code>
        url: https://www.adafruit.com/product/2652
      - name: What's the difference between the BMP280 and the BME280 atmospheric sensors
        url: https://www.youtube.com/watch?v=0aL1PxK3rkE

  - topic: Coin Cell
    list:
      - name: 20mm Coin Cell Breakout with On-Off Switch CR2032
        url: https://www.adafruit.com/product/1871

  - topic: Firmware
    list:
      - name: nRF52 Arduino
        url: https://github.com/sandeepmistry/arduino-nRF5
      - name: Si1145 Arduino library by Adafruit
        url: https://github.com/adafruit/Adafruit_SI1145_Library/blob/master/examples/si1145test/si1145test.ino
      - name: VEML6070 Arduino firmware library
        url: https://github.com/adafruit/Adafruit_VEML6070

  - topic:  BLE
    list:
      - name: Adafruit nRF52 Feather device pinout
        url: https://cdn-learn.adafruit.com/assets/assets/000/046/248/original/microcontrollers_Feather_NRF52_Pinout_v1.2-1.png?1504885794
      - name: Adafruit nRF52 Feather pinout
        url: https://cdn-learn.adafruit.com/assets/assets/000/043/921/original/microcontrollers_nRF52Pinout.png?1500272417
      - name: Adafruit nRF52 Feather schematic
        url: https://cdn-learn.adafruit.com/assets/assets/000/052/793/original/microcontrollers_revgsch.png?1523067417

# Schedule
design_start: '2019-04-02'
design_end: '2019-06-21'
manufacturing_start: '2019-06-21'
manufacturing_end: '2019-07-02'
integration_start: '2019-07-09'
integration_end: '2019-07-09'
deployment_start: '2019-07-09'
deployment_end: '2019-07-10'

---
