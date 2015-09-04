#include "sensorUtils.h"
#include "effectorsUtils.h"
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

