#include "remoteInstructor.h"

void runRemoteInstructor(){
  InstructorCommand command;
  while(1){  
    readInstructorCommand(&command);
    if(command.valid == INVALID_INSTRUCTOR_COMMAND){
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

void readInstructorCommand(InstructorCommand * command){}

void effectorRun(unsigned int effector){
  EFFECTOR_LIST[effector].serviceRoutine(-1);
}
void sensorRun(unsigned int sensor){
  SENSOR_LIST[sensor].serviceRoutine(-1);  
}
