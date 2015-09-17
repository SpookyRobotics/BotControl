#ifndef REMOTE_INSTRUCTOR_HEADER_FILE
#define REMOTE_INSTRUCTOR_HEADER_FILE

#define INVALID_INSTRUCTOR_COMMAND 100
#define VALID_INSTRUCTOR_COMMAND 101
#include "structs.h"

void readInstructorCommand(InstructorCommand * command);
void runRemoteInstructor();
void effectorRun(unsigned int effector);
void sensorRun(unsigned int sensor);

#endif
