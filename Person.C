#include "Person.H"

using std::string;
using std::cout;
using std::endl;


Person::Person(string name, int age) : name_(name), age_(age){}; /*Constructor*/

string Person::get_name() const /*Gives the person's name*/
{
	return name_;
}
int Person::get_age() const /*Gives the persons age*/
{
	return age_;
}

void Person::print_person() const
{
	cout << "Name : " << name_ << endl; /*Printing the info we need to print*/
	cout << "Age : " << age_ << endl;
}