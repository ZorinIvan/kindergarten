#include "Office.H"
#include "defs.H"
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::boolalpha;


Office::Office() : Room(1, 20), sick_child_name_("None"), busy_(false) /*Constructor*/
{
	is_occupied();
}

Result Office::add_new_class(int space, double child_teacher_max_ratio, int age_group, int max_child_num) /*Go through the items in the class vector*/
{
	for (int i = class_vec_.size() - 1; i >= 0; i++) /*Checking if a class with this age group already exists*/
	{
		if (class_vec_[i].get_age_group() == age_group) /*They are the same age group*/
			return FAILURE;
	}

	/*There is no class with this age group*/
	int room_num = class_vec_.size() + 2; /*The number of the new room will be*/
	Class new_class(room_num, space, child_teacher_max_ratio, age_group, max_child_num); /*Initializing the new class*/
	class_vec_.push_back(new_class); /*Inserting the new class*/
	return SUCCESS;
}

Result Office::add_new_child(string name, int age, string Prnts_phone)
{
	for (int i = class_vec_.size() - 1; i >= 0; i--) /*Looking for the right class*/
	{
		if (age == class_vec_[i].get_age_group()) /*Right age group*/
		{
			class_vec_[i].add_child(name, Prnts_phone, age);
			return SUCCESS;
		}
	}
	return FAILURE; /*Not found*/
}

Result Office::add_new_teacher(string name, int age, int seniority)
{
	int ratio_different; /*To know if all ratios are 0*/
	int least_teachers=9999; /*Number of teachers in the class with least teachers*/
	int least_teachers_index=9999; /*The class with the least teachers*/
	int max_ratio = 0; /*The class with the max ratio*/
	int max_ratio_index; /*The index of the class with the max ratio*/
	for (int i = class_vec_.size() - 1; i >= 0; i++) /*Going through the vector from the start to see if there is an empty class*/
	{
		if (class_vec_[i].get_teacher_num() == 0) /*Found a class with 0 teachers and 0 children*/
		{
			class_vec_[i].add_teacher(name, seniority, age); /*Adding the teacher*/
			class_vec_[i].is_occupied();
			return SUCCESS;
		}
		/*FOR THE SECOND SCENERIO CONDITION*/
		if (class_vec_[i].get_current_ratio() != 0) /*Meanwhile we want to remember if there is a class with a ratio different than 0*/
			ratio_different = class_vec_[i].get_current_ratio();
		/*FOR THE SECOND SCENERIO CONDITION*/

		/*FOR THE SECOND SCENERIO*/
		if (least_teachers > class_vec_[i].get_teacher_num()) /*We are finding the min number of teachers in a class, and making sure we save the first that was entered*/
		{
			least_teachers = class_vec_[i].get_teacher_num();
			least_teachers_index = i;
		}
		/*FOR THE SECOND SCENERIO*/

		/*FOR THE THIRD SCENERIO*/
		if (max_ratio < class_vec_[i].get_current_ratio())/*To remember the first class with the max stuend-teacher ratio*/
		{
			max_ratio = class_vec_[i].get_current_ratio();
			max_ratio_index = i;
		}

	}

	/*We saw that there is no classes with no teachers*/
	if (ratio_different == 0) /*We are going to give the teacher to the class with the lowest number of teachers*/
	{
		class_vec_[least_teachers_index].add_teacher(name, seniority, age); /*Adding the teacher*/
		return SUCCESS;
	}
	else
	{
		class_vec_[max_ratio_index].add_teacher(name, seniority, age); /*Adding the teacher*/
		return SUCCESS;
	}

	return FAILURE;
}

