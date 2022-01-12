#pragma once
#include "student.h"

/*Declare roster class.*/

class Roster
{
public:
/*Create integer to hold size of class roster array. Fixed integer size for this one.*/
	const static int numStudents = 5;

/*Create an index for the classRosterArray to loop through.*/

	int indexForArray = -1;
/*Create a pointer to an array of student objects. These will be created dynamically on the heap
and we will need to release this memory when the program is done.*/

	Student* classRosterArray[numStudents];

/*Function to parse strings in our data set.*/

	void parseStudentStrings(string row);

/*Function to pass our student strings into the pointers to student objects we created above.*/

	void add(string studentID,string firstName,string lastName,string emailAddress,int age,double daysInClass1,double daysInClass2,double daysInClass3,DegreeProgram degreeProgram);

/*Print method in student class for each student.*/
	void printAll();

/*Print by degree program.*/
	void printByDegreeProgram(DegreeProgram degreeProgram);

/*Print invalid emails.*/
	void printInvalidEmails();

/*Print average days in class.*/

	void printAverageDaysInClass();

/*Remove student by student ID.*/
	void removeStudentByStudentID(string studentID);

/*Create destructor for Roster class. Need to release memory on the heap.*/
	~Roster();
};
