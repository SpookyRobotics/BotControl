#include "sensorsUtils.h"
#include "effectorsUtils.h"

volatile unsigned int SENSOR_TRIGGER_MAP;
Sensor SENSOR_LIST[SENSOR_LIST_SIZE];
int SENSOR_PINS[SENSOR_PINS_SIZE];
int EFFECTOR_PINS[EFFECTOR_PINS_SIZE];
Effector EFFECTOR_LIST[EFFECTOR_LIST_SIZE];

// Read the sensors and update the SENSOR_TRIGGER_MAP
// to inform other cogs of a change in the environment
void cog1Program(){
  unsigned int triggerMapUpdate = 0;
  SENSOR_TRIGGER_MAP = 0;
  startSensorHandlerLoop();
}



// Control all non Motor output
void cog2Program(){
  unsigned int triggerMap = 0;
  startEffectorHandlerLoop();    
}

void main(){}