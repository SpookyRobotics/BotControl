#ifndef EFFECTORS_HEADER
#define EFFECTORS_HEADER

#define BLUE_LED 0
#define GREEN_LED 1
#define WHITE_LED 2
#define RED_LED 3
#define RED_LASER 4
#define SPEAKER 7
#define SERVO1 8
#define DEBUG_LED_1 10
#define DEBUG_LED_2 11
#define DEBUG_LED_3 12
#define DEBUG_LED_4 13
#define DEBUG_LED_5 14
#define DEBUG_LED_6 15
#define DEBUG_LED_7 19
#define DEBUG_LED_8 18
#define DEBUG_LED_9 17
#define DEBUG_LED_10 16

#define EFFECTOR_LIST_SIZE 7
#define EFFECTOR_PINS_SIZE 15


typedef struct {
  char name[12];
  int pinNumbersSize;
  int * pinNumbers;
  void (*serviceRoutine)(unsigned int); 
} Effector;

extern Effector BlueLed;
extern Effector GreenLed;
extern Effector WhiteLed;
extern Effector RedLed;
extern Effector RedLaser;
extern Effector Speaker;
extern Effector DebugLeds;
extern Effector EFFECTOR_LIST[EFFECTOR_LIST_SIZE]; 
extern int EFFECTOR_PINS[];

void serviceBlueLed(unsigned int);
void serviceGreenLed(unsigned int);
void serviceWhiteLed(unsigned int);
void serviceRedLed(unsigned int);
void serviceRedLaser(unsigned int);
void serviceSpeaker(unsigned int);
void serviceDebugLeds(unsigned int);
void initEffectors();
void defaultEffectorService(int state, int * pins, int pinsLength);
int validEffector(unsigned int sensorPin);
void togglePins(unsigned int sensors[], unsigned int sensorsLength,unsigned int onTimeMs, unsigned int offTimeMs);

#endif