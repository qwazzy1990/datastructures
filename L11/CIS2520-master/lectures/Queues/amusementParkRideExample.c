/**
 * Example from the amusement part ride
 * Priority Queue
 * Note: The Priority Queue API does not exactly match
 *      the expectations of this course. Its used to demonstrate problem solving
 *      and core API operations.
 */
#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"

int main( int argc, char ** argv )
{
    // Adventure Ride - Priority Queue Example
    int exampleData[] = {3,3,5,10,11};
    int timer=0;
    printf("START\n");
    int input;

    // Initialize a priority queue.
    // Will be different for your initialization
    // Since you will have function pointers.
    PriorityQueue pq = initializePriorityQueue();

    // Load our example data 
    for( int i =0; i<5; i++)
        insert(pq,exampleData[i]);      
 
       
    printf("Initial Example Data\n");
    pq = printQueue(pq);
    
    while(!isEmpty(pq))
    {
        // Read input from the user and insert into priority queue
        printf("Press -1 to continue or press N>=0 to add passenger\n");
        while(scanf("%d",&input) == 1 && input >= 0)
        {
            printf("Adding priority passenger %d\n", input);
            insert(pq,input);
        }
        // Check we still have passengers
        // If it's been 4 seconds then ride goes again.
        if( !isEmpty(pq) && timer%4 == 0 )
        {
            // Read the first rider and then pop
            int top = peek(pq);
            pop(pq);
            

            // Read the 2nd rider if they exist
            int nextTop = -1;
            if(!isEmpty(pq)) {
                nextTop = peek(pq);
                pop(pq);
            }
            // Print the two riders that left 
            printf("The follow are on the ride %d %d\n",top, nextTop );
        }
        
        timer++;
    }
        
    printf("ALL DONE\n");
    return 0;
}