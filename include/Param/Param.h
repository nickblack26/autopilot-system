#include <cmath>
#include <stdint.h>

#define AP_Int8 uint8_t
#define AP_Int16 uint16_t
#define AP_Int32 uint32_t

/*
    Parameters for a fixed wing aircraft
*/

struct FixedWing {
    AP_Int8  throttle_min; 
    AP_Int8  throttle_max; 
    AP_Int8  throttle_cruise; 
    AP_Int8  takeoff_throttle_max; 
    AP_Int8  takeoff_throttle_min;
    AP_Int16 airspeed_min;
    AP_Int16 airspeed_max;
    AP_Int32 airspeed_cruise_cm;
    AP_Int32 min_gndspeed_cm;
    AP_Int8  crash_detection_enable;
    AP_Int16 roll_limit_cd;
    AP_Int16 pitch_limit_max_cd;
    AP_Int16 pitch_limit_min_cd;        
    AP_Int8  autotune_level;
    AP_Int8  stall_prevention;
    AP_Int16 loiter_radius;

    struct Rangefinder_State {
        bool in_range:1;
        bool have_initial_reading:1;
        bool in_use:1;
        float initial_range;
        float correction;
        float initial_correction;
        float last_stable_correction;
        AP_Int32 last_correction_time_ms;
        AP_Int8 in_range_count;
        float height_estimate;
        float last_distance;
        };


        // stages of flight
    enum FlightStage {
        FLIGHT_TAKEOFF      = 1,
        FLIGHT_VTOL         = 2,
        FLIGHT_NORMAL       = 3,
        FLIGHT_LAND         = 4,
        FLIGHT_ABORT_LAND   = 7
        };
};
    enum class ControlOutput {
        Roll                = 1,
        Pitch               = 2,
        Throttle            = 3,
        Yaw                 = 4,
        Lateral             = 5,
        MainSail            = 6,
        WingSail            = 7,
        Walking_Height      = 8,
        Last_ControlOutput  // place new values before this
        };
