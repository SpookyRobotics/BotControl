#include "remoteInstructor.h"
#include "simpletools.h"
#include "fdserial.h"

fdserial * serialIn;
void setup(){
  serialIn = fdserial_open (31, 30, 0, 9600);
}  
void runRemoteInstructor(){
  setup();
  InstructorCommand command;
  command.valid = INVALID_INSTRUCTOR_COMMAND;
  dprint(serialIn,"EFFECTOR_LIST_SIZE %d\n",EFFECTOR_LIST_SIZE);
  dprint(serialIn,"SENSOR_LIST_SIZE %d\n",SENSOR_LIST_SIZE);

  while(1){  
    readInstructorCommand(&command);
    validateInstructorCommand(&command);
    #ifdef DEBUG
    debugInstructorCommand(&command);
    #endif 
    if(command.valid != VALID_INSTRUCTOR_COMMAND){ 
      continue;
    } 
    for(int index = command.startEffectorsIndex; index < command.endEffectorsIndex; index++){
      char mask = 0x80 >> index;
      if(command.effectorsMask & mask){
        effectorRun(index);
      }      
    }
    for(int index = command.startSensorsIndex; index < command.endSensorsIndex; index++){
      char mask = 0x80 >> index;
      if(command.sensorsMask & mask){
        sensorRun(index);
      }      
    }  
  }       
}

void validateInstructorCommand(InstructorCommand * commandPtr){
  InstructorCommand command = *commandPtr;
  int validStartEffectorsIndex = command.startEffectorsIndex >= 0 && command.startEffectorsIndex < EFFECTOR_LIST_SIZE;
                                  
  int validEndEffectorsIndex = command.endEffectorsIndex >= 0 && 
                                   command.endEffectorsIndex <= EFFECTOR_LIST_SIZE && 
                                   command.endEffectorsIndex >= command.startEffectorsIndex;   
  int validStartSensorsIndex = command.startSensorsIndex >= 0 && command.startEffectorsIndex < SENSOR_LIST_SIZE;

  int validEndSensorsIndex = command.endSensorsIndex >= 0 && 
                                   command.endSensorsIndex <= SENSOR_LIST_SIZE && 
                                   command.endSensorsIndex >= command.startSensorsIndex;  
                                                                                                                            
  if(validStartEffectorsIndex && validEndEffectorsIndex && validStartSensorsIndex && validEndSensorsIndex){
    (*commandPtr).valid = VALID_INSTRUCTOR_COMMAND;
  }
  else{
    (*commandPtr).valid = INVALID_INSTRUCTOR_COMMAND;
  }
     
  
}  

#ifdef DEBUG
void debugInstructorCommand(InstructorCommand * commandPtr){
  dprint(serialIn,"Instructor: %d %d %d %d %d %d\n", (*commandPtr).startEffectorsIndex, 
                                      (*commandPtr).endEffectorsIndex,
                                      (*commandPtr).startSensorsIndex,
                                      (*commandPtr).endSensorsIndex,
                                      (*commandPtr).effectorsMask,
                                      (*commandPtr).sensorsMask); 
                                      
  InstructorCommand command = *commandPtr;                                    
  int validStartEffectorsIndex = command.startEffectorsIndex >= 0 && command.startEffectorsIndex < EFFECTOR_LIST_SIZE;
                                     
  int validEndEffectorsIndex = command.endEffectorsIndex >= 0 && 
                                   command.endEffectorsIndex <= EFFECTOR_LIST_SIZE && 
                                   command.endEffectorsIndex >= command.startEffectorsIndex;
  
  int validStartSensorsIndex = command.startSensorsIndex >= 0 && command.startEffectorsIndex < SENSOR_LIST_SIZE;
  int validEndSensorsIndex = command.endSensorsIndex >= 0 && 
                                   command.endSensorsIndex <= SENSOR_LIST_SIZE && 
                                   command.endSensorsIndex >= command.startSensorsIndex;  
  if(!validStartEffectorsIndex){
    dprint(serialIn,"Invalid  StartEffectorsIndex\n");
  }
  if(!validEndEffectorsIndex){
   dprint(serialIn,"Invalid  EndEffectorsIndex\n");
  }
  if(!validStartSensorsIndex){
    dprint(serialIn,"Invalid  StartSensorsIndex\n");
  }
  if(!validEndSensorsIndex){
    dprint(serialIn,"Invalid  EndSensorsIndex\n");
  }        
   
}  

#endif

int readInt(){
 int result = 0; 
 int index = 0;
 int byte = fdserial_rxChar(serialIn);
 while(byte !=  10){
   byte -= 48;
   result += byte;
   byte = fdserial_rxChar(serialIn);
 }
 return result;   
}  
void readInstructorCommand(InstructorCommand * commandPtr){
  (*commandPtr).valid = INVALID_INSTRUCTOR_COMMAND;
   int startEffectorsIndex;
   int endEffectorsIndex;
   int startSensorsIndex;
   int endSensorsIndex;
   int effectorsMask;
   int sensorsMask;
  
  dprint(serialIn,"Enter startEffectorsIndex: ");                        
  startEffectorsIndex = readInt();
  
  dprint(serialIn,"Enter endEffectorsIndex: ");
  endEffectorsIndex = readInt();
  
  dprint(serialIn,"Enter startSensorsIndex: ");
  startSensorsIndex = readInt();
  
  dprint(serialIn,"Enter endSensorsIndex: ");
  endSensorsIndex = readInt();
  
  dprint(serialIn,"Enter effectorsMask: ");
  effectorsMask = readInt();
  
  dprint(serialIn,"Enter sensorsMask: ");
  sensorsMask = readInt();
  
  (*commandPtr).startEffectorsIndex = startEffectorsIndex;
  (*commandPtr).endEffectorsIndex = endEffectorsIndex;
  (*commandPtr).startSensorsIndex = startSensorsIndex;
  (*commandPtr).endSensorsIndex = endSensorsIndex;
  (*commandPtr).effectorsMask = effectorsMask;
  (*commandPtr).sensorsMask = sensorsMask;
  
}

void effectorRun(unsigned int effector){
  EFFECTOR_LIST[effector].serviceRoutine(-1);
}
void sensorRun(unsigned int sensor){
  SENSOR_LIST[sensor].serviceRoutine(-1);  
}
