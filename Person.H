#ifndef _PERSON_H_
#define _PERSON_H_
#include <string>
#include <iostream>

using std::string;


class Person {
public:
	Person(int age, string name); /*Constructor*/
	string get_name() const; /*Gives the name of the person*/
	int get_age() const; /*Gives the age of the person*/
	void print_person() const; /*Prints info a about the person as asked*/
protected:
	int age_;
	string name_;
};

#endif
