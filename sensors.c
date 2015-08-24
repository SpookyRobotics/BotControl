#include "sensors.h"
#include "simpletools.h"


/*
 * Service methods for input sensors. Each method should set or reset the 
 * sensorTriggerMap each time its called
 */

extern volatile unsigned int SENSOR_TRIGGER_MAP;

unsigned int serviceCollisionDetector(){
  int value = input(COLLISION_DETECTOR);
  if(value == 0){
    return sensorTriggered(COLLISION_DETECTOR);  
  }
  else{
	  return sensorReset(COLLISION_DETECTOR);
  }
}  

unsigned int serviceReedSwitch(){
  int value = input(MAGNETIC_REED);
  if(value == 0){
      return sensorTriggered(MAGNETIC_REED);  
  }
  else{
	  return sensorReset(MAGNETIC_REED);
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

unsigned int sensorTriggered(unsigned int sensorPin){
	if(validSensor(sensorPin)){
		unsigned int copy = SENSOR_TRIGGER_MAP;
     return copy |= 1 << sensorPin;
	}
  return 0;
}

unsigned int sensorReset(unsigned int sensorPin){
	if(validSensor(sensorPin)){
		int mask = 1 << sensorPin;
		mask = ~mask;
		unsigned int copy = SENSOR_TRIGGER_MAP;
     return copy &= mask;
	}
  return 0;
}
