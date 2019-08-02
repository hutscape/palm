---
layout: default
title: Software
permalink: /software
sequence: 3
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
    <h2 class="title is-1">iOS Client</h2>

    <p class="subtitle is-4">Use the <a href="https://itunes.apple.com/sg/app/nrf-connect/id1054362403?mt=8">nRF Connect iPhone app</a> to view the exact UV Index levels.</p>

    <div class="columns is-desktop">
      <div class="column">
        <a href="{{site.url}}/images/software/ios-detect.jpg"><img src="{{site.url}}/images/software/ios-detect.jpg" alt="iOS detect BLE device"></a>
      </div>
      <div class="column">
        <a href="{{site.url}}/images/software/ios-services.jpg"><img src="{{site.url}}/images/software/ios-services.jpg" alt="iOS detect GATT services"></a>
      </div>
      <div class="column">
        <a href="{{site.url}}/images/software/ios-characteristics-batt.jpg"><img src="{{site.url}}/images/software/ios-characteristics-batt.jpg" alt="iOS GATT Characteristics Battery level"></a>
      </div>
      <div class="column">
        <a href="{{site.url}}/images/software/ios-characteristics-uv.jpg"><img src="{{site.url}}/images/software/ios-characteristics-uv.jpg" alt="iOS GATT Characteristics UV Index"></a>
      </div>
    </div>
  </div>
</section>

<section class="section is-small">
  <div class="container">
    <h2 class="title is-1">Web BLE</h2>
    <p class="subtitle is-4 is-spaced">Web BLE on Chrome browser is used to display the UV Index and Battery level on laptop.</p>

    <a class="button is-primary" href="{{ site.github.repository_url }}/tree/master/web-ble">Download code</a>
    <a class="button is-primary" href="/web-ble">View demo</a>
    <br>

    {% highlight html %}{%- include_relative web-ble/index.html -%}{% endhighlight %}
  </div>
</section>
