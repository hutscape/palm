# Power

## Main components

| Chip # | Chip | Operating Voltage | Advertising mode (`152.5ms`) | Transmission mode |
| ------ | ------ | ------ | ------ | ------ |
| [nRF52832](https://www.adafruit.com/product/3406) | BLE + MCU | `1.7v` to `3.3v` | `60 µA` | `216 µA`
| [VEML6075](https://www.vishay.com/docs/84304/veml6075.pdf) | UV Sensor |  `1.7V` to `3.6V` |  | `480uA` at `1.8V`

## Calculated

### Advertising mode

from online simulator

- Voltage `3.3V`
- Advertising (Connectable)
- 0 bytes TX payload
- `120mAh` battery capacity
- `57 µA` current consumption
- `120m/57u = 2000 h = 83 days`

### Transmission mode

from online simulator

- Voltage `3.3V`
- Connection (peripheral)
- 3 byte TX payload
- Connection interval (ms) 1000
- `120mAh` battery capacity
- `6.4 µA` current consumption
- `120m/250u = 18,000 h = 781 days`

## CPU

How much current consumption `Idd` for running code in active mode?

## References

- [Measuring current for nRF52832](https://infocenter.nordicsemi.com/index.jsp?topic=%2Fug_nrf52832_dk%2FUG%2Fnrf52_DK%2Fhw_meas_current.html)
- [Online Power profiler](https://devzone.nordicsemi.com/nordic/power)
- [High pulse drain impact on CR2032 coin cell battery capacity](https://www.dmcinfo.com/Portals/0/Blog%20Files/High%20pulse%20drain%20impact%20on%20CR2032%20coin%20cell%20battery%20capacity.pdf)
- [CR2032 Coin Cell battery life estimation with NRF52 as beacon](https://devzone.nordicsemi.com/f/nordic-q-a/36982/cr2032-coin-cell-battery-life-estimation-with-nrf52-as-beacon)
- [Using the correct Bluetooth LE Advertising and Connection Parameters for a stable connection](https://developer.apple.com/library/archive/qa/qa1931/_index.html)
