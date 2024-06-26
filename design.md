---
layout: design
title: Design
permalink: /design
sequence: 5
state_machine: true

# Mechanical
items:
  - name: Adafruit Bluefruit nRF52 Feather
    url: https://www.adafruit.com/product/3406
    height: 51
    width: 23
    depth: 8
    dimension_unit: mm
    weight: 5.7
    weight_unit: g

  - name: Adafruit UV Sensor VEML6075
    url: https://www.adafruit.com/product/3964
    height: 17.0
    width: 15.3
    depth: 2.9
    dimension_unit: mm
    weight: 0.8
    weight_unit: g

  - name: LiPo battery 380mAh at 3.7V
    url: https://www.aliexpress.com/item/Limskey-3-7V-380mAh-25C-Lipo-Battery-for-For-Hubsan-X4-H107-H107L-H107D-JD385-JD388/32846516934.html?spm=2114.search0103.3.69.12983204ovX5ra&ws_ab_test=searchweb0_0,searchweb201602_6_10065_10068_319_10059_10884_317_10887_10696_321_322_10084_453_10083_454_10103_10618_10307_537_536,searchweb201603_52,ppcSwitch_0&algo_expid=067ab389-d2ff-4f23-98e8-7aef2b13aeef-9&algo_pvid=067ab389-d2ff-4f23-98e8-7aef2b13aeef&transAbTest=ae803_4
    height: 37
    width: 19
    depth: 8
    dimension_unit: mm

# Design
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
