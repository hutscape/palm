---
layout: code
title: Palm Demo
description: Display the UV Index color code with the on-board RGB LED
difficulty: medium
features:
  - UV
  - BLE
images:
  console: demo-console.png
steps:
  - step: Ensure the PCB can be detected with <code>ls -al /dev/cu.usbmodem</code> and <code>arduino-cli board list</code>.
  - step: Run <code>make a</code> to upload the code
---
