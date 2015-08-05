#ifndef SENSORS_HEADER
#define SENSORS_HEADER


#define MAGNETIC_REED 5
#define COLLISION_DETECTOR 6


int validSensor(unsigned int sensorPin);
unsigned int sensorTriggered(unsigned int sensorPin);
unsigned int sensorReset(unsigned int sensorPin);

unsigned int serviceCollisionDetector();
unsigned int serviceReedSwitch();
#endif