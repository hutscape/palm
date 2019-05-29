# Power

## Potential batteries

| Name | Capacity | Voltage | Dimension | Buy from |
| ------ | ------ | ------ | ------ | ------ |
| CR2450 | `120mAh` | 3.6V | 4cm x 2cm x 2cm | [AliExpress](https://www.aliexpress.com/item/Rainpro-2PCS-LOT-LIR2450-horizontal-welding-foot-battery-3-6V-rechargeable-coin-cell-battery-charging-2450/32853897751.html?spm=2114.search0104.3.8.189ed9beMuzTzf&ws_ab_test=searchweb0_0,searchweb201602_6_10065_10068_319_10059_10884_317_10887_10696_321_322_10084_453_10083_454_10103_10618_10307_537_536,searchweb201603_52,ppcSwitch_0&algo_expid=48ce131f-0f3b-433f-9bb9-f5874e08c121-1&algo_pvid=48ce131f-0f3b-433f-9bb9-f5874e08c121&transAbTest=ae803_4)
| LiPo | `380mAh` | 3.7V | 37mm x 19mm x 8mm | [AliExpress](https://www.aliexpress.com/item/Limskey-3-7V-380mAh-25C-Lipo-Battery-for-For-Hubsan-X4-H107-H107L-H107D-JD385-JD388/32846516934.html?spm=2114.search0103.3.69.12983204ovX5ra&ws_ab_test=searchweb0_0,searchweb201602_6_10065_10068_319_10059_10884_317_10887_10696_321_322_10084_453_10083_454_10103_10618_10307_537_536,searchweb201603_52,ppcSwitch_0&algo_expid=067ab389-d2ff-4f23-98e8-7aef2b13aeef-9&algo_pvid=067ab389-d2ff-4f23-98e8-7aef2b13aeef&transAbTest=ae803_4)

## Main components

| Chip # | Chip | Operating Voltage | Advertising mode (`152.5ms`) | Transmission mode |
| ------ | ------ | ------ | ------ | ------ |
| [nRF52832](https://www.adafruit.com/product/3406) | BLE + MCU | `1.7v` to `3.3v` | `60 µA` | `216 µA`
| [VEML6075](https://www.vishay.com/docs/84304/veml6075.pdf) | UV Sensor |  `1.7V` to `3.6V` |  | `480uA` at `1.8V`

## Calculated

### Advertising mode

from [online power profiler](https://devzone.nordicsemi.com/nordic/power):

- Chip `nRF52832`
- Voltage `3.3V`
- Radio TX Power `0dBm`
- Role: Advertising (Connectable)
- TX payload (Byte) 0 bytes
- Advertising interval (ms): `152.5 ms` as recommended in [Apple developer guide](https://developer.apple.com/library/archive/qa/qa1931/_index.html)
- `120mAh` battery capacity

![](images/online-profiler-advertising.png)

Result:

- `57 µA` current consumption
- `120m/57u = 2000 h = 83 days`

### Transmission mode

from [online power profiler](https://devzone.nordicsemi.com/nordic/power):

- Voltage `3.3V`
- Role: Connection (peripheral)
- `3 byte` TX payload
- Connection interval (ms): `1000 ms`

![](images/online-profiler-peripheral.png)

Result:

- `6.4 µA` current consumption
- `120m/250u = 18,000 h = 781 days`

### CPU

How much current consumption `Idd` for running code in active mode?

[page 76, 77](https://infocenter.nordicsemi.com/pdf/nRF52832_PS_v1.1.pdf):

| Description | Typical | Units | Max
| ------ | ------ | ------ | ------ |
| 0 dBm TX @ 1 Mb/s Bluetooth Low Energy mode, Clock = HFXO | 7.1 | mA |
| -40 dBm TX @ 1 Mb/s Bluetooth Low Energy mode, Clock = HFXO | 4.1 | mA |
| Radio RX @ 1 Mb/s Bluetooth Low Energy mode, Clock = HFXO | 6.5 | mA |
| CPU running CoreMark from Flash, Radio 0 dBm TX @ 1 Mb/s | 9.6 | mA | x |
| CPU running CoreMark from Flash, Radio RX @ 1 Mb/s | 9.0 | mA |
| System ON, No RAM retention, Wake on any event | 1.2 | µA |
| System ON, Full RAM retention, Wake on any event | 1.5 | µA |
| System ON, No RAM retention, Wake on RTC | 1.9 | µA |
| System OFF, No RAM retention, Wake on reset | 0.7 | µA |
| System OFF, No RAM retention, Wake on GPIO | 1.2 | µA |
| System OFF, No RAM retention, Wake on LPCOMP | 1.9 | µA |
| System OFF, No RAM retention, Wake on NFC field | 0.7 | µA |
| System OFF, Full RAM retention, Wake on reset | 1.0 | µA |

Result:

- `9.6 mA` current consumption
- `120m/9.6 = 12.5 h`

### Summary

- If transmitting 100% of the time: ~781 days
- If advertising 100% of the time: ~83 days
- if CPU running 100% of the time: ~12.5 hours

## References

- [Measuring current for nRF52832](https://infocenter.nordicsemi.com/index.jsp?topic=%2Fug_nrf52832_dk%2FUG%2Fnrf52_DK%2Fhw_meas_current.html)
- [Online Power profiler](https://devzone.nordicsemi.com/nordic/power)
- [High pulse drain impact on CR2032 coin cell battery capacity](https://www.dmcinfo.com/Portals/0/Blog%20Files/High%20pulse%20drain%20impact%20on%20CR2032%20coin%20cell%20battery%20capacity.pdf)
- [CR2032 Coin Cell battery life estimation with NRF52 as beacon](https://devzone.nordicsemi.com/f/nordic-q-a/36982/cr2032-coin-cell-battery-life-estimation-with-nrf52-as-beacon)
- [Using the correct Bluetooth LE Advertising and Connection Parameters for a stable connection](https://developer.apple.com/library/archive/qa/qa1931/_index.html)
- [nRF52832 Product Specification v1.1](https://infocenter.nordicsemi.com/pdf/nRF52832_PS_v1.1.pdf)
