---
layout: csq
title: CSQ
permalink: /csq
sequence: 7

# Lessons
lessons:
  - title: Lessons learnt
    subtitle: Good practices to continue for future projects
    list:
      - name: Mark polarity for power connectors to safe guard against reverse polarity. E.g. JST connector should have <code>+</code> and <code>-</code> labels on silkscreen
      - name: Buy good quality LiPo / battery and power connectors E.g. JST connectors
  - title: V2.0
    subtitle: For next iteration
    list:
      - name: Do not use modules as they are big and bulky. E.g. <a href="https://www.adafruit.com/product/4077">MDBT42Q</a>
      - name: Use DP3T to power on, wireless off and wireless on options instead of 2 switches
      - name: Use a smaller and brighter RGB LED
      - name: Use a single layer board with only SMD parts so that a housing can be catered for the battery at the back
      - name: Use a smaller rechargeable coin cell battery E.g. CR2450

# Schedule
design_start: '2019-04-02'
design_end: '2019-06-21'
manufacturing_start: '2019-06-21'
manufacturing_end: '2019-07-02'
integration_start: '2019-07-09'
integration_end: '2019-07-09'
deployment_start: '2019-07-09'
deployment_end: '2019-07-10'
---
