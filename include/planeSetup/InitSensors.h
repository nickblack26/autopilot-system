#include <sensorSetup/bno055.h>
#include <sensorSetup/bmp180.h>


void init_Plane() {
    init_IMU(); // IMU (bno055) initialization
    init_Pres(); // Pressure / Altitude Sensor (BMP180)
}
