#pragma once
#include <sstream>
#include <string>
#include <iostream>

#include "roster.h"
#include "student.h"
#include "degree.h"
/* Using Namespace for neatness of code */
using namespace std;



/* Requirement E.1 " Create an array of pointer, classRosterArray,
to hold the data provided in the studentData Table. " */

/* Roster Constructor */
Roster::Roster() { classRosterArray = new Student * [5]; };

/* Roster Destructor */

Roster::~Roster() { delete[] classRosterArray; };

/* Prints the Degree Program using a switch statement, */

void Roster::printDegreeStr(int major) {
	switch (major) {
	case 0:
		cout << "SECURITY";
		break;
	case 1:
		cout << "NETWORK";
		break;
	case 2:
		cout << "SOFTWARE";
		break;
	default:
		cout << "ERROR";
		break;
	}
}


/* Parameters: A through X are what I'm using to pass the following as variables */

void Roster::addStudent(int index, string a, string b, string c, string d, string e, int f, int g, int h, DegreeProgram x) {


	const int indexConst = index;

	Student* nstudent = new Student();


	nstudent->setID(a);
	nstudent->setFirstName(b);
	nstudent->setLastName(c);
	nstudent->setEmailAddress(d);
	nstudent->setAge(e);
	nstudent->setDays(f, g, h);
	nstudent->setDegreeProgram(x);

	classRosterArray[indexConst] = nstudent;
}

/* Definition of removeStudent Function from roster.h file */
void Roster::removeStudent(string stID) {
	/* Boolean for indexing */
	bool indexFound = false;

	int indexNum = 0;

	cout << " Searching for studentID: " << stID;

	for (int i = 0; i < 5; i++) {
		/* If equal to one of the values, the student ID is found */
		if (this->classRosterArray[i]->getID() == stID) {
			indexNum = i;
			indexFound = true;
			cout << ".";
			break;
		}
		/* On the inverse, if its not equal then the student ID was NOT found */
		else {
			indexFound = false;
			cout << ".";
			continue;
		}
	}
	cout << endl;

	/* This removes the data at the index location if found */
	if (indexFound) {
		cout << "Student Found! Removing data from the roster.";
		const int indexConst = indexNum;
		
		Student* nstudent = new Student();

		

		/* This ensures that if the student data is removed the program wont print it */
		nstudent->setID(" ERROR ");
		cout << ".";
		nstudent->setFirstName("");
		cout << ".";
		nstudent->setLastName("");
		cout << ".";
		nstudent->setEmailAddress("");
		cout << ".";
		nstudent->setAge("");
		cout << ".";
		nstudent->setDays(0, 0, 0);
		cout << ".";
		nstudent->setDegreeProgram(NONE);
		cout << ".";

		/* Wipes old data with new data */
		classRosterArray[indexConst] = nstudent;

		cout << " DONE ";
	}

	else {
		/* This is output if the student is not found, hence the else statement */
		cout << "Student " << stID << " was not found.";
	}
	cout << endl;
}

void Roster::parseArray(int rosterIndex) {

	/* Points to the data table to parse */
	string studentDataString = studentData[rosterIndex];

	int stringLength = studentDataString.length();

	/* Blank here so that they can be given data once its parsed */
	string studentID = "";
	string firstName = "";
	string lastName = "";
	string email = "";
	string age = "";
	string stringdays0 = "";
	string stringdays1 = "";
	string stringdays2 = "";
	int days0 = 0;
	int days1 = 0;
	int days2 = 0;
	string degreeProgramString = "";
	DegreeProgram studentDegree;

	int i = 0;

	/* int skip is used as variable for switch statement here */
	int skip = 0;

	/* Found this parse method worked a lot better than what I origionally tried 
	also much easier to understand than the lhs/rhs method personally */
	for (i = 0; i < stringLength; i++) {
		char s = studentDataString.at(i);
		if (s != ',') {
			switch (skip) {
			case 0:
				studentID.push_back(s);
				break;
			case 1:
				firstName.push_back(s);
				break;
			case 2:
				lastName.push_back(s);
				break;
			case 3:
				email.push_back(s);
				break;
			case 4:
				age.push_back(s);
				break;
			case 5:
				stringdays0.push_back(s);
				break;
			case 6:
				stringdays1.push_back(s);
				break;
			case 7:
				stringdays2.push_back(s);
				break;
			case 8:
				degreeProgramString.push_back(s);
				break;
			default:
				break;
			}
		}

		else {
			skip = skip + 1;
		}
	}

	/* this converts the values from string to int */
	stringstream convertDays0(stringdays0);
	stringstream convertDays1(stringdays1);
	stringstream convertDays2(stringdays2);
	convertDays0 >> days0;
	convertDays1 >> days1;
	convertDays2 >> days2;

	
	/* Converts string variable to enum value */
	if (degreeProgramString == "SECURITY") {
		studentDegree = SECURITY;
	}
	else if (degreeProgramString == "NETWORK") {
		studentDegree = NETWORK;
	}
	else if (degreeProgramString == "SOFTWARE") {
		studentDegree = SOFTWARE;
	}
	else {
		studentDegree = NONE;
	}

	/* This adds data to the array after paring and convesion */
	addStudent(rosterIndex, studentID, firstName, lastName, email, age, days0, days1, days2, studentDegree);
}

