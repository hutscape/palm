// Reference: https://github.com/adafruit/Adafruit_VEML6075/blob/master/examples/veml6075_fulltest/veml6075_fulltest.ino

#include <Wire.h>
#include "Adafruit_VEML6075.h"

Adafruit_VEML6075 uv = Adafruit_VEML6075();

void setup() {
  Serial.begin(115200);
  Serial.println("VEML6075 Full Test");

  if (! uv.begin()) {
    Serial.println("Failed to communicate with VEML6075 sensor, check wiring?");
  }
  Serial.println("Found VEML6075 sensor");
}


void loop() {
  Serial.print("Raw UVA reading:  ");
  Serial.println(uv.readUVA());

  Serial.print("Raw UVB reading:  ");
  Serial.println(uv.readUVB());

  Serial.print("UV Index reading: ");
  Serial.println(uv.readUVI());

  delay(1000);
}
