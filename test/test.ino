#include <bluefruit.h>
#include "Adafruit_VEML6075.h"

// RGB LED pin declarations
int redPin = PIN_A1;
int greenPin = PIN_A2;
int bluePin = PIN_A3;

// Enable VEML6075 sensor pin 15
const int ENSensorPin = 15;
Adafruit_VEML6075 uv = Adafruit_VEML6075();

// UV index GATT Characteristic format is in uint8
uint8_t  uvindexvalue = 0x42;

// VEML6075 UV sensor reading is in float
float  readUVIndexValue = 0.0;

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);
  pinMode(ENSensorPin, OUTPUT);
  digitalWrite(ENSensorPin, LOW);

  Serial.println("Starting Palm design verification test");
  Serial.println("-------------------------------------\n");

  Serial.println("Test 1: It expects display GREEN LED");
  displayLEDColor(0, 255, 0);
  delay(1000);

  Serial.println("Test 2: It expects display YELLOW LED");
  displayLEDColor(255, 255, 0);
  delay(1000);

  Serial.println("Test 3: It expects display ORANGE LED");
  displayLEDColor(255, 50, 0);
  delay(1000);

  Serial.println("Test 4: It expects display RED LED");
  displayLEDColor(255, 0, 0);
  delay(1000);

  Serial.println("Test 5: It expects display PURPLE LED");
  displayLEDColor(255, 0, 255);
  delay(1000);

  Serial.println("Test 6: It expects display no color on the LED");
  displayLEDColor(0, 0, 0);
  delay(1000);

  digitalWrite(ENSensorPin, HIGH);
  if (!uv.begin()) {
    Serial.println("Test 7: It expects the Sensor VEML6075 to be disabled");
  }
  delay(1000);

  digitalWrite(ENSensorPin, LOW);
  Serial.println("Test 8: It expects the Sensor VEML6075 to be enabled");
}

void loop() {
  digitalToggle(LED_RED);  // blinking RED LED indicates reading UV sensor

  readUVIndexValue = uv.readUVI();
  uvindexvalue = round(abs(readUVIndexValue));

  Serial.print("Test 9: It expects to read UV Index value: ");
  Serial.println(uvindexvalue);
  displayLED(uvindexvalue);

  delay(2000);
}

void displayLEDColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void displayLED(uint8_t uvindexvalue) {
  if (uvindexvalue <= 2) {
    // UV Index <= 2, display GREEN or no color alerts
    displayLEDColor(0, 255, 0);
  } else if (uvindexvalue >= 3 && uvindexvalue <= 5) {
    // UV Index is from 3 to 5, display YELLOW
    displayLEDColor(255, 255, 0);
  } else if (uvindexvalue >= 6 && uvindexvalue <= 7) {
    // UV Index is from 6 to 7, display ORANGE
    displayLEDColor(255, 50, 0);
  } else if (uvindexvalue >= 8 && uvindexvalue <= 10) {
    // UV Index is from 8 to 10, display RED
    displayLEDColor(255, 0, 0);
  } else {
    // UV Index is above 11, display PURPLE
    displayLEDColor(255, 0, 255);
  }
}
