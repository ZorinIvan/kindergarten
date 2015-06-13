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
	Class(int room_number, int space, double child_teacher_max, int age_group, int max_child_num); /*Constructor*/

	int get_teacher_num() const; /*returns number of teachers in this class*/
	int get_age_group() const; /*Class age group*/
	double get_current_ratio() const; /*Current ratios of children to teachers*/
	string get_child_number(string childs_name) const; /*returns child's parents phone number*/
	void print_class() const;

	Result add_teacher(string teachers_name, int seniority , int age);
	Result add_child(string childs_name, string Prnts_phone_number, int age);
	Result remove_teacher(string teachers_name);
	Result remove_child(string childs_name);
	Result sick_child(string childs_name);

  	
private:
	double child_teacher_max_;
	int age_group_;
	int max_child_num_;
	vector<Child> child_vec_; /*Create a child vector*/
	vector<Teacher> teacher_vec_; /*Create a teacher vector*/
};

#endif
