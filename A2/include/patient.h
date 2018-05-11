#ifndef _PATIENT_
#define _PATIENT_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedListAPI.h"
#include "queue.h"

struct patient {
    char x[10];
    int y;
    char z[10];
    int time;
}; typedef struct patient Patient;

Patient* initializePatient(char a[], int* b, char c[]);
void printData(void* x);
void deleteData(void* x);


#endif
