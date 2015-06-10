#include "Teacher.H"
using std::string;
using std::cout;
using std::endl;

Teacher::Teacher(string name, unsigned int age, int seniority) : Person(name, age), seniority_(seniority) {}; /*Constructor*/

unsigned int Teacher::get_seniority() const
{
	return seniority_;
}

void Teacher::print_teacher() const /*Printing the rest of the info we need*/
{
	print_person();
	cout << "Seniority : " << seniority_ << endl;
}
