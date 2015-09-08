#ifndef MAIN_HEADER_FILE
#define MAIN_HEADER_FILE
#include "simpletools.h"
#include "config.h"
#include "structs.h"

#define SENSORS_INIT() EXPAND_SENSORS(CONFIG)
#define EXPAND_SENSORS(x) SENSOR_FUNCTION_MACRO(x)
#define SENSOR_FUNCTION_MACRO(x) x ## SensorsInit()

#define EFFECTORS_INIT() EXPAND_EFFECTORS(CONFIG)
#define EXPAND_EFFECTORS(x) EFFECTOR_FUNCTION_MACRO(x)
#define EFFECTOR_FUNCTION_MACRO(x) x ## EffectorsInit()


#endif