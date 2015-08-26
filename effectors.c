#include "sensors.h"
#include "simpletools.h"
#include "effectors.h"

int blueLedPins[] = {BLUE_LED};
int greenLedPins[] = {GREEN_LED};
int whiteLedPins[] = {WHITE_LED};
int redLedPins[] = {RED_LED};
int redLaserPins[] = {RED_LASER};
int speakerPins[] = {SPEAKER};
int debugLedPins[] = {DEBUG_LED_1,DEBUG_LED_2,DEBUG_LED_3,
                       DEBUG_LED_4,DEBUG_LED_5,DEBUG_LED_6,
                       DEBUG_LED_7,DEBUG_LED_8,DEBUG_LED_9,
                       DEBUG_LED_10};
                       
Effector BlueLed = {"BlueLed",1,blueLedPins,&serviceBlueLed};
Effector GreenLed = {"GreenLed",1,greenLedPins,&serviceGreenLed};
Effector WhiteLed = {"WhiteLed",1,whiteLedPins,&serviceWhiteLed};
Effector RedLed = {"RedLed",1,redLedPins,&serviceRedLed};
Effector RedLaser = {"RedLaser",1,redLaserPins,&serviceRedLaser};
Effector Speaker = {"Speaker",1,speakerPins,&serviceSpeaker};
Effector DebugLeds = {"DebugLeds",10,debugLedPins,&serviceDebugLeds};
                       
int EFFECTOR_PINS[] = {BLUE_LED,
                      GREEN_LED,
                      WHITE_LED,
                      RED_LED,
                      RED_LASER,
                      SPEAKER,
                      DEBUG_LED_1,
                      DEBUG_LED_2,
                      DEBUG_LED_3,
                      DEBUG_LED_4,
                      DEBUG_LED_5,
                      DEBUG_LED_6,
                      DEBUG_LED_7,
                      DEBUG_LED_8,
                      DEBUG_LED_9,
                      DEBUG_LED_10};
Effector EFFECTOR_LIST[]; 

void initEffectors(){
  EFFECTOR_LIST[0] = BlueLed;
  EFFECTOR_LIST[1] = GreenLed;
  EFFECTOR_LIST[2] = WhiteLed;
  EFFECTOR_LIST[3] = RedLed;
  EFFECTOR_LIST[4] = RedLaser;
  EFFECTOR_LIST[5] = Speaker;
  EFFECTOR_LIST[6] = DebugLeds;
}

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
void serviceBlueLed(unsigned int effectorMap){
  static int state = 0;
  defaultEffectorService(state,BlueLed.pinNumbers, BlueLed.pinNumbersSize);
  pause(100);
  state = !state;
}
void serviceGreenLed(unsigned int effectorMap){
  static int state = 0;
  defaultEffectorService(state,GreenLed.pinNumbers, GreenLed.pinNumbersSize);
  pause(200);
  state = !state;
}
void serviceWhiteLed(unsigned int effectorMap){
  static int state = 0;
  defaultEffectorService(state,WhiteLed.pinNumbers, WhiteLed.pinNumbersSize);
  pause(300);
  state = !state;
}
void serviceRedLed(unsigned int effectorMap){
  static int state = 0;
  defaultEffectorService(state,DebugLeds.pinNumbers, DebugLeds.pinNumbersSize);
  pause(400);
  state = !state;
}
void serviceRedLaser(unsigned int effectorMap){}
void serviceSpeaker(unsigned int effectorMap){}
void serviceDebugLeds(unsigned int effectorMap){
  static int state = 0;
  defaultEffectorService(state,RedLed.pinNumbers, RedLed.pinNumbersSize);
  pause(400);
  state = !state;
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
