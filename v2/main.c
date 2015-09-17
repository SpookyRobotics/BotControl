#include "main.h"
#include "breadboardConfig.h"

volatile unsigned int SENSOR_TRIGGER_MAP;
Sensor SENSOR_LIST[SENSOR_LIST_SIZE];
int SENSOR_PINS[SENSOR_PINS_SIZE];
int EFFECTOR_PINS[EFFECTOR_PINS_SIZE];
Effector EFFECTOR_LIST[EFFECTOR_LIST_SIZE];


// Read the sensors and update the SENSOR_TRIGGER_MAP
// to inform other cogs of a change in the environment
void cog1Program(){
  SENSOR_TRIGGER_MAP = 0;
  SENSORS_INIT(); 
  startSensorHandlerLoop(&SENSOR_TRIGGER_MAP);
}



// Control all non Motor output
void cog2Program(){
  EFFECTORS_INIT();
  startEffectorHandlerLoop(&SENSOR_TRIGGER_MAP);    
}

// Control motor output
void cog3Program(){
  servoTest();
}  

 

int main(){
  cog_run(&cog1Program,100);
  cog_run(&cog2Program,100); 
  cog_run(&cog3Program,100);
  return 0;
}