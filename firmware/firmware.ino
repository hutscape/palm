#include <bluefruit.h>
#include "Adafruit_VEML6075.h"

int redPin = PIN_A1;
int greenPin = PIN_A2;
int bluePin = PIN_A3;

const int ENSensorPin = 15;
Adafruit_VEML6075 uv = Adafruit_VEML6075();
uint8_t  uvindexvalue = 0x42;
float  readUVIndexValue = 0.0;

const int ENBLEPin = 16;
bool isBLEON = false;

/* GATT Services https://www.bluetooth.com/specifications/gatt/services/
    Name: Environmental Sensing
    Uniform Type Identifier: org.bluetooth.service.environmental_sensing
    Assigned Number: 0x181A
    Specification: GSS
*/
#define UUID16_SVC_ENVIRONMENTAL_SENSING 0x181A

/* GATT Characteristics https://www.bluetooth.com/specifications/gatt/characteristics/
    Name: UV Index
    Uniform Type Identifier: org.bluetooth.characteristic.uv_index
    Assigned Number: 0x2A76
    Specification: GSS
*/
#define UUID16_CHR_UV_INDEX 0x2A76

BLEService        ess = BLEService(UUID16_SVC_ENVIRONMENTAL_SENSING);
BLECharacteristic uvic = BLECharacteristic(UUID16_CHR_UV_INDEX);

BLEDis bledis;    // DIS (Device Information Service) helper class instance

// Advanced function prototypes
void startAdv(void);
void setupESService(void);
void connect_callback(uint16_t conn_handle);
void disconnect_callback(uint16_t conn_handle, uint8_t reason);

// Battery
#define VBAT_PIN          (A7)
#define VBAT_MV_PER_LSB   (0.73242188F)
#define VBAT_DIVIDER      (0.71275837F)
#define VBAT_DIVIDER_COMP (1.403F)
int vbat_raw;
uint8_t vbat_per;
float vbat_mv;

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);
  pinMode(ENSensorPin, OUTPUT);
  digitalWrite(ENSensorPin, LOW);
  pinMode(ENBLEPin, INPUT);
  pinMode(LED_RED, OUTPUT);
  Bluefruit.autoConnLed(false);  // Turn off BLUE LED

  // Battery
  analogReference(AR_INTERNAL_3_0);
  analogReadResolution(12);  // Can be 8, 10, 12 or 14

  Serial.println("Palm@Hutscape - UV Index sensor");
  Serial.println("-------------------------------------\n");

  int returnValue = uv.begin();
  if (!returnValue) {
    Serial.println("[ERROR] Sensor VEML6075 cannot be found");
  }
  Serial.println("[INFO] Sensor VEML6075 enabled");

  // TODO: Turn on/off BLE based on the ENBLEPin
  Bluefruit.begin();
  Bluefruit.setName("Palm@Hutscape");

  Bluefruit.Periph.setConnectCallback(connect_callback);
  Bluefruit.Periph.setDisconnectCallback(disconnect_callback);

  bledis.setManufacturer("Adafruit Industries");
  bledis.setModel("Bluefruit Feather52");
  bledis.begin();;
  setupESService();
  startAdv();

  Serial.println("[INFO] Start advertising...");
}

