#include "sensors.h"
#include "simpletools.h"
#include "effectors.h"

                       

Effector EFFECTOR_LIST[]; 



void defaultEffectorService(int pinState, int * pins, int pinsLength){
  for(int index = 0; index < pinsLength; index++){
    if(pinState == 0){
      high(pins[index]);
      pinState = 1;
    }
    else{
      low(pins[index]);
      pinState = 0;
    }   
  }    
}  

  
void togglePins(unsigned int sensors[], unsigned int sensorsLength,unsigned int onTimeMs, unsigned int offTimeMs){
  for(int index = 0; index < sensorsLength; index++){
    unsigned int pin = sensors[index];
    if(!validEffector(pin)){
      sensors[index]   = -1; 
    }    
    else{
      high(pin);
    }      
  }    
       
  pause(onTimeMs);
  for(int index = 0; index < sensorsLength; index++){
    unsigned int pin = sensors[index];
    if(pin != -1){
      low(pin);
    }        
  }
  pause(offTimeMs);
    
}  

int validEffector(unsigned int sensorPin){
  for(int index = 0; index < EFFECTOR_PINS_SIZE; index++){
    if(sensorPin == EFFECTOR_PINS[index]){
      return 1;
    }
  }    
  return 0;
}  
