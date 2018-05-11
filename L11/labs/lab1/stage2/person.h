#ifndef PERSON_H
#define PERSON_H

/*
	A Structure that holds age and name information about a person.
*/
typedef struct person
{
	int age;
	char name[30];
} Person;

/*
  Dipslay person information to the console
  Pre: Provided a pointer to a person.
  Post: The persons age and name are printed to the console.
*/
void printPerson( Person * p );

/*
  Add a year to a person's age 
  Pre: Provided a pointer to a person.
  Post: Person is 1 year older in age.
*/
void addBirthday( Person * p);

/*
  Compares two people's ages 
  Pre: two people  
  Post:
  	-1 Person a is younger
	 0 Person a and b are the same age.
	 1 Person be is younger
*/
int compareAges( const Person * a, const Person * b);


#endif
