#include "quickstartConfig.h"
#include "simpletools.h"
#include "sensors.h"
#include "effectors.h"
#include "testFunctions.h"


/*Startup 
#define SENSOR_LIST_SIZE 8
#define SENSOR_PINS_SIZE 8
#define EFFECTOR_LIST_SIZE 1
#define EFFECTOR_PINS_SIZE 8*/

int EFFECTOR_PINS[] = {LED0,LED1,LED2,LED3,LED4,LED5,LED6,LED7};
int SENSOR_PINS[] = {TOUCH0,TOUCH1,TOUCH2,TOUCH3,TOUCH4,TOUCH5,TOUCH6,TOUCH7};

void sensorsInit(){
  SENSOR_LIST[0] = touch0;
  SENSOR_LIST[1] = touch1;
  SENSOR_LIST[2] = touch2;
  SENSOR_LIST[3] = touch3;
  SENSOR_LIST[4] = touch4;
  SENSOR_LIST[5] = touch5;
  SENSOR_LIST[6] = touch6;
  SENSOR_LIST[7] = touch7;
}

void effectorsInit(){
  EFFECTOR_LIST[0] = leds;
}

// Begin Synchronous Timed functions

void initSynchronizedTimerFunctions(){
  TIMER_COG_FUNCTIONS[0] = blinkLed;
  TIMER_COG_FUNCTIONS[1] = blinkLed2;
}

/* End Startup */

/************************
 * Begin Effector Layout
 ***********************/
int ledPins[] = {LED0,LED1,LED2,LED3,LED4,LED5,LED6,LED7};

Effector leds = {"Leds",8,ledPins,&serviceLeds};

void serviceLeds(unsigned int effectorMap){
  static int state = 0;
  defaultEffectorService(state,leds.pinNumbers, leds.pinNumbersSize);
  pause(100);
  state = !state;
}

/************************
 * Begin Sensor Layout
 ***********************/

Sensor touch0 = {"TOUCH0",TOUCH0, &serviceTouch0,0};
Sensor touch1 = {"TOUCH1",TOUCH1, &serviceTouch1,1};
Sensor touch2 = {"TOUCH2",TOUCH2, &serviceTouch2,2};
Sensor touch3 = {"TOUCH3",TOUCH3, &serviceTouch3,3};
Sensor touch4 = {"TOUCH4",TOUCH4, &serviceTouch4,4};
Sensor touch5 = {"TOUCH5",TOUCH5, &serviceTouch5,5};
Sensor touch6 = {"TOUCH6",TOUCH6, &serviceTouch6,6};
Sensor touch7 = {"TOUCH7",TOUCH7, &serviceTouch7,7};



unsigned int serviceTouch0(){
  if(debouncePinRead(touch0.pinNumber) == 1){
    high(23);
    pause(30);
    low(23);
    pause(30);
  }     
}  

unsigned int serviceTouch1(){
  if(debouncePinRead(touch1.pinNumber) == 1){
    high(22);
    pause(30);
    low(22);
    pause(30);
  }     
} 

unsigned int serviceTouch2(){
  if(debouncePinRead(touch2.pinNumber) == 1){
    high(21);
    pause(100);
    low(21);
    pause(100);
  }     
} 

unsigned int serviceTouch3(){
  if(debouncePinRead(touch3.pinNumber) == 1){
    high(20);
    pause(100);
    low(20);
    pause(100);
  }     
} 

unsigned int serviceTouch4(){
  if(debouncePinRead(touch4.pinNumber) == 1){
    high(19);
    pause(100);
    low(19);
    pause(100);
  }     
} 

unsigned int serviceTouch5(){
  if(debouncePinRead(touch5.pinNumber) == 1){
    high(18);
    pause(100);
    low(18);
    pause(100);
  }     
} 

unsigned int serviceTouch6(){
  if(debouncePinRead(touch6.pinNumber) == 1){
    high(17);
    pause(100);
    low(17);
    pause(100);
  }     
} 

unsigned int serviceTouch7(){
  if(debouncePinRead(touch7.pinNumber) == 1){
    high(16);
    pause(100);
    low(16);
    pause(100);
  }     
} 

