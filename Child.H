#ifndef _CHILD_H_
#define _CHILD_H_
#include "Person.H"
#include "defs.H"
#include <string>
#include <iostream>

using std::string;

class Child : public Person {
public:

	//********************************************************************
	//* Function name: Child
	//* Description: Constructor function
	//* Parameters: name, age, phone_number
	//* Return value: none
	//********************************************************************
	Child(string name, int age, string phone_number); /*Cpnstructor*/


	//********************************************************************
	//* Function name: get_phone
	//* Description: returns the phone number of the perants
	//* Parameters: none - it is a method inside of the function
	//* Return value: string
	//********************************************************************
	string get_phone() const; /*Takes phone number*/


	//********************************************************************
	//* Function name: set_phone
	//* Description: sets the phone number of the student
	//* Parameters: phone number
	//* Return value: void
	//********************************************************************
	void set_phone(string phone_number); /*Sets phone number*/


	//********************************************************************
	//* Function name: set_sick
	//* Description: sets the child's status as sick.
	//* Parameters: none - inside the class method
	//* Return value: Result - will fail if already sick
	//********************************************************************
	Result set_sick();


	//********************************************************************
	//* Function name: print_child
	//* Description: prints all the info we need to know about the child
	//* Parameters: none - inside the function method
	//* Return value: void
	//********************************************************************
	void print_child() const;


private:
	string Prnts_phone_number_;
	bool sick_;
};

#endif
