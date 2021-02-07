#include <SFE_BMP180.h>
#include <Wire.h>

#define ALTITUDE 195.0 // Altitude in Denton

SFE_BMP180 pressure;

void init_Pres() {
    Serial.println("REBOOT");

    // Initialize the sensor (it is important to get calibration values stored on the device).
    if (pressure.begin())
        Serial.println("BMP180 init success");
    else 
        Serial.println("BMP180 init fail\n\n");
        while(1);
}