#include "person.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printPerson( Person * p )
{
	printf("Hello my name is %s", p->name);
	printf("I'm %d year(s) old.", p->age);
}

void addBirthday( Person * p)
{
	p->age++;
}

int compareAges( const Person * a, const Person * b )
{
	return a->age < b->age;
}

