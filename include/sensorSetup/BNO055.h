#include <Adafruit_BNO055.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>


Adafruit_BNO055 bno = Adafruit_BNO055(55);

void init_IMU () {
  if(!bno.begin()) {
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);

    delay(1000);
    
    bno.setExtCrystalUse(true);
  }
}