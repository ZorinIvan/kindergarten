#ifndef _TEACH_H_
#define _TEACH_H_
#include "Person.H"
#include <string>
#include <iostream>

class Teacher : public Person{
public:
	Teacher(string name, int age, int seniority); /*Constructor*/
	int get_seniority() const;
	void print_teacher() const;
private:
	int seniority_;
};

#endif
