#include "Child.H"

using std::cout;
using std::endl;
using std::boolalpha;

Child::Child(string name, int age, string phone_number) : Person(name, age), Prnts_phone_number_(phone_number), sick_(false) {}; /*Child constructor*/

string Child::get_phone() const /*Returns the perants phone number*/
{
	return Prnts_phone_number_;
}

Result Child::set_sick() /*Change child's sick status*/
{
	if (sick_ == true) /*The child is already sick*/
		return FAILURE;
	else{ /*The child isn't sick*/
		sick_ = true;
		return SUCCESS;
	}
}

void Child::set_phone(string phone_number) /*Updating the current phone number*/
{
	Prnts_phone_number_ = phone_number;
}

void Child::print_child() const
{
	print_person(); /*First we print the Person info*/
	cout << "Parant's Phone : " << Prnts_phone_number_ << endl; /*Then all of the rest*/
	cout << "Is sick : " << std::boolalpha << sick_ << endl;
}
