---
layout: default
title: Design
permalink: /design
sequence: 5
state_machine: true
user_stories:
  - user: user
    actions:
      - goal: power ON the device
        reason: it can measure the UV Index periodically
      - goal: power OFF the device
        reason: it can power down completely to save battery consumption
      - goal: switch ON the wireless BLE
        reason: it can transmit the data to another BLE device
      - goal: switch OFF the wireless BLE
        reason: it can stop transmitting the data to another BLE device
      - goal: view the changing colors of the on-board RGB LED
        reason: I know the current range of UV Index
      - goal: view the numerical values of the UV Index and battery level data on another BLE device
        reason: I know those values accurately
      - goal: hang the entire keychain through the M6 drill hole
        reason: I can be hands-free when outdoors
---
