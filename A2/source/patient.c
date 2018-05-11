#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"
#include "LinkedListAPI.h"
#include "queue.h"

Patient* initializePatient(char a[], int* b, char c[])
{
    Patient* newPatient = (Patient*)malloc(sizeof(Patient));
    strcpy(newPatient->x, a);
    strcpy(newPatient->z,c);
    newPatient->y = *b;
    return newPatient;
}

void printData(void* data)
{
    Patient* temp = (Patient*)data;
    printf("%10s %10d %15s %15d\n", temp->x, temp->y, temp->z, (temp->time));
}

void deleteData(void* data)
{
    free(data);
}

