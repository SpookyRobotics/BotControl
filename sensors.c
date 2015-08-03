#include "sensors.h"
#include "simpletools.h"

/*
 * Service methods for input sensors. Each method should set or reset the 
 * sensorTriggerMap each time its called
 */

extern unsigned int SENSOR_TRIGGER_MAP;

void serviceCollisionDetector(){
  int value = input(COLLISION_DETECTOR);
  if(value == 0){
    sensorTriggered(COLLISION_DETECTOR);  
  }
  else{
	  sensorReset(COLLISION_DETECTOR);
  }
}  
void serviceReedSwitch(){
  int value = input(MAGNETIC_REED);
  if(value == 0){
      sensorTriggered(MAGNETIC_REED);  
  }
  else{
	  sensorReset(MAGNETIC_REED);
  }    
}  

int validSensor(unsigned int sensorPin){
	switch(sensorPin){
			case MAGNETIC_REED:
			case COLLISION_DETECTOR:
				return 1;
			default:
				return 0;
		}
}

void sensorTriggered(unsigned int sensorPin){
	if(validSensor(sensorPin)){
		SENSOR_TRIGGER_MAP |= 1 << sensorPin;
	}
}

void sensorReset(unsigned int sensorPin){
	if(validSensor(sensorPin)){
		int mask = 1 << sensorPin;
		mask = ~mask;
		SENSOR_TRIGGER_MAP &= mask;
	}
}
