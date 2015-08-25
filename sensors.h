#ifndef SENSORS_HEADER
#define SENSORS_HEADER

#define SENSOR_LIST_SIZE 2
#define MAGNETIC_REED 5
#define COLLISION_DETECTOR 6
#define DEBUG_SENSOR 200

typedef struct {
  char name[12];
  int pinNumber;
  unsigned int (*serviceRoutine)();
  unsigned int sensorMapBit;
  
} Sensor;

extern Sensor MAGNETIC_REED_SENSOR; 
extern Sensor COLLISION_DETECTOR_SENSOR;
extern Sensor SENSOR_LIST[];

unsigned int validSensor(unsigned int sensorPin);
unsigned int sensorTriggered(Sensor sensor);
unsigned int sensorReset(Sensor sensor);

unsigned int serviceCollisionDetector();
unsigned int serviceReedSwitch();
void sensorInit();
#endif