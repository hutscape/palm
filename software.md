---
layout: default
title: Software
permalink: /software
sequence: 3
---

<section class="section is-small">
  <div class="container">
    <h2 class="title is-1">Features</h2>

    <div class="content is-medium">
      <ul>
        <li>Read UV Index with the on-board sensor <code>VEML6075</code></li>
        <li>Display the UV Index color code with the on-board RGB LED</li>
        <li>Power on/off the entire device with the on-board power switch</li>
        <li>Start or stop BLE advertising with the on-board BLE switch</li>
        <li>Connect via the USB cable to flash the firmware or charge the LiPo</li>
        <li>Hang it like as keychain using the <code>M6</code> drill hole</li>
      </ul>
    </div>
  </div>
</section>

<section class="section is-small">
  <div class="container">
    <h2 class="title is-1">Firmware</h2>

    <p class="subtitle is-4"><a href="{{site.github.repository_url}}/tree/master/{{page.path | replace:'.md',''}}">Upload the code</a> with <code>make flash</code> command.</p>
    {% highlight c %}{%- include_relative firmware/firmware.ino -%}{% endhighlight %}

    <p class="subtitle is-4">Makefile</p>
    {% highlight make %}{%- include_relative firmware/Makefile -%}{% endhighlight %}

    <p class="subtitle is-4">Serial console</p>
    <img src="{{site.url}}/images/software/console.png" alt="Firmware serial console">
  </div>
</section>

<section class="section is-small">
  <div class="container">
    <h2 class="title is-1">Client</h2>

    <p class="subtitle is-4">Use the <a href="https://itunes.apple.com/sg/app/nrf-connect/id1054362403?mt=8">nRF Connect iPhone app</a> to view the exact UV Index levels.</p>

    <div class="columns is-desktop">
      <div class="column"><img src="{{site.url}}/images/software/ios-detect.jpg" alt="iOS detect"></div>
      <div class="column"><img src="{{site.url}}/images/software/ios-services.jpg" alt="iOS detect"></div>
      <div class="column"><img src="{{site.url}}/images/software/ios-characteristics.jpg" alt="iOS detect"></div>
    </div>
  </div>
</section>

<section class="section is-small">
  <div class="container">
    <h2 class="title is-1">Test</h2>

    <p class="subtitle is-4"><a href="{{site.github.repository_url}}/tree/master/test">Upload the code</a> with <code>make flash</code> command.</p>
    {% highlight c %}{%- include_relative test/test.ino -%}{% endhighlight %}

    <p class="subtitle is-4">Makefile</p>
    {% highlight make %}{%- include_relative test/Makefile -%}{% endhighlight %}

    <p class="subtitle is-4">Serial console</p>
    <img src="{{site.url}}/images/software/test-console.png" alt="Firmware serial console">
  </div>
</section>
