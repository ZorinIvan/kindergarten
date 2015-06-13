#ifndef _OFFICE_H_
#define _OFFICE_H_

#include <string>
#include <vector>

#include "Room.H"
#include "defs.H"
#include "Class.H"

using std::string;
using std::vector;

class Office : public Room {
public:
	//********************************************************************
	//* Function name: Office
	//* Description: Constructor function
	//* Parameters: none - we have set parameters for the office
	//* Return value: none
	//********************************************************************
	Office();


	//********************************************************************
	//* Function name: add_new_class
	//* Description: creates a new class
	//* Parameters: space - the space inside the class, child_teacher_max_ratio - the max ratio of children to teachers allowed in this class, age_group - the age group in this class, max_child_num - the max number of children allowed inside this class
	//* Return value: Result of the creation attempt
	//********************************************************************
	Result add_new_class(int space, double child_teacher_max_ratio, int age_group, int max_child_num);


	//********************************************************************
	//* Function name: add_new_child
	//* Description: attempts to add a new child to a fitting class for his age
	//* Parameters: name, age and Prnts_phone - the phone number of his parents
	//* Return value: Result - the result of the attempt
	//********************************************************************
	Result add_new_child(string name, int age, string Prnts_phone);


	//********************************************************************
	//* Function name: add_new_teacher
	//* Description: attempts to add a new teacher to a fitting class by the rules given to us
	//* Parameters: name - the name of the teacher, age - her age, seniority - her seniority
	//* Return value: Result of the attempt
	//********************************************************************
	Result add_new_teacher(string name, int age, int seniority);


	//********************************************************************
	//* Function name: remove_child
	//* Description: attempts to remove a child with the name inserted
	//* Parameters: name - the name of the child we want to remove
	//* Return value: result of the attempt
	//********************************************************************
	Result remove_child(string name);


	//********************************************************************
	//* Function name: remove_teacher
	//* Description: attempts to find a teacher with this name and remove him 
	//* Parameters: name - the name of the teacher we want to remove
	//* Return value: result of the attempt
	//********************************************************************
	Result remove_teacher(string name);


	//********************************************************************
	//* Function name: remove_class
	//* Description: attempts to remove a class
	//* Parameters: age group - the age group of the class we want to remove
	//* Return value: result of the attempt
	//********************************************************************
	Result remove_class(int age_group);


	//********************************************************************
	//* Function name: reporting_sick_child
	//* Description: attempts to report the child with the name inserted sick, and report the office as busy as of this moment untill he is removed
	//* Parameters: name - the name of the child we want to report as sick
	//* Return value: result of the attempt
	//********************************************************************
	Result reporting_sick_child(string name);


	//********************************************************************
	//* Function name: print_office
	//* Description: attempts to print the office and all of the information about the classes and the teachers and the children as needed
	//* Parameters: none - internal method
	//* Return value: void
	//********************************************************************
	void print_office();


private:
	string sick_child_name_;
	bool busy_;
	vector<Class> class_vec_;
};

#endif
