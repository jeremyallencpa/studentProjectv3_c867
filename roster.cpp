#pragma once
#include <iomanip>
#include "roster.h"

/*Create function to parse out students from out student data in the main function.*/

void Roster::parseStudentStrings(string studentdata)
{
/*We will start by searching in student data to find a comma delimiter since our data is
comma delimited. This will be set to an unsigned integer variable (type size_t) called
rightEdge which will hold the position of the comma found in our string.*/

	size_t rightEdge = studentdata.find(",");

/*We will then set studentID variable equal to the string that lies between the start
position of 0 of the object in the array and ends right before rightEdge where our comma
is. This will create a string of the studentID.*/

	string studentID = studentdata.substr(0, rightEdge);

/*Now we want to create another unsigned integer variable that will be our left hand
side of the next string we have. The start position is one after the comma which is
what we want.*/

	size_t leftEdge = rightEdge + 1;

/*Now we will set a new right edge where we are searching for a comma starting at
the current left edge (remember, this is one after the first comma we found.*/

	rightEdge = studentdata.find(",", leftEdge);

/*Now we will set this new substring which is between our new left edge and goes for a
length of our new right edge minus our new left edge. We will repeat this process for
each of our variables that we need to add to our student object.*/

	string firstName = studentdata.substr(leftEdge, rightEdge - leftEdge);

/*Same process as above to find last name.*/
	leftEdge = rightEdge + 1;
	rightEdge = studentdata.find(",", leftEdge);
	string lastName = studentdata.substr(leftEdge, rightEdge - leftEdge);

/*Same process as above to find email address.*/

	leftEdge = rightEdge + 1;
	rightEdge = studentdata.find(",", leftEdge);
	string emailAddress = studentdata.substr(leftEdge, rightEdge - leftEdge);

/*Same process as above to find age with one difference. Because our array of student
data is of type string, we need to use the 'stoi' modifier so that we can modify our
data from type string to type int as this is the data type of our age variable.*/

	leftEdge = rightEdge + 1;
	rightEdge = studentdata.find(",", leftEdge);
	int age = stoi(studentdata.substr(leftEdge, rightEdge - leftEdge));

/*Same process as above to find days in class with one difference. Because our array of student
data is of type string, we need to use the 'stod' modifier so that we can modify our
data from type string to type double as this is the data type of our days in class variable.*/


	leftEdge = rightEdge + 1;
	rightEdge = studentdata.find(",", leftEdge);
	double daysInClass1 = stod(studentdata.substr(leftEdge, rightEdge - leftEdge));/*first days in class*/
	leftEdge = rightEdge + 1;
	rightEdge = studentdata.find(",", leftEdge);
	double daysInClass2 = stod(studentdata.substr(leftEdge, rightEdge - leftEdge));/*second days in class*/
	leftEdge = rightEdge + 1;
	rightEdge = studentdata.find(",", leftEdge);
	double daysInClass3 = stod(studentdata.substr(leftEdge, rightEdge - leftEdge));/*third days in class*/
	leftEdge = rightEdge + 1;
	rightEdge = studentdata.find(",", leftEdge);

/*This one is a bit different of a process. Because our degree program is an enumerated data type
we cannot pass its value in as a string which is the data type that will be found using the find method.
Therefore, we have to create a new variable (called 'degreeString') which will hold the value
of the string that we find. Based on the value of the string that we find, we will then use
an if/else structure to set the string the degree program type using the enumerated data type.
If we pass this in as string to the enumerated degree data type we'll get a bunch of errors because it
can't convert the data type. Trust me...took me a long time to figure that one out.*/

	DegreeProgram degreeProgram;
	{string degreeString = studentdata.substr(leftEdge, studentdata.length() - leftEdge);
	if (degreeString == "NETWORK") { degreeProgram = DegreeProgram::NETWORK; }
	else if(degreeString == "SECURITY") { degreeProgram = DegreeProgram::SECURITY; }
	else if (degreeString == "SOFTWARE") { degreeProgram = DegreeProgram::SOFTWARE; }
	}

/*Now that we have set all of our variables, lets pass those into our add method from the roster class.*/

	add(studentID, firstName, lastName, emailAddress, age, daysInClass1, daysInClass2, daysInClass3, degreeProgram);
}

/*Now we need to create an add method which will take our list of days in class that we individually parsed
out and add those to an array. We need to do this because the student function takes in an array of doubles.*/

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, double daysInClass1, double daysInClass2, double daysInClass3, DegreeProgram degreeProgram)
{
/*Put days into array for constructor for student objects.*/

	double daysInClassArray[3] = { daysInClass1,daysInClass2,daysInClass3 };
/*Make student object, last index starts at -1 for our looping.*/

	classRosterArray[++indexForArray] = new Student(studentID, firstName, lastName, emailAddress, age, daysInClassArray, degreeProgram);
}

/*Display all students using tab separated output and identifiers. This function takes each item
from classRosterArray and passes it into the print function from the student class.*/

void Roster::printAll()
{
	for (int i = 0; i <= Roster::indexForArray; i++)
	{
		classRosterArray[i]->print();
	}
}

/*Display students by degree type.*/

void Roster::printByDegreeProgram(DegreeProgram dp)
{
	for (int i = 0; i <= Roster::indexForArray; i++) {
		if (Roster::classRosterArray[i]->getDegreeType() == dp) classRosterArray[i]->print();
	}
	cout << std::endl;
}

/*Check emails for validity.*/

void Roster::printInvalidEmails()
{
	bool invalidCharacter = false;
	for (int i = 0; i <= Roster::indexForArray; i++)
	{
		string emailAddress = (classRosterArray[i]->getEmailAddress());
		if (emailAddress.find('@') == string::npos || emailAddress.find('.') == string::npos || emailAddress.find(' ') != string::npos)
		{
			invalidCharacter = true;
			cout << emailAddress << ":" << classRosterArray[i]->getEmailAddress() << std::endl;
		}
		if (!invalidCharacter) cout << "None" << std::endl;
	}
}
/*Print average days in class.*/

void Roster::printAverageDaysInClass()
{
	for (int i = 0; i <= Roster::indexForArray; i++) 
	{
		cout << classRosterArray[i]->getStudentID() << ": ";
		cout << (classRosterArray[i]->getDaysInClass()[0]
			+ classRosterArray[i]->getDaysInClass()[1]
			+ classRosterArray[i]->getDaysInClass()[2]) / 3.0 << std::endl;
	}
	cout << std::endl;
}

/*Remove student by student ID.*/

void Roster::removeStudentByStudentID(string studentID)
{
	bool removeComplete = false;
	for (int i = 0; i <= Roster::indexForArray; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			removeComplete = true; /*This means we found student.*/
			if (i < numStudents - 1)
			{
				Student* studentSwap = classRosterArray[i]; /*Swap with last student in roster.*/
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = studentSwap;
			}
			Roster::indexForArray--;
		}
	}
	if (removeComplete)
	{
		cout << studentID << " Removed from roster." << std::endl << std::endl;
		this->printAll();
	}
	else cout << studentID << " not found." << std::endl << std::endl;
}

Roster::~Roster() 
{
	cout << "You have called the DESTRUCTOR! Now I am become Death, Destroyer of computer science students." << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destroying student: " << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}
