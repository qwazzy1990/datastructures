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
	if(a->age == b->age )
		return 0;
	else if( a->age < b->age )
		return -1;
	return 1;
}

