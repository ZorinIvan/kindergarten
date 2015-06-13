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
	Office();
	Result add_new_class(int space, double child_teacher_max_ratio, int age_group, int max_child_num);
	Result add_new_child(string name, int age, string Prnts_phone);
	Result add_new_teacher(string name, int age, int seniority);
	Result remove_child(string name);
	Result remove_teacher(string name);
	Result remove_class(int age_group);
	Result reporting_sick_child(string name);
	void print_office();
private:
	string sick_child_name_;
	bool busy_;
	vector<Class> class_vec_;
};

#endif
