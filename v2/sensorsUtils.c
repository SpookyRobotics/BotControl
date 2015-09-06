#include "sensorsUtils.h"

void startSensorHandlerLoop(volatile unsigned int * sensorTriggerMap){
  while(1){
    unsigned int triggerMapUpdate = 0;
    for(int index = 0; index < SENSOR_LIST_SIZE; index++){
      triggerMapUpdate |= SENSOR_LIST[index].serviceRoutine(); 
    }
    *sensorTriggerMap = triggerMapUpdate;
  } 
}

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

unsigned int debouncePinRead(unsigned int pinToRead){
    int n = 16;
    int result  = -1;       // Number of counts to declare high input
    int reading =  0;
    int pins = 1 << pinToRead;
    while(n--){
      reading = pins;        // reset mask
      DIRA &= ~pins;         // switch to input
      pause(2);              // wait for RC time
      reading &= INA;        // mask desired pin with single pin states
      if(reading > 0){       // accumulate count if pin is high
        result += 1;          
      }        
    }
    if(result > 0){
      return 1;
    }      
    return 0;
}

unsigned int debounceReadInput(){
    int n = 16;
    int result = 0;
    int assertHighCount  = -1;       // Number of counts to declare high input
    int reading[16];
    int pins = 0xFF;
    for(int index =0; index < n; index++){
      DIRA &= ~pins;         // switch to input
      pause(2);              // wait for RC time
      reading[index] = INA;  // read input register
             
    }
    // For each bit, count the number of times set. If
    // a pin is set more times than absolute value of assertHighCount
    // mark as set in result
    for(int index = 0; index < 32; index++){
      int assertCount = assertHighCount;
      int highMask = 1 << index;
      for(int  index2 = 0; index2 < 16; index2++){
        if(reading[index2] & highMask){
          assertCount += 1;
          if(assertCount > 0){
            result |= 1 << index;
            break;
          }
        }                      
      }        
    }      
    return result;
}