void loop() {
  // Battery
  vbat_raw = analogRead(VBAT_PIN);
  vbat_per = mvToPercent(vbat_raw * VBAT_MV_PER_LSB);
  vbat_mv = (float)vbat_raw * VBAT_MV_PER_LSB * VBAT_DIVIDER_COMP;
  Serial.print("[INFO] ADC = ");
  Serial.print(vbat_raw * VBAT_MV_PER_LSB);
  Serial.print(" mV (");
  Serial.print(vbat_raw);
  Serial.print(") ");
  Serial.print("LIPO = ");
  Serial.print(vbat_mv);
  Serial.print(" mV (");
  Serial.print(vbat_per);
  Serial.println("%)");

  // UV Index
  readUVIndexValue = uv.readUVI();
  uvindexvalue = round(abs(readUVIndexValue));
  Serial.print("[INFO] UV Index: ");
  Serial.println(uvindexvalue);
  displayLED(uvindexvalue);

  Serial.print("[INFO] BLE Switch: ");
  Serial.println(digitalRead(ENBLEPin));

  // Turn on BLE
  if (digitalRead(ENBLEPin) == 1) {
    isBLEON = true;
    digitalToggle(LED_RED);  // Blinking RED LED indicated BLE is ON
  } else {
    isBLEON = false;
    digitalWrite(LED_RED, LOW);
  }

  if (isBLEON && Bluefruit.connected()) {
    // Note: We use .indicate instead of .write!
    // If it is connected but CCCD is not enabled
    // The characteristic's value is still updated although indicate is not sent
    if (uvic.indicate(&uvindexvalue, sizeof(uvindexvalue))) {
      Serial.print("[INFO] Updated UV Index: ");
      Serial.println(uvindexvalue);
    } else {
      Serial.println("[ERROR] Indicate not set in the CCCD or not connected");
    }
  }

  delay(4000);
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

void startAdv(void) {
  // Advertising packet
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();

  // Include HTM Service UUID
  Bluefruit.Advertising.addService(ess);

  // Include Name
  Bluefruit.Advertising.addName();

  /* Start Advertising
   * - Enable auto advertising if disconnected
   * - Interval:  fast mode = 20 ms, slow mode = 152.5 ms
   * - Timeout for fast mode is 30 seconds
   * - Start(timeout) with timeout = 0 will advertise forever (until connected)
   *
   * For recommended advertising interval
   * https://developer.apple.com/library/content/qa/qa1931/_index.html
   */
  Bluefruit.Advertising.restartOnDisconnect(true);

  // in unit of 0.625 ms
  Bluefruit.Advertising.setInterval(32, 244);

  // number of seconds in fast mode
  Bluefruit.Advertising.setFastTimeout(30);

  // 0 = Don't stop advertising after n seconds
  Bluefruit.Advertising.start(0);
}

void setupESService(void) {
  // Configure the Environmental Sensing service
  // See: https://www.bluetooth.com/wp-content/uploads/Sitecore-Media-Library/Gatt/Xml/Characteristics/org.bluetooth.characteristic.uv_index.xml
  // Supported Characteristics:
  // Name                         UUID    Requirement Properties
  // ---------------------------- ------  ----------- ----------
  // UV Index                     0x2A76  Mandatory   Read
  ess.begin();

  // Note: You must call .begin() on the BLEService before calling .begin() on
  // any characteristic(s) within that service definition.. Calling .begin() on
  // a BLECharacteristic will cause it to be added to the last BLEService that
  // was 'begin()'ed!

  // Configure the UV Index characteristic
  // See:https://www.bluetooth.com/wp-content/uploads/Sitecore-Media-Library/Gatt/Xml/Characteristics/org.bluetooth.characteristic.uv_index.xml
  // Properties = Indicate
  // Min Len    = 1
  // Max Len    = 1
  // B0         = UINT8 - UV Index measurement unitless
  uvic.setProperties(CHR_PROPS_INDICATE);
  uvic.setPermission(SECMODE_OPEN, SECMODE_NO_ACCESS);
  uvic.setFixedLen(1);
  uvic.setCccdWriteCallback(cccd_callback);  // Optionally capture CCCD updates
  uvic.begin();
  uvic.write(&uvindexvalue, sizeof(uvindexvalue));
}

void connect_callback(uint16_t conn_handle) {
  // Get the reference to current connection
  BLEConnection* connection = Bluefruit.Connection(conn_handle);

  char central_name[32] = { 0 };
  connection->getPeerName(central_name, sizeof(central_name));

  Serial.print("[INFO] Connected to ");
  Serial.println(central_name);
}

/**
 * Callback invoked when a connection is dropped
 * @param conn_handle connection where this event happens
 * @param reason is a BLE_HCI_STATUS_CODE which can be found in ble_hci.h
 */
void disconnect_callback(uint16_t conn_handle, uint8_t reason) {
  (void) conn_handle;
  (void) reason;

  Serial.println("[INFO] Disconnected");
  Serial.println("[INFO] Advertising!");
}

void cccd_callback(uint16_t conn_hdl,
  BLECharacteristic* chr, uint16_t cccd_value) {
    // Display the raw request packet
    Serial.print("[INFO] CCCD Updated: ");

    // Serial.printBuffer(request->data, request->len);
    Serial.print(cccd_value);
    Serial.println("");

    // Check the characteristic this CCCD update is associated with in case
    // this handler is used for multiple CCCD records.
    if (chr->uuid == uvic.uuid) {
        if (chr->indicateEnabled(conn_hdl)) {
            Serial.println("[INFO] UV Index Measurement 'Indicate' enabled");
        } else {
            Serial.println("[INFO] UV Index Measurement 'Indicate' disabled");
        }
    }
}

uint8_t mvToPercent(float mvolts) {
  uint8_t battery_level;

  if (mvolts >= 3000) {
    battery_level = 100;
  } else if (mvolts > 2900) {
    battery_level = 100 - ((3000 - mvolts) * 58) / 100;
  } else if (mvolts > 2740) {
    battery_level = 42 - ((2900 - mvolts) * 24) / 160;
  } else if (mvolts > 2440) {
    battery_level = 18 - ((2740 - mvolts) * 12) / 300;
  } else if (mvolts > 2100) {
    battery_level = 6 - ((2440 - mvolts) * 6) / 340;
  } else {
    battery_level = 0;
  }

  return battery_level;
}
