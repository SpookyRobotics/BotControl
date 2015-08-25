#include "sensors.h"
#include "simpletools.h"
#include "testFunctions.h"

/*
 * Service methods for input sensors. Each method should set or reset the 
 * sensorTriggerMap each time its called
 */

extern volatile unsigned int SENSOR_TRIGGER_MAP;

Sensor MAGNETIC_REED_SENSOR = {"MAG_REED",MAGNETIC_REED, &serviceReedSwitch,0};
Sensor COLLISION_DETECTOR_SENSOR = {"COL_DETECT",COLLISION_DETECTOR, &serviceCollisionDetector,1};


Sensor SENSOR_LIST[SENSOR_LIST_SIZE];

void sensorInit(){
  SENSOR_TRIGGER_MAP = 0;
  SENSOR_LIST[0] = DEBUG_SENSOR1;
  SENSOR_LIST[1] = DEBUG_SENSOR2;
}


    
unsigned int serviceCollisionDetector(){
  int value = input(COLLISION_DETECTOR);
  if(value == 0){
    return sensorTriggered(COLLISION_DETECTOR_SENSOR);  
  }
  else{
	  return sensorReset(COLLISION_DETECTOR_SENSOR);
  }
}  

unsigned int serviceReedSwitch(){
  int value = input(MAGNETIC_REED);
  if(value == 0){
      return sensorTriggered(MAGNETIC_REED_SENSOR);  
  }
  else{
	  return sensorReset(MAGNETIC_REED_SENSOR);
  }    
}  

unsigned int validSensor(unsigned int sensorPin){
	switch(sensorPin){
			case MAGNETIC_REED:
			case COLLISION_DETECTOR:
       case DEBUG_SENSOR:
				return 1;
			default:
				return 0;
		}
}

unsigned int sensorTriggered(Sensor sensor){
	if(validSensor(sensor.pinNumber)){
		unsigned int copy = SENSOR_TRIGGER_MAP;
     return copy |= 1 << sensor.sensorMapBit;
	}
  return 0;
}

unsigned int sensorReset(Sensor sensor){
	if(validSensor(sensor.pinNumber)){
		int mask = 1 << sensor.sensorMapBit;
		mask = ~mask;
		unsigned int copy = SENSOR_TRIGGER_MAP;
     return copy &= mask;
	}
  return 0;
}
