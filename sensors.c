#include "sensors.h"
#include "simpletools.h"

/*
 * Service methods for input sensors. Each method should set or reset the 
 * sensorTriggerMap each time its called
 */


Sensor SENSOR_LIST[SENSOR_LIST_SIZE];
    

unsigned int validSensor(unsigned int sensorPin){
  for(int index = 0; index < SENSOR_PINS_SIZE; index++){
    if(sensorPin == SENSOR_PINS[index]){
      return 1;
    }
  }    
  return 0;
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
