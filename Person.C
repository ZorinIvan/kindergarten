#include "Person.H"

using std::string;
using std::cout;
using std::endl;


Person::Person(string name, unsigned int age) : age_(age), name_(name) {}; /*Constructor*/

string Person::get_name() const /*Gives the person's name*/
{
	return name_;
}
unsigned int Person::get_age() const /*Gives the persons age*/
{
	return age_;
}

void Person::print_person() const
{
	cout << "Name : " << name_ << endl; /*Printing the info we need to print*/
	cout << "Age : " << age_ << endl;
}