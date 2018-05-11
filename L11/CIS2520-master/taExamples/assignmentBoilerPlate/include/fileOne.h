/***
* Name: Foo Bar
* Student Number: 0123456
*
* File: fileOne.h
* Description: The functions used in fileOne.c and contains the student info data structure.
* Date Created: October 2017
**/


/* Included libraries */

#include<stdio.h>



/* Self defined data structure typedefs */

typedef struct studentNode Student;


/* Data structure members defined */

struct studentNode {
	char *name;
	char *studentNumber;

	Student *next;
};



/* Function prototypes */


/***
* @brief Simple print function to show where the function is called from.
*
* @param No parameters required
*
* @return The return is void.
***/

void fromFileOne();

