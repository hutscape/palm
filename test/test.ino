#include <bluefruit.h>

// RGB LED pin declarations
int redPin = PIN_A1;
int greenPin = PIN_A2;
int bluePin = PIN_A3;

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);   // for nrf52840 with native usb

  Serial.println("Starting Palm design verification test");
  Serial.println("-------------------------------------\n");
}

void loop() {
  Serial.println("Test 1: It expects display no color on the LED");
  displayLEDColor(0, 0, 0);
  delay(2000);

  Serial.println("Test 2: It expects display GREEN LED");
  displayLEDColor(0, 255, 0);
  delay(2000);

  Serial.println("Test 3: It expects display YELLOW LED");
  displayLEDColor(255, 255, 0);
  delay(2000);

  Serial.println("Test 4: It expects display ORANGE LED");
  displayLEDColor(255, 50, 0);
  delay(2000);

  Serial.println("Test 5: It expects display RED LED");
  displayLEDColor(255, 0, 0);
  delay(2000);

  Serial.println("Test 6: It expects display PURPLE LED");
  displayLEDColor(255, 0, 255);
  delay(2000);
}

void displayLEDColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
