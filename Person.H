#ifndef _PERSON_H_
#define _PERSON_H_
#include <string>
#include <iostream>

using std::string;

class Person {
public:
	//********************************************************************
	//* Function name: Person
	//* Description: Constructor function
	//* Parameters: name, age - used to create a person (specificly Child and Teacher)
	//* Return value: none
	//********************************************************************
	Person(string name,int age); /*Constructor*/


	//********************************************************************
	//* Function name: get_name
	//* Description: returns the name of the person
	//* Parameters: none - internal method
	//* Return value: the name of this person
	//********************************************************************
	string get_name() const; /*Gives the name of the person*/


	//********************************************************************
	//* Function name: get_age
	//* Description: returns the age of this person
	//* Parameters: none - internal method
	//* Return value: int - the age of the person
	//********************************************************************
	int get_age() const; /*Gives the age of the person*/


	//********************************************************************
	//* Function name: print_person
	//* Description: prints the info we need about this person
	//* Parameters: none - internal method
	//* Return value: void
	//********************************************************************
	void print_person() const; /*Prints info a about the person as asked*/

protected:
	string name_;
	int age_;
};

#endif
