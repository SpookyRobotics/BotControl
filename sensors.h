#ifndef SENSORS_HEADER
#define SENSORS_HEADER


#define MAGNETIC_REED 5
#define COLLISION_DETECTOR 6

unsigned int SENSOR_TRIGGER_MAP;


int validSensor(unsigned int sensorPin);
void sensorTriggered(unsigned int sensorPin);
void sensorReset(unsigned int sensorPin);

void serviceCollisionDetector();
void serviceReedSwitch();
#endif