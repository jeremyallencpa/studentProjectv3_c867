#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

/*Requirement D - create the student class variables studentID, firstName, lastName
email address, age, array of number of days to complete each course, degree program.*/

class Student {

/*Requirement D(1) - set variables for Student class that will pull from the studentData string.*/

public:

/*Create integer to hold array size for days in class array declared below.*/

	const static int daysInClassArraySize = 3;

/*Create private variables in the Student class that will hold student ID, first name,
last name, email address, age, the number of days to complete a course, and
the student's degree program.*/

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	double daysInClass[daysInClassArraySize];
	DegreeProgram degreeType;

/*Create public items for student class.*/

public:

/*Create empty constructor for Student class.*/

	Student();
	
/*Create full constructor for Student class.*/

	Student(string studentID, string firstName, string lastName, string emailAddress, int age, double daysInClass[], DegreeProgram degreeType);
	
/*Create destructor for student class.*/

	~Student();

/*Create getters for student class.*/

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	double* getDaysInClass();
	DegreeProgram getDegreeType();

/*Create setters for student class.*/

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInClass(double daysInClass[]);
	void setDegreeType(DegreeProgram degreeProgram);
	
/*Print specific student data.*/

	void print();
};
