#include "sensors.h"
#include "simpletools.h"
#include "effectors.h"

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
  switch(sensorPin){
    case BLUE_LED:
    case GREEN_LED:
    case WHITE_LED:
    case RED_LED:
    case RED_LASER:
    case SPEAKER:
    case SERVO1:
      return 1;
    default: 
      return 0; 
  }    
}  
