#pragma once
#include <iostream>
#include <iomanip>
#include "student.h"

using std::string;
using std::cout;

/*Create the empty constructor for the student class.*/

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysInClassArraySize; i++) this->daysInClass[i] = 0;
	this->degreeType = DegreeProgram::NETWORK;
}
/*Create the full constructor for the student class.*/

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, double daysInClass[], DegreeProgram degreeType)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysInClassArraySize; i++) this->daysInClass[i] = daysInClass[i];
	this->degreeType = degreeType;
}
/*Create the destructor for the student class.*/

Student::~Student() {}

/*Create full construction for getters for student class.*/

string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
double* Student::getDaysInClass() { return this->daysInClass; }
DegreeProgram Student::getDegreeType() { return this->degreeType; }

/*Create full constructor for setters for student class.*/

void Student::setStudentID(string ID) { this->studentID = ID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInClass(double daysInClass[])
{
	for (int i = 0; i < daysInClassArraySize; i++) this->daysInClass[i] = daysInClass[i];
}
void Student::setDegreeType(DegreeProgram degreeProgram) { this->degreeType = degreeProgram; }

/*Function to print the student data.*/

void Student::print()
{
	cout << "ID:" << this->getStudentID() << '\t';
	cout << "First Name: " << this->getFirstName() << '\t';
	cout << "Last Name: " << this->getLastName() << '\t';
	cout << "Age: " << this->getAge() << '\t' << '\t';
	/*create days in course array output*/
	cout << "Days In Course {"
	<< this->getDaysInClass()[0] << ',';
	cout << this->getDaysInClass()[1] << ',';
	cout << this->getDaysInClass()[2] << "}" << '\t';
	/*create days in course array output*/
	cout << "Degree Program: " <<degreeProgramStringFormat[this->getDegreeType()] << '\n';
}