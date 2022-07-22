---
layout: start
title: Getting Started
permalink: /
sequence: 1

manufacturing: true
downloads:
  schematic: true
  layout: true
  kicad: true
  gerber: true
  bom: true
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

<section class="section is-small">
  <div class="container">
    <h2 class="title is-1">Getting Started</h2>
    <div class="tile is-ancestor">
      <div class="tile is-vertical is-12">
        <div class="tile">
          <div class="tile is-parent">
            <article class="tile is-child notification">
              <p class="title">Step 1</p>
              <p class="subtitle">Wire up the hardware components with <a href="">nRF52 Adafruit feather board</a>, <a href="https://www.adafruit.com/product/3964">VEML6075 sensor board</a> and LiPo battery. Turn on the switch for power and BLE.</p>
              <a href="images/hardware/schematic.png"><img src="images/hardware/schematic.png" alt="Schematic"></a>
              <a href="images/prototype/prototype-3.jpg"><img src="images/prototype/prototype-3.jpg" alt="Prototype"></a>
            </article>
          </div>
          <div class="tile is-parent">
            <article class="tile is-child notification">
              <p class="title">Step 2</p>
              <p class="subtitle">Flash the firmware onto the <code>nRF52</code> board to display UV Index and battery level.</p>
              <a href="images/code/demo-console.png"><img src="images/code/demo-console.png" alt="Serial console for firmware"></a>
            </article>
          </div>
          <div class="tile is-parent">
            <article class="tile is-child notification">
              <div class="content">
                <p class="title">Step 3</p>
                <p class="subtitle">See the UV and battery level values on the <a href="https://itunes.apple.com/sg/app/nrf-connect/id1054362403?mt=8">nRF Connect iPhone app</a></p>
                <img src="images/code/ios-detect.jpg" alt="iOS app detect">
                <br><br>
                <img src="images/code/ios-services.jpg" alt="iOS app GATT Services">
              </div>
            </article>
          </div>
        </div>
      </div>
    </div>
  </div>
</section>

<section class="section is-small">
  <div class="container">
    <h2 class="title is-1">Maintenance</h2>
    <div class="content is-medium">
      <ul>
        <li><strong>Flashing firmware:</strong> Plug in the USB cable into the USB connector</li>
        <li><strong>Charging the LiPo:</strong> Plug in the USB cable into the USB connector. Charging will have the yellow LED on.</li>
      </ul>
    </div>
  </div>
</section>
