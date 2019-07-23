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

BLEService environmental_sensing_service = BLEService(UUID16_SVC_ENVIRONMENTAL_SENSING);
BLECharacteristic uv_index_characteristic = BLECharacteristic(UUID16_CHR_UV_INDEX);

BLEDis bledis;    // DIS (Device Information Service) helper class instance

// Advanced function prototypes
void startAdv(void);
void setupESService(void);
void setupBattService(void);
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

/* GATT Services https://www.bluetooth.com/specifications/gatt/services/
    Name: Battery Service
    Uniform Type Identifier: org.bluetooth.service.battery_service
    Assigned Number: 0x180F
    Specification: GSS
*/
#define UUID16_SVC_BATTERY 0x180F

/* GATT Characteristics https://www.bluetooth.com/specifications/gatt/characteristics/
    Name: Battery Level
    Abstract: The current charge level of a battery.
          100% represents fully charged while 0% represents fully discharged.
    Uniform Type Identifier: org.bluetooth.characteristic.battery_level
    Assigned Number: 0x2A19
    Format: uint8
    Specification: GSS
*/
#define UUID16_CHR_BATTERY_LEVEL 0x2A19

BLEService        battery_service = BLEService(UUID16_SVC_BATTERY);
BLECharacteristic battery_level_characteristic = BLECharacteristic(UUID16_CHR_BATTERY_LEVEL);

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

  // Enable UV sensor
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
  setupBattService();
  startAdv();

  Serial.println("[INFO] Start advertising...");
}

void loop() {
  // Battery
  vbat_raw = analogRead(VBAT_PIN);
  vbat_per = mvToPercent(vbat_raw * VBAT_MV_PER_LSB);
  vbat_mv = (float)vbat_raw * VBAT_MV_PER_LSB * VBAT_DIVIDER_COMP;

  // UV Index
  readUVIndexValue = uv.readUVI();
  uvindexvalue = round(abs(readUVIndexValue));
  displayLED(uvindexvalue);

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
    if (uv_index_characteristic.indicate(&uvindexvalue, sizeof(uvindexvalue))) {
      Serial.print("[INFO] Updated UV Index: ");
      Serial.println(uvindexvalue);
    } else {
      Serial.println("[ERROR] UV Index Indicate not set in the CCCD or not connected");
    }

    if (battery_level_characteristic.indicate(&vbat_per, sizeof(vbat_per))) {
      Serial.print("[INFO] Updated Battery level: ");
      Serial.print(vbat_per);
      Serial.println("%");
    } else {
      Serial.println("[ERROR] Battery level Indicate not set in the CCCD or not connected");
    }
  }

  Serial.print("[INFO] UV Index: ");
  Serial.println(uvindexvalue);
  Serial.print("[INFO] Battery level: ");
  Serial.print(vbat_per);
  Serial.println("%");
  Serial.println("");

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
  Bluefruit.Advertising.addService(environmental_sensing_service);
  Bluefruit.Advertising.addService(battery_service);

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
  environmental_sensing_service.begin();

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
  uv_index_characteristic.setProperties(CHR_PROPS_INDICATE);
  uv_index_characteristic.setPermission(SECMODE_OPEN, SECMODE_NO_ACCESS);
  uv_index_characteristic.setFixedLen(1);
  uv_index_characteristic.setCccdWriteCallback(cccd_callback);  // Optionally capture CCCD updates
  uv_index_characteristic.begin();
  uv_index_characteristic.write(&uvindexvalue, sizeof(uvindexvalue));
}

void setupBattService(void) {
  battery_service.begin();

  battery_level_characteristic.setProperties(CHR_PROPS_INDICATE);
  battery_level_characteristic.setPermission(SECMODE_OPEN, SECMODE_NO_ACCESS);
  battery_level_characteristic.setFixedLen(1);
  battery_level_characteristic.setCccdWriteCallback(cccd_callback);  // Optionally capture CCCD updates
  battery_level_characteristic.begin();
  battery_level_characteristic.write(&vbat_per, sizeof(vbat_per));
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
    if (chr->uuid == uv_index_characteristic.uuid) {
        if (chr->indicateEnabled(conn_hdl)) {
            Serial.println("[INFO] UV Index Measurement 'Indicate' enabled");
        } else {
            Serial.println("[INFO] UV Index Measurement 'Indicate' disabled");
        }
    } else if (chr->uuid == battery_level_characteristic.uuid) {
        if (chr->indicateEnabled(conn_hdl)) {
            Serial.println("[INFO] Battery level 'Indicate' enabled");
        } else {
            Serial.println("[INFO] Battery level 'Indicate' disabled");
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
