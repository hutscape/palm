---
layout: default
title: Power
permalink: /power
sequence: 6
---

<section class="section is-small">
  <div class="container">
    <h2 class="title is-1">Power source</h2>
    <p class="subtitle"><code>380mAh</code> LiPo battery</p>
  </div>
</section>

<section class="section is-small">
  <div class="container">
    <h2 class="title is-1">Potential batteries</h2>

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

<section class="section is-small">
  <div class="container">
    <h2 class="title is-1">Main components</h2>

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
          <td>`1.7v` to `3.3v`</td>
          <td>`60 µA`</td>
          <td>`216 µA`</td>
        </tr>
        <tr>
          <td><a href="https://www.vishay.com/docs/84304/veml6075.pdf">VEML6075</a></td>
          <td>UV Sensor</td>
          <td>`1.7V` to `3.6V`</td>
          <td></td>
          <td>`480uA` at `1.8V`</td>
        </tr>
      </tbody>
    </table>
  </div>
</section>

<section class="section is-small">
  <div class="container">
    <h2 class="title is-1">Calculation</h2>

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
