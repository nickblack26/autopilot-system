/*
    Main Autopilot Class
*/

#include <sensorSetup/BNO055.h>
#include <sensorSetup/BMP180.h>
#include <cmath>
#include <Param/Param.h>

class Plane : public FixedWing {
public:

    bool begin_pre_flight();
    void get_status();
    void cal_sensors();
    void get_init_state();

private:    
    
};

void Plane::cal_sensors() {
    AP_Int8 system, gyro, accel, mag;
    system = gyro = accel = mag = 0;
    

    while (gyro != 3) {
        bno.getCalibration(&system, &gyro, &accel, &mag);

        Serial.print(" G:");
        Serial.print(gyro, DEC);
    }

    if (gyro == 3) {
        Serial.print("System calibrated!\n");
        Serial.println("\n");
    }
    delay(1000);
}

bool Plane::begin_pre_flight() { 
    Serial.println("Orientation Sensor Test"); Serial.println("");
  
    /* Initialize the IMU */
    if(!bno.begin()) {
        /* There was a problem detecting the BNO055 ... check your connections */
        Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
        while(1);
    }
    
    delay(1000);
        
    bno.setExtCrystalUse(true);
}

void Plane::get_status() {
    sensors_event_t event; 
    bno.getEvent(&event);
  
    /* Display the floating point data */
    Serial.print("---------------------------------\n");
    Serial.print("Roll: ");
    Serial.print(event.orientation.z, 4);
    Serial.print("\tPitch: ");
    Serial.print(event.orientation.y, 4);
    Serial.print("\n\nYaw: ");
    Serial.print(event.orientation.x, 4);
    Serial.print("\tTemp: ");
    Serial.print(bno.getTemp());
    Serial.print("cº");
    Serial.println("\n");
}

void Plane::get_init_state() {
    sensors_event_t secondEvent; 
    bno.getEvent(&secondEvent);

    pitch_limit_min_cd = (secondEvent.orientation.y) - 10;
    pitch_limit_max_cd = (secondEvent.orientation.y) + 45;
    roll_limit_cd = 55;

    Serial.print("Minimum Pitch Limit: ");
    Serial.print(pitch_limit_min_cd);
    Serial.print("\tMaximum Pitch Limit: ");
    Serial.print(pitch_limit_max_cd);
    Serial.print("\tRoll Limit: ");
    Serial.print(roll_limit_cd);
    Serial.println("");
    delay(1000);
}