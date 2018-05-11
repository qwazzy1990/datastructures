#include "person.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printPerson( Person * p )
{
	printf("Hello my name is %s\n", p->name);
	printf("I'm %d year(s) old.\n", p->age);
}

void addBirthday( Person * p)
{
	p->age++;
}

int compareAges( const Person * a, const Person * b )
{
	if( a == NULL && b == NULL)
		return 0;
	else if( a == NULL)
		return 1;
	else if(b  == NULL)
		return -1;
		
	if( a->age == b->age)
		return 0;

	// If age of a  is less than age of b
	// 	 return -1
	// else
	//  	return 1
	return a->age < b->age ? -1 : 1;
}

