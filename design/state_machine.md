graph TD;
A((POWER OFF))-->|Turn ON the power switch|B((POWER ON, NOT ADVERTISING));
B-->|Turn OFF the power switch| A
B-->|Turn ON wireless connectivity switch| C((POWER ON, ADVERTISING))
C-->|Turn OFF wireless connectivity switch| B
B-->|Sensor timer up| D((Read UV Index and display RGB LED))
C-->|Sensor timer up| D((Read UV Index and display RGB LED))
C-->|BLE advertising interval up| C
C-->|Connected to BLE central| E((Display UV Index on iOS app))
