#include "roster.h"
using namespace std;

int main()
{
	/*Print course title, programming language used, WGU student ID, and name*/

	cout << "------------------------------------------------------" << endl;
	cout << "Welcome to my student roster project!" << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "I have been programming this for about 72 hours straight :)" << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "My wife is wondering what is so complicated about printing out some students :)" << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "Course title: C867 - Scripting & Programming" << endl;
	cout << "Programming language used : C++" << endl;
	cout << "WGU Student ID: 001305503" << endl;
	cout << "Student Name: Jeremy Allen" << endl;
	cout << "------------------------------------------------------" << endl << endl;

	/*Requirement A. modified the studentData table to include my personal information as the last item*/
	const int numStudents = 5;
	const string studentData[numStudents] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Jeremy,Allen,jeremyallencpa@gmail.com,29,10,20,30,SOFTWARE"
	};

	Roster roster;

	for (int i = 0; i < numStudents; i++) roster.parseStudentStrings(studentData[i]);
	cout << "Displaying all students :" << std::endl;
	cout << "------------------------------------------------------" << endl << endl;
	roster.printAll();
	cout << std::endl;

	cout << "Displaying students with invalid emails:" << std::endl;
	cout << "------------------------------------------------------" << endl << endl;
	roster.printInvalidEmails();
	cout << std::endl;

	cout << "Displaying average days in class: " << std::endl;
	cout << "------------------------------------------------------" << endl << endl;
	roster.printAverageDaysInClass();

	cout << "Displaying by student type: " << degreeProgramStringFormat[2] << std::endl;
	cout << "------------------------------------------------------" << endl << endl;
	roster.printByDegreeProgram((DegreeProgram::SOFTWARE));
	

	/*for (int i = 0; i < 3; i++)
	{
		cout << "Displaying by student type: " << degreeProgramStringFormat[i] << std::endl;
		cout << "------------------------------------------------------" << endl << endl;
		roster.printByDegreeProgram((DegreeProgram)i);
	}*/


	cout << "Removing student with ID A3: " << std::endl;
	cout << "------------------------------------------------------" << endl << endl;
	roster.removeStudentByStudentID("A3");
	cout << std::endl;

	cout << "Removing student with ID A3" << std::endl;
	cout << "------------------------------------------------------" << endl << endl;
	roster.removeStudentByStudentID("A3");
	cout << std::endl;

	system("pause");
	return 0;

}