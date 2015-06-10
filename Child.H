#ifndef _CHILD_H_
#define _CHILD_H_
#include "Person.H"
#include "defs.H"
#include <string>
#include <iostream>

using std::string;

class Child : public Person {
public:
	Child(string name, unsigned int age, string phone_number); /*Cpnstructor*/
	string get_phone() const; /*Takes phone number*/
	void set_phone(string phone_number); /*Sets phone number*/
	Result set_sick();
	void print_child() const;
private:
	string Prnts_phone_number_;
	bool sick_;
};

#endif
