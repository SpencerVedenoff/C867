#pragma once
#include <string>
#include <iostream>
#include "student.h"
/* Using Namespace for neatness of code */
using namespace std;

/* Requirement D2.d Student constructor for student.cpp file */

Student::Student() {
    /* Set to blank value for default */
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = "";

    for (int i = 0; i < 3; i++)
    {
        this->daysLeft[i] = 0;
    }
    /* Set to NONE as the default value */
    this->degreeProgram = NONE;
};

/* Requirement D2: Create functions for the student class */

/* Accessors */
string Student::getID() { return studentID; }
string Student::getFirstName() { return firstName; }
string Student::getLastName() { return lastName; }
string Student::getEmailAddress() { return emailAddress; }
string Student::getAge() { return age; }
int Student::getDays(int atArray) { return daysLeft[atArray]; }
DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

/* Mutators */
void Student::setID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(string age) { this->age = age; }
void Student::setDays(int num0, int num1, int num2) { this->daysLeft[0] = num0; this->daysLeft[1] = num1; this->daysLeft[2] = num2; }
void Student::setDegreeProgram(DegreeProgram degree) { this->degreeProgram = degree; }


void Student::print(int result) {

    /* Switch statement used for output of any variable for the student
       origionally tried cout statements but kept getting errors */

    switch (result) {
    case 0:
        std::cout << studentID;
        break;
    case 1:
        std::cout << firstName;
        break;
    case 2:
        std::cout << lastName;
        break;
    case 3:
        std::cout << emailAddress;
        break;
    case 4:
        std::cout << age;
        break;
    case 5:
        std::cout << daysLeft[0];
        break;
    case 6:
        std::cout << daysLeft[1];
        break;
    case 7:
        std::cout << daysLeft[2];
        break;
    case 8:
        std::cout << degreeProgram;
        break;
    default:
        std::cout << " ERROR ";
        break;
    }
}