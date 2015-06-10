#ifndef _PERSON_H_
#define _PERSON_H_
#include <string>
#include <iostream>

using std::string;

class Person {
public:
	Person(string name,int age); /*Constructor*/
	string get_name() const; /*Gives the name of the person*/
	int get_age() const; /*Gives the age of the person*/
	void print_person() const; /*Prints info a about the person as asked*/
protected:
	string name_;
	int age_;
};

#endif
