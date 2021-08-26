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

# Power
power_tree: true
power_source: <code>380mAh</code> LiPo battery
battery_life: 5 days
charging_duration: 5 hours
charging_instruction: Plug in the USB cable to charge. <code>Yellow</code> LED will be on while it is charging.
---


<section class="section is-small">
  <div class="container">
    <h2 class="title is-1">Power consumption from main components</h2>
    <table class="table is-fullwidth">
      <thead>
        <tr>
          <th>Chip #</th>
          <th>Chip</th>
          <th>Operating Voltage</th>
          <th>Advertising mode (<code>152.5ms</code>)</th>
          <th>Transmission mode</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <td><a href="https://www.adafruit.com/product/3406">nRF52832</a></td>
          <td>BLE + MCU</td>
          <td><code>1.7v</code> to <code>3.3v</code></td>
          <td><code>60 µA</code></td>
          <td><code>216 µA</code></td>
        </tr>
        <tr>
          <td><a href="https://www.vishay.com/docs/84304/veml6075.pdf">VEML6075</a></td>
          <td>UV Sensor</td>
          <td><code>1.7V</code> to <code>3.6V</code></td>
          <td></td>
          <td><code>480uA</code> at <code>1.8V</code></td>
        </tr>
      </tbody>
    </table>
  </div>
</section>

<section class="section is-small">
  <div class="container">
    <h2 class="title is-1">Power calculation</h2>
    <h3 class="title is-3">Advertising Mode</h3>
    <p class="subtitle">From <a href="https://devzone.nordicsemi.com/nordic/power">online power profiler</a></p>
    <div class="content">
      <ul>
        <li>Chip <code>nRF52832</code></li>
        <li>Voltage <code>3.3V</code></li>
        <li>Radio TX Power <code>0dBm</code></li>
        <li>Role: Advertising (Connectable)</li>
        <li>TX payload (Byte)<code>0 byte</code></li>
        <li>Advertising interval (ms): <code>152.5 ms</code> as recommended in <a href="https://developer.apple.com/library/archive/qa/qa1931/_index.html">Apple developer guide</a></li>
        <li><code>120mAh</code> battery capacity</li>
      </ul>
      <img src="{{site.url}}/images/online-profiler-advertising.png" alt="Online profiler">
      <h3 class="title is-3">Transmission Mode</h3>
      <p class="subtitle">From <a href="https://devzone.nordicsemi.com/nordic/power">online power profiler</a></p>
      <div class="content">
        <ul>
          <li>Voltage <code>3.3V</code></li>
          <li>Role: Connection (peripheral)</li>
          <li><code>3 byte</code> TX payload</li>
          <li>Connection interval (ms): <code>1000 ms</code></li>
        </ul>
        <img src="{{site.url}}/images/online-profiler-peripheral.png" alt="Online profiler">
      </div>
      <h3 class="title is-3">Summary</h3>
      <div class="content">
        <ul>
          <li>If transmitting 100% of the time: ~781 days</li>
          <li>If advertising 100% of the time: ~83 days</li>
          <li>if CPU running 100% of the time: ~12.5 hours</li>
        </ul>
      </div>
    </div>
  </div>
</section>

<section class="section is-small">
  <div class="container">
    <h2 class="title is-1">Other potential batteries</h2>
    <table class="table is-fullwidth">
      <thead>
        <tr>
          <th>Name</th>
          <th>Capacity</th>
          <th>Voltage</th>
          <th>Dimension</th>
          <th>Buy from</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <td>CR2450</td>
          <td><code>120mAh</code></td>
          <td><code>3.6V</code></td>
          <td><code>4cm</code> x <code>2cm</code>x <code>2cm</code></td>
          <td><a href="https://www.aliexpress.com/item/Rainpro-2PCS-LOT-LIR2450-horizontal-welding-foot-battery-3-6V-rechargeable-coin-cell-battery-charging-2450/32853897751.html?spm=2114.search0104.3.8.189ed9beMuzTzf&ws_ab_test=searchweb0_0,searchweb201602_6_10065_10068_319_10059_10884_317_10887_10696_321_322_10084_453_10083_454_10103_10618_10307_537_536,searchweb201603_52,ppcSwitch_0&algo_expid=48ce131f-0f3b-433f-9bb9-f5874e08c121-1&algo_pvid=48ce131f-0f3b-433f-9bb9-f5874e08c121&transAbTest=ae803_4">AliExpress</a></td>
        </tr>
        <tr>
          <td>LiPo</td>
          <td><code>380mAh</code></td>
          <td><code>3.7V</code></td>
          <td><code>37mm</code> x <code>19mm</code> x <code>8mm</code></td>
          <td><a href="https://www.aliexpress.com/item/Limskey-3-7V-380mAh-25C-Lipo-Battery-for-For-Hubsan-X4-H107-H107L-H107D-JD385-JD388/32846516934.html?spm=2114.search0103.3.69.12983204ovX5ra&ws_ab_test=searchweb0_0,searchweb201602_6_10065_10068_319_10059_10884_317_10887_10696_321_322_10084_453_10083_454_10103_10618_10307_537_536,searchweb201603_52,ppcSwitch_0&algo_expid=067ab389-d2ff-4f23-98e8-7aef2b13aeef-9&algo_pvid=067ab389-d2ff-4f23-98e8-7aef2b13aeef&transAbTest=ae803_4">AliExpress</a></td>
        </tr>
      </tbody>
    </table>
  </div>
</section>
