#ifndef _TEACH_H_
#define _TEACH_H_
#include "Person.H"
#include <string>
#include <iostream>

class Teacher : public Person{
public:
	Teacher(string name, unsigned int age, int seniority); /*Constructor*/
	unsigned int get_seniority() const;
	void print_teacher() const;
private:
	unsigned int seniority_;
};

#endif
