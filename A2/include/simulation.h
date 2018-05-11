
#ifndef _SIMULATION_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"
#include "queue.h"
#include "LinkedListAPI.h"


void setTime(Queue* q, int x);
void getMatch(Queue* q1, Queue* q2);
void addPatient(Queue* q1, Queue* q2);
void runSim(FILE* fp, Queue* q1, Queue* q2, int time);
#endif
