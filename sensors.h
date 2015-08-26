#ifndef SENSORS_HEADER
#define SENSORS_HEADER

#define SENSOR_LIST_SIZE 8
#define SENSOR_PINS_SIZE 8

typedef struct {
  char name[12];
  int pinNumber;
  unsigned int (*serviceRoutine)();
  unsigned int sensorMapBit;
  
} Sensor;

extern volatile unsigned int SENSOR_TRIGGER_MAP;
extern Sensor SENSOR_LIST[];
extern int SENSOR_PINS[SENSOR_PINS_SIZE];

unsigned int debouncePinRead(unsigned int pinToRead);
unsigned int validSensor(unsigned int sensorPin);
unsigned int sensorTriggered(Sensor sensor);
unsigned int sensorReset(Sensor sensor);
unsigned int debounceReadInput();
void sensorsInit();
#endif