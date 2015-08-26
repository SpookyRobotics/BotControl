#include "simpletools.h"
#include "effectors.h"
#include "breadBoardConfig.h"

/* Startup 


int SENSOR_PINS[] = {MAGNETIC_REED ,COLLISION_DETECTOR,DEBUG_SENSOR};
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
                      
void sensorsInit(){
  SENSOR_LIST[0] = DEBUG_SENSOR1;
  SENSOR_LIST[1] = DEBUG_SENSOR2;
}

void effectorsInit(){
  EFFECTOR_LIST[0] = BlueLed;
  EFFECTOR_LIST[1] = GreenLed;
  EFFECTOR_LIST[2] = WhiteLed;
  EFFECTOR_LIST[3] = RedLed;
  EFFECTOR_LIST[4] = RedLaser;
  EFFECTOR_LIST[5] = Speaker;
  EFFECTOR_LIST[6] = DebugLeds;
}



 End Startup 
*/

/************************
 * Begin Effector Layout
 * *********************/

                      
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

/*****************
 * Begin sensor layout 
 * **************/

Sensor MAGNETIC_REED_SENSOR = {"MAG_REED",MAGNETIC_REED, &serviceReedSwitch,0};
Sensor COLLISION_DETECTOR_SENSOR = {"COL_DETECT",COLLISION_DETECTOR, &serviceCollisionDetector,1};

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