/* Prints all variables in the roster */
void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		/* Checks for student data in the array */
		if (classRosterArray[i]->getID() != " ERROR ") {
			classRosterArray[i]->print(0);
			cout << "	";
			cout << "First name: ";
			classRosterArray[i]->print(1);
			cout << "	";
			cout << "Last name: ";
			classRosterArray[i]->print(2);
			cout << "	";
			cout << "Age: ";
			classRosterArray[i]->print(4);
			cout << "	";
			cout << "Days In Course: {";
			classRosterArray[i]->print(5);
			cout << ",";
			classRosterArray[i]->print(6);
			cout << ",";
			classRosterArray[i]->print(7);
			cout << "}";
			cout << "Degree program: ";

			/* prints degree string at index location */
			printDegreeStr(classRosterArray[i]->getDegreeProgram());
			cout << endl;
		}
	}
	cout << endl;
}

/* Definition for printing average days in course */
void Roster::printAverageDaysInCourse(string stID) {
	int average;
	int daysA;
	int daysB;
	int daysC;

	/* Another boolean to find the student */
	bool indexFound = false;

	int indexNum = 0;

	/* Again a For loop to find the student in the index */
	for (int i = 0; i <= 5; i++) {
		if (this->classRosterArray[i]->getID() == stID) {
			indexNum = i;
			indexFound = true;
			break;
		}
		else {
			indexFound = false;
			continue;
		}
	}

	/* This gathers the days left for each course from the string so it can be averaged */
	if (indexFound) {
		daysA = this->classRosterArray[indexNum]->getDays(0);
		daysB = this->classRosterArray[indexNum]->getDays(1);
		daysC = this->classRosterArray[indexNum]->getDays(2);

		/* Simple math to calculate the average amount of days to complete 3 courses */
		average = ((daysA + daysB + daysC) / 3);

		cout << "Average number of days in course for student " << stID << ": " << average;
		cout << endl;

	}

	/* Another Else statement if the student ID is not found */
	else {
		cout << "Student " << stID << " was not found.";
		cout << endl;
	}
}

/* Definition for printing invalid emails function from roster.h file */
void Roster::printInvalidEmails() {
	cout << "Printing invalid emails: " << endl << endl;

	/*For Loop with 'if' statements to parse invalid email addresses */

	for (int i = 0; i < 5; i++) {
		string emailStr = classRosterArray[i]->getEmailAddress();
		/* Parses for the @ symbol as well as a period */
		if ((emailStr.find('@') != string::npos) && emailStr.find('.') != string::npos) {
			/* this if statement looks for any spaces */
			if (emailStr.find(' ') != string::npos) {
				cout << emailStr;
				cout << endl;
			}
		}
		else {
			cout << emailStr;
			cout << endl;
		}
	}
	cout << endl;
}
/* Defintion for print by degree program from roster.h file */
void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {

	cout << "Printing students by Degree Program ";
	printDegreeStr(degreeprogram);
	cout << ":" << endl;
	for (int i = 0; i < 5; i++) {

		if (classRosterArray[i]->getDegreeProgram() == degreeprogram) {
			if (classRosterArray[i]->getID() != " ERROR ") {
				classRosterArray[i]->print(0);
				cout << "	";
				cout << "First Name: ";
				classRosterArray[i]->print(1);
				cout << "	";
				cout << "Last Name: ";
				classRosterArray[i]->print(2);
				cout << "	";
				cout << "Age: ";
				classRosterArray[i]->print(4);
				cout << "	";
				cout << "Days In Course: {";
				classRosterArray[i]->print(5);
				cout << ",";
				classRosterArray[i]->print(6);
				cout << ",";
				classRosterArray[i]->print(7);
				cout << "}";
				cout << "Degree Program: ";

				printDegreeStr(classRosterArray[i]->getDegreeProgram());
				cout << endl;
			}
		}
	}
}