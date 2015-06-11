#include "Class.H"
#include "defs.H"
#include <iostream>

using std::cout;
using std::endl;

Class::Class(int room_number, int space, double child_teacher_max, int age_group, int max_child_num) : Room(room_number, space), child_teacher_max_(child_teacher_max), age_group_(age_group), max_child_num_(max_child_num)
{
	not_occupied(); /*The room will not be occupied*/
	vector<Child> child_vec_;
	vector<Teacher> teacher_vec;
}

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
		if (child_vec_[i].get_name() == childs_name)
			return child_vec_[i].get_phone();
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
		if (teacher_vec_[i].get_name() == teachers_name)
			return FAILURE;
	}
	teacher_vec_.push_back(new_teacher);
	return SUCCESS;
}

Result Class::add_child(string childs_name, string Prnts_phone_number, int age) /*Adding a new child*/
{
	if (teacher_vec_.size() == 0)
		return FAILURE; /*No teachers*/
	if (child_vec_.size() == max_child_num_) /*We surpass the max ammount of children*/
		return FAILURE;
	Child new_child(childs_name, age, Prnts_phone_number);
	if (((child_vec_.size() + 1) / teacher_vec_.size()) > child_teacher_max_) /*Dont surpass the maximum*/
		return FAILURE;
	for (int i = (child_vec_.size() - 1); i <= 0; i--) /*Go through the items in the vector and see if it exists already*/
	{
		if (teacher_vec_[i].get_name() == childs_name)
			return FAILURE;
	}
	child_vec_.push_back(new_child);
	return SUCCESS;
}

Result Class::remove_teacher(string teachers_name)
{
	if (teacher_vec_.size() == 0)
		return FAILURE; /*No teachers*/
	if ((child_vec_.size() / (teacher_vec_.size() - 1)) > child_teacher_max_) /*Dont surpass the maximum*/
		return FAILURE;
	for (int i = (teacher_vec_.size() - 1); i <= 0; i--) /*Search for the one we want to delete*/
	{
		if (teacher_vec_[i].get_name() == teachers_name)/*Found the teacher*/
		{
			teacher_vec_.erase(teacher_vec_.end() - 1 - i); /*We are deleting from the end*/ /*it returns the position of the past-the-end place*/
			return SUCCESS;
		}
	}
	return FAILURE; /*Teacher wasn't found*/
}

Result Class::remove_child(string childs_name)
{
	for (int i = (child_vec_.size() - 1); i <= 0; i--) /*Search for the one we want to delete*/
	{
		if (child_vec_[i].get_name() == childs_name)/*Found the child*/
		{
			child_vec_.erase(child_vec_.end() - 1 - i); /*We are deleting from the end*/ /*it returns the position of the past-the-end place*/
			return SUCCESS;
		}
	}
	return FAILURE; /*Child wasn't found*/
}

Result Class::sick_child(string childs_name)
{
	for (int i = (child_vec_.size() - 1); i <= 0; i--) /*Search for the one we want to set sick*/
	{
		if (child_vec_[i].get_name() == childs_name)/*Found the child*/
		{
			Result result = child_vec_[i].set_sick();/*We are deleting from the end*/ /*it returns the position of the past-the-end place*/
			return result;
		}
	}
	return FAILURE; /*Child not found*/
}