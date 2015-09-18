#include "remoteInstructor.h"
#include "simpletools.h"

void runRemoteInstructor(){
  InstructorCommand command;
  command.valid = INVALID_INSTRUCTOR_COMMAND;
  print("EFFECTOR_LIST_SIZE %d\n",EFFECTOR_LIST_SIZE);
  print("SENSOR_LIST_SIZE %d\n",SENSOR_LIST_SIZE);

  while(1){  
    readInstructorCommand(&command);
    validateInstructorCommand(&command);
    debugInstructorCommand(&command);
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

void debugInstructorCommand(InstructorCommand * commandPtr){
  print("Instructor: %d %d %d %d %d %d\n", (*commandPtr).startEffectorsIndex, 
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
    print("Invalid  StartEffectorsIndex\n");
  }
  if(!validEndEffectorsIndex){
    print("Invalid  EndEffectorsIndex\n");
  }
  if(!validStartSensorsIndex){
    print("Invalid  StartSensorsIndex\n");
  }
  if(!validEndSensorsIndex){
    print("Invalid  EndSensorsIndex\n");
  }        
   
}  


void readInstructorCommand(InstructorCommand * commandPtr){
  (*commandPtr).valid = INVALID_INSTRUCTOR_COMMAND;
   int startEffectorsIndex;
   int endEffectorsIndex;
   int startSensorsIndex;
   int endSensorsIndex;
   int effectorsMask;
   int sensorsMask;
  
  print("Enter startEffectorsIndex: ");                        
  scan("%d\n", &startEffectorsIndex);
  
  print("Enter endEffectorsIndex: ");
  scan("%d\n", &endEffectorsIndex);

  print("Enter startSensorsIndex: ");
  scan("%d\n", &startSensorsIndex);

  print("Enter endSensorsIndex: ");
  scan("%d\n", &endSensorsIndex);
  
  print("Enter effectorsMask: ");
  scan("%d\n", &effectorsMask);
  
  print("Enter sensorsMask: ");
  scan("%d\n", &sensorsMask);
  
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
