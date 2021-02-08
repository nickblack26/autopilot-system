#include <Arduino.h>
#include <Plane.h>

Plane plane;

void setup (void) {
  Serial.begin(9600);
  plane.begin_pre_flight();
  plane.cal_sensors();
  plane.get_init_state();
}

void loop (void) {
  plane.get_status();
  delay(2000);
}