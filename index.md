---
layout: start
title: Start
permalink: /
sequence: 1

manufacturing: true
downloads:
  schematic: true
  layout: true
  kicad: true
  gerber: true
  bom: true
  freecad: false
  case: false
software:
  - name: Demo firmware
    code: _code/demo

features:
  - detail: Read UV Index with the on-board sensor <code>VEML6075</code> and the battery level
  - detail: Display the UV Index color code with the on-board RGB LED
  - detail: Power on/off the entire device with the on-board power switch
  - detail: Start or stop BLE advertising with the on-board BLE switch
  - detail: Connect via the USB cable to flash the firmware or charge the LiPo
  - detail: Hang it like as keychain using the <code>M6</code> drill hole
  - detail: Display UV Index and Battery level as a GATT service and characteristic on a BLE client such as the iPhone or Web BLE on Chrome browser
---
## Maintenance

- **Flashing firmware:** Plug in the USB cable into the USB connector
- **Charging the LiPo:** Plug in the USB cable into the USB connector. Charging will have the yellow LED on.
