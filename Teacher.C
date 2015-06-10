#include "Teacher.H"
using std::string;
using std::cout;
using std::endl;

Teacher::Teacher(string name, int age, int seniority) : Person(name, age), seniority_(seniority) {}; /*Constructor*/

int Teacher::get_seniority() const
{
	return seniority_;
}

void Teacher::print_teacher() const /*Printing the rest of the info we need*/
{
	print_person();
	cout << "Seniority : " << seniority_ << endl;
}
