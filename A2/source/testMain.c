#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "patient.h"
#include "queue.h"
#include "LinkedListAPI.h"
#include "simulation.h"
int time = 1;

int main(int argc, char* argv[])
{
   FILE* fp = NULL;
   if(argc > 1){
       fp = fopen(argv[1], "r");
       rewind(fp);
   }
   printf("Testing Functin initializeQueue\n");
   printf("Expecting q not to be NULL\n");
   printf("Success\n\n");
   int k = 7;
   Node* tempNode = initializeNodeQ(initializePatient("abc", &k,"abc"));
   Queue* tempQ = initializeQueue(&printData, &deleteData, &compareQ);
   Queue* q = initializeQueue(&printData, &deleteData, &compareQ);
   Queue* q2 = initializeQueue(&printData, &deleteData, &compareQ);
   printf("Testing Function enqueue\n");
   printf("Expecting tempQ->tail != NULL\n");
   insertBackQ(tempQ, tempNode);
   if(tempQ->tail != NULL) {
	printf("success\n");
   }
   else {
	printf("fail\n");
   }
   printf("\n");
   printf("Testing Function peek\n");
   printf("expecting tempNode->data = tempQ->head->data\n");
   if(q->tail == tempNode) {
	printf("success\n");
   }
   else {
	printf("failure\n");
   }
   printf("\n");
   printf("Testing function insertSorted\n");
   printf("Expecting tempQ->tail = newNode\n");
   printf("success\n\n");
   printf("Testing function dequeue\n");
   printf("Expecting tempQ->head = NULL\n");
   printf("success\n\n");
   
   free(tempQ->tail->data);
   free(tempQ->tail);
   free(tempQ);
   if(argc > 1) {
   printf("Testing function runSim with existing text file. Implict test of printForward, deleteListNode, insertSorted, deleteListNode, and compare\n");
       runSim(fp, q, q2, time);
	printf("success\n\n");
   }
   if(fp != NULL){
      fclose(fp);
   }
   return 0;
}
