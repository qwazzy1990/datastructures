#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"
#include "queue.h"
#include "LinkedListAPI.h"
#include "simulation.h"
void runSim(FILE* fp, Queue* q1, Queue* q2, int time)
{
    int choice = 0;
    readFile(fp, q1, q2);
    Node* i1 = q1->head;
    Node* i2 = q2->head; 
    while(1 == 1) {
	printf("Enter 1 to enter a new patient\n");
	printf("Enter 2 to process patients and exit\n");
        fscanf(stdin, "%d", &choice);
        if(choice == 1) {
	    addPatient(q1, q2);	    
	}
        if(choice == 2) {
	   setTime(q1, time);
           getMatch(q1, q2);
	printf("Patient ID	Priority	Symptom Code	Time Finished\n\n");
	   while(q2->head != NULL) {
	       printData(q2->head->data);
	       q2->head = q2->head->next;
	   } 
           q1->head = i1;
	   q2->head = i2;
           while(q1->head != NULL) {
		i1 = q1->head;
		free((Patient*)i1->data);
		free(i1);
		q1->head = q1->head->next;
	   }
	   while(q2->head != NULL) {
		i2 = q2->head;
	        free((Patient*)i2->data);
		free(i2);
		q2->head = q2->head->next;
	   }
	   free(q1);
	   free(q2);
	   return;  
	}
    }
}
void setTime(Queue* q, int x)
{
      Patient* temp = NULL;
      Node* iterator = q->head;
      while(q->head != NULL) {
          temp = (Patient*)(q->head->data);
          if(strcmp(temp->z, "CV") == 0) {
              x = x + 5;
              temp->time = x;
          }
          if(strcmp(temp->z, "HN") == 0) {
              x = x + 3;
              temp->time = x;
          }
          if(strcmp(temp->z, "EV") == 0) {
              x = x + 10;
              temp->time = x;
          }
          if(strcmp(temp->z, "GI") == 0){
              x = x + 2;
              temp->time = x;
          }
          if(strcmp(temp->z, "MH") == 0) {
              x = x+5;
             temp->time = x;
          }
          if(strcmp(temp->z, "NC") == 0) {
              x = x+5;
              temp->time = x;
     	  }   
        
          if(strcmp(temp->z, "EC")==0) {
              x = x+1;
              temp->time = x;
          }
          if(strcmp(temp->z, "RC")==0) {
              x = x+1;
              temp->time = x;
          }
          if(strcmp(temp->z, "SK")==0){
              x = x+2;
              temp->time = x;
          }
          if(strcmp(temp->z, "SA")==0){
              x = x+7;
              temp->time = x;
          }
          if(strcmp(temp->z, "TR")==0) {
              x = x+4;
              temp->time = x;
          }
          x++;
          q->head = q->head->next;
      }
     q->head = iterator;
     return;
}

void getMatch(Queue* q1, Queue* q2)
 {
      Node* iterator1 = q1->head;
      Node* iterator2 = q2->head;
      Patient* temp1 = NULL;
      Patient* temp2 = NULL;
      while(q1->head != NULL){
          temp1 = (Patient*)q1->head->data;
          while(q2->head != NULL) {
             temp2 = (Patient*)q2->head->data;
             if(strcmp(temp1->x, temp2->x) == 0) {
                 temp2->time = temp1->time;
                 break;
             }
             q2->head = q2->head->next;
         }
         q1->head = q1->head->next;
         q2->head = iterator2;
     }
     q1->head = iterator1;
     q2->head = iterator2;
}
void addPatient(Queue* q1, Queue* q2)
{
    char x[10] = "\0";
    char y[10] = "\0";
    int z = 0;
    printf("Enter the Patient ID\n");
    fscanf(stdin, "%s", x);
    printf("Enter the priority number\n");
    fscanf(stdin, "%d", &z);
    printf("Enter the Symptom Code\n");
    fscanf(stdin, "%s", y);
    Node* n1 = NULL;
    Node* n2 = NULL;
    n1 = initializeNodeQ(initializePatient(x, &z, y));
    n2 = initializeNodeQ(initializePatient(x, &z, y));
    insertSortedQ(q1, n1);
    insertBackQ(q2, n2);
}
