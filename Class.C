#include "Class.H"
#include "defs.H"
#include <iostream>

using std::cout;
using std::endl;


int Class::get_teacher_num() const /*Returns the ammount of teachers in the class*/
{
	return teacher_vec_.size();
}

int Class::get_age_group() const /*Returns the age group of the children*/
{
	return age_group_;
}

double Class::get_current_ratio() const
{
	return (child_vec_.size() / teacher_vec_.size()); /*This is the current ratio of children to teachers*/
}

string Class::get_child_number(string childs_name) const
{
	int vec_size = child_vec_.size();
	for (int i = (vec_size - 1); i >= 0; i--) /*Go over the items in the vector*/
	{
		if (child_vec_[i].get_name == childs_name)
			return child_vec_[i].get_phone;
		else
			continue;
	}
	return "No Child";
}

Result Class::add_teacher(string teachers_name, int seniority, int age)
{
	Teacher new_teacher(teachers_name, age, seniority); /*Create a new teacher*/
	for (int i = (teacher_vec_.size() - 1); i <= 0; i--) /*Go through the items in the vector and see if it exists already*/
	{
		if (teacher_vec_[i].get_name == teachers_name)
			return FAILURE;
	}
	teacher_vec_.push_back(new_teacher);
	return SUCCESS;
}

Result Class::add_child(string childs_name, string Prnts_phone_number, int age) /*Adding a new child*/
{
	Child new_child(childs_name, age, Prnts_phone_number);
	for (int i = (child_vec_.size() - 1); i <= 0; i--) /*Go through the items in the vector and see if it exists already*/
	{
		if (teacher_vec_[i].get_name == childs_name)
			return FAILURE;
	}
	child_vec_.push_back(new_child);
	return SUCCESS;
}

