#include <bluefruit.h>
#include "Adafruit_VEML6075.h"

// RGB LED pin declarations
int redPin = PIN_A1;
int greenPin = PIN_A2;
int bluePin = PIN_A3;

// Enable VEML6075 sensor pin 15
uint8_t ENSensorPin = 15;
Adafruit_VEML6075 uv = Adafruit_VEML6075();

// UV index GATT Characteristic format is in uint8
uint8_t  uvindexvalue = 0x42;

// VEML6075 UV sensor reading is in float
float  readUVIndexValue = 0.0;

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);   // for nrf52840 with native usb

  Serial.println("Starting Palm design verification test");
  Serial.println("-------------------------------------\n");

  Serial.println("Test 1: It expects display GREEN LED");
  displayLEDColor(0, 255, 0);
  delay(2000);

  Serial.println("Test 2: It expects display YELLOW LED");
  displayLEDColor(255, 255, 0);
  delay(2000);

  Serial.println("Test 3: It expects display ORANGE LED");
  displayLEDColor(255, 50, 0);
  delay(2000);

  Serial.println("Test 4: It expects display RED LED");
  displayLEDColor(255, 0, 0);
  delay(2000);

  Serial.println("Test 5: It expects display PURPLE LED");
  displayLEDColor(255, 0, 255);
  delay(2000);

  Serial.println("Test 6: It expects display no color on the LED");
  displayLEDColor(0, 0, 0);
  delay(2000);

  digitalWrite(ENSensorPin, HIGH);
  if (!uv.begin()) {
    Serial.println("Test 7: Failed to communicate with VEML6075 sensor");
  } else {
    Serial.println("Test 7: It expects to communicate with VEML6075 sensor");
    Serial.print("Test 8: It expects to read UV Index value: ");

    readUVIndexValue = uv.readUVI();
    uvindexvalue = round(abs(readUVIndexValue));  // convert float to uint8_t
    Serial.println(uvindexvalue);
  }
}

void loop() { }

void displayLEDColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
