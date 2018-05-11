#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "patient.h"
#include "queue.h"
#include "simulation.h"
#include "LinkedListAPI.h"
int time = 1;
int main(int argc, char* argv[])
{
    FILE* fp = NULL;
    Queue* q1 = initializeQueue(&printData, &deleteData, &compareQ);
    Queue* q2 = initializeQueue(&printData, &deleteData, &compareQ);
    if(argc == 1) {
	printf("Error entering file\n");
	printf("Exit status\n");
	return 0;
    }
    if(argc > 1){
        fp = fopen(argv[1], "r");
        rewind(fp);
        runSim(fp, q1, q2, time);
    }
    if(argc > 1) {
	fclose(fp);
    }
    return 0;
}
