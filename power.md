---
layout: power
title: Power
permalink: /power
sequence: 6

# Power
power:
  tree: true
  components: true
  calculation: true
  source: <code>380mAh</code> LiPo battery
  battery_life: 5 days
  charging_duration: 5 hours
  charging_instruction: Plug in the USB cable to charge. <code>Yellow</code> LED will be on while it is charging.
---

# Power consumption of main components

| Chip # | Chip | Operating Voltage | Advertising mode (`152.5ms`) | Transmission mode |
|--------|------|------------------|-----------------------------|-------------------|
| [nRF52832](https://www.adafruit.com/product/3406) | BLE + MCU | `1.7v` to `3.3v` | `60 µA` | `216 µA` |
| [VEML6075](https://www.vishay.com/docs/84304/veml6075.pdf) | UV Sensor | `1.7V` to `3.6V` | | `480uA` at `1.8V` |

# Power calculation

## Advertising Mode

From [online power profiler](https://devzone.nordicsemi.com/nordic/power)

- Chip `nRF52832`
- Voltage `3.3V`
- Radio TX Power `0dBm`
- Role: Advertising (Connectable)
- TX payload (Byte) `0 byte`
- Advertising interval (ms): `152.5 ms` as recommended in [Apple developer guide](https://developer.apple.com/library/archive/qa/qa1931/_index.html)
- `120mAh` battery capacity

![Online profiler]({{site.url}}/images/online-profiler-advertising.png)

## Transmission Mode
From [online power profiler](https://devzone.nordicsemi.com/nordic/power)

- Voltage `3.3V`
- Role: Connection (peripheral)
- `3 byte` TX payload
- Connection interval (ms): `1000 ms`

![Online profiler]({{site.url}}/images/online-profiler-peripheral.png)

## Summary

- If transmitting 100% of the time: `~781 days`
- If advertising 100% of the time: `~83 days`
- If CPU running 100% of the time: `~12.5 hours`

## Other potential batteries

| Name | Capacity | Voltage | Dimension | Buy from |
|------|----------|---------|-----------|----------|
| CR2450 | `120mAh` | `3.6V` | `4cm` x `2cm` x `2cm` | [AliExpress](https://www.aliexpress.com/item/Rainpro-2PCS-LOT-LIR2450-horizontal-welding-foot-battery-3-6V-rechargeable-coin-cell-battery-charging-2450/32853897751.html?spm=2114.search0104.3.8.189ed9beMuzTzf&ws_ab_test=searchweb0_0,searchweb201602_6_10065_10068_319_10059_10884_317_10887_10696_321_322_10084_453_10083_454_10103_10618_10307_537_536,searchweb201603_52,ppcSwitch_0&algo_expid=48ce131f-0f3b-433f-9bb9-f5874e08c121-1&algo_pvid=48ce131f-0f3b-433f-9bb9-f5874e08c121&transAbTest=ae803_4) |
| LiPo | `380mAh` | `3.7V` | `37mm` x `19mm` x `8mm` | [AliExpress](https://www.aliexpress.com/item/Limskey-3-7V-380mAh-25C-Lipo-Battery-for-For-Hubsan-X4-H107-H107L-H107D-JD385-JD388/32846516934.html?spm=2114.search0103.3.69.12983204ovX5ra&ws_ab_test=searchweb0_0,searchweb201602_6_10065_10068_319_10059_10884_317_10887_10696_321_322_10084_453_10083_454_10103_10618_10307_537_536,searchweb201603_52,ppcSwitch_0&algo_expid=067ab389-d2ff-4f23-98e8-7aef2b13aeef-9&algo_pvid=067ab389-d2ff-4f23-98e8-7aef2b13aeef&transAbTest=ae803_4) |
