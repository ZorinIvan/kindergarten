#include "Office.H"
#include "Class.H"
#include "Child.H"
#include "Teacher.H"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::istringstream;

//////////////////////////////////////
//////////////////////////////////////

int stringToInt(const string s) {
  istringstream istr(s);
  int i = 0;
  istr >> i;
  return i;
}

double stringToDouble(const string s1,const string s2) {
  
  istringstream istr1(s1);
  istringstream istr2(s2);
  int i; //integer part
  int j; //fraction part
  double a = 0;
  istr1 >> i;
  istr2 >> j;
  a = double(i)+double(j)/1000; //assuming fraction part is alwways 3 digits
  return a;
}

vector<string> tokenize(string line, const char* delim) {
	unsigned int i, j; 
	vector<string> tokens;
	while (!line.empty()) {
		i = line.find_first_not_of(delim);
		j = line.find_first_of(delim, i+1);
		tokens.push_back(line.substr(i, j-i));
		if (j > line.size()-1)
			line = "";
		else
			line = line.substr(j+1,line.size()-j-1);
	}
	return tokens;
}

int main() {

	Office KG_Office; //KinderGarten Office
	const char* delims = " \t\n";
	vector<string> tokens;
	string line;
	unsigned int lineNumber = 1;

	while (!cin.eof()) {
	  getline(cin, line);
	  tokens = tokenize(line, delims);
	  if (tokens.size() == 0) { //empty line
	    continue;
	  }

	  if (tokens[0] == "addClass") {

		  vector<string> token_ratio = tokenize(tokens[2], ".");
		  int size, max_num_children, children_age;
		  double ratio;


		  if (tokens.size() != 5){
			  cerr << "Failed - " << line << endl;
			  continue;
		  }

		  size=stringToInt(tokens[1]);
		  ratio=stringToDouble(token_ratio[0],token_ratio[1]);
		  max_num_children=stringToInt(tokens[3]);
		  children_age=stringToInt(tokens[4]);



		  if(KG_Office.add_new_class(size, ratio, children_age, max_num_children)==FAILURE){
			  cerr << "Failed - " << line << endl;
			  continue;
		  }

	  } //  if (tokens[0] == "addClass")


	  if (tokens[0] == "removeClass") {

		  if (tokens.size() != 2){
			  cerr << "Failed - " << line << endl;
			  continue;
		  }

		  int age=stringToInt(tokens[1]);

		  if(KG_Office.remove_class(age)==FAILURE){
			  cerr << "Failed - " << line << endl;
			  continue;
		  }
	  }//if (tokens[0] == "removeClass")


	  if (tokens[0] == "addChild") {
		  if (tokens.size() != 4){
			  cerr << "Failed - " << line << endl;
			  continue;
		  }

		  int age=stringToInt(tokens[1]);
		  if(KG_Office.add_new_child(tokens[2], age, tokens[3])==FAILURE){
				  cerr << "Failed - " << line << endl;
				  continue;
		  }

	  }//if (tokens[0] == "addChild")
	  
	  if (tokens[0] == "addTeacher") {
		 if (tokens.size() != 4){
			 cerr << "Failed - " << line << endl;
		  	 continue;
		  }

		 int age, seniority;
		 age=stringToInt(tokens[1]);
		 seniority=stringToInt(tokens[3]);

		 if(KG_Office.add_new_teacher(tokens[2], age, seniority)==FAILURE){
			cerr << "Failed - " << line << endl;
			continue;
		 }

	  }//if (tokens[0] == "addTeacher")
	  
	  if (tokens[0] == "removeChild") {
		  if (tokens.size() != 2){
			  cerr << "Failed - " << line << endl;
			  continue;
		  }

		  if(KG_Office.remove_child(tokens[1])==FAILURE){
			  cerr << "Failed - " << line << endl;
			  continue;
		  }

	  }//  if (tokens[0] == "removeChild")
	  
	  if (tokens[0] == "removeTeacher") {
		  if (tokens.size() != 2){
			  cerr << "Failed - " << line << endl;
			  continue;
		  }

		  if(KG_Office.remove_teacher(tokens[1])==FAILURE){
			  cerr << "Failed - " << line << endl;
			  continue;
		  }

	  }// if (tokens[0] == "removeTeacher")
	  
	  if (tokens[0] == "PrintKindergarten") {
		  if (tokens.size() != 1){
			  cerr << "Failed - " << line << endl;
			  continue;
		  }

		  KG_Office.print_office();
	  }//if (tokens[0] == "PrintKindergarten")
	  
	  if (tokens[0] == "sickChild") {
		  if (tokens.size() != 2){
			  cerr << "Failed - " << line << endl;
			  continue;
		  }

		  if(KG_Office.reporting_sick_child(tokens[1])==FAILURE){
			  cerr << "Failed - " << line << endl;
			  continue;
		  }
	  }//if (tokens[0] == "sickChild")
	  
	  lineNumber++;
	}
	return 0; 
};
