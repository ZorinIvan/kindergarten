#ifndef _CLASS_H_
#define _CLASS_H_

#include <string>
#include <iostream>
#include <vector>
#include "defs.H"
#include "Room.H"
#include "Child.H"
#include "Teacher.H"

using std::string;
using std::vector;

class Class : public Room{
public:
	//********************************************************************
	//* Function name: Class
	//* Description: Constructor function - creates the class
	//* Parameters: room_number, the space (the field of the room), child_teacher_max - the maximal ratio of children to teachers, age group - the age group of the class, max_child_num - max number of children allowed
	//* Return value: none - Constructor
	//********************************************************************
	Class(int room_number, int space, double child_teacher_max, int age_group, int max_child_num); /*Constructor*/


	//********************************************************************
	//* Function name: get_teacher_num
	//* Description: returns the ammount of teachers in the class
	//* Parameters: none - inside the class method
	//* Return value: int - the number of teachers
	//********************************************************************
	int get_teacher_num() const; /*returns number of teachers in this class*/


	//********************************************************************
	//* Function name: get_age_group
	//* Description: returns the age group of this class
	//* Parameters: none - inside the class method
	//* Return value: int - the ammount of teachers in this class
	//********************************************************************
	int get_age_group() const; /*Class age group*/


	//********************************************************************
	//* Function name: get_current_ratio
	//* Description: returns children to teachers ratio
	//* Parameters: none - internal method
	//* Return value: double - the ratio
	//********************************************************************
	double get_current_ratio() const; /*Current ratios of children to teachers*/


	//********************************************************************
	//* Function name: get_child_number
	//* Description: searches through the children and returns the number of the child with the name we inserted
	//* Parameters: the name of the child
	//* Return value: the number of the perants of the child we were looking after
	//********************************************************************
	string get_child_number(string childs_name) const; /*returns child's parents phone number*/


	//********************************************************************
	//* Function name: print_class
	//* Description: prints all of the info we need about the current class object
	//* Parameters: none - internal method - works on the current object
	//* Return value: void
	//********************************************************************
	void print_class() const;


	//********************************************************************
	//* Function name: add_teacher
	//* Description: tries to add a teacher to the class. returns the result of the attempt
	//* Parameters: teachers_name - the name of the teacher, seniority - his seniority, and his age
	//* Return value: Result
	//********************************************************************
	Result add_teacher(string teachers_name, int seniority , int age);


	//********************************************************************
	//* Function name: add_child
	//* Description: tries to add a child
	//* Parameters: name, perants phone number, and age
	//* Return value: Result of the attempt
	//********************************************************************
	Result add_child(string childs_name, string Prnts_phone_number, int age);


	//********************************************************************
	//* Function name: remove_teacher
	//* Description: tries to remove a teacher with the given name
	//* Parameters: teachers_name - the name of the teacher we want to remove
	//* Return value: Result of the attempt
	//********************************************************************
	Result remove_teacher(string teachers_name);


	//********************************************************************
	//* Function name: remove_child
	//* Description: tries to remove a child from this class
	//* Parameters: name - the name of the child we want to remove from this class
	//* Return value: Result of the attempt
	//********************************************************************
	Result remove_child(string childs_name);


	//********************************************************************
	//* Function name: sick_child
	//* Description: sets the status of a child as sick
	//* Parameters: childs_name - the name of the child
	//* Return value: Result of the attempt - will fail if he is already marked as sick
	//********************************************************************
	Result sick_child(string childs_name);

  	
private:
	double child_teacher_max_;
	int age_group_;
	int max_child_num_;
	vector<Child> child_vec_; /*Create a child vector*/
	vector<Teacher> teacher_vec_; /*Create a teacher vector*/
};

#endif
