#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"person.h"

int main( int argc, char ** argv )
{
	printf("STARTING THE MAIN\n");

	// Create first person
	Person * p = (Person*)malloc(sizeof(Person));
	strncpy(p->name, "Donald Duck", 30);
	p->age = 100;
	printPerson( p );

	// Create a second person
	Person * a = (Person*) malloc(sizeof(Person));
	a->age = 100;
	strncpy(a->name, "Daisy", 30);
	addBirthday( a );
	printPerson(a);

	// Compare ages and indicate who is older.
	int diff = compareAges(a,p);
	printf("\nThe value of diff is %d\n\n", diff);

	if(diff == 0 )
		printf("They are the same age.\n");
	else if(diff == 1 )
		printf( "%s is older.\n", a->name);
	else
		printf( "%s is older.\n", p->name);
	
	return 0;
}
