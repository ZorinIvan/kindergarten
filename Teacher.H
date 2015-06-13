#ifndef _TEACH_H_
#define _TEACH_H_
#include "Person.H"
#include <string>
#include <iostream>

class Teacher : public Person{
public:
	//********************************************************************
	//* Function name: Teacher
	//* Description: Constructor function
	//* Parameters: name, age, seniority
	//* Return value: none
	//********************************************************************
	Teacher(string name, int age, int seniority); /*Constructor*/


	//********************************************************************
	//* Function name: get_seniority
	//* Description: returns the seniority of this teacher
	//* Parameters: none - internal method
	//* Return value: int - the seniority
	//********************************************************************
	int get_seniority() const;


	//********************************************************************
	//* Function name: print_teacher
	//* Description: prints all the information about the teacher
	//* Parameters: none - internal method
	//* Return value: void
	//********************************************************************
	void print_teacher() const;

private:
	int seniority_;
};

#endif
