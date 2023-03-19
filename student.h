#pragma once
#include "degree.h"
/* Using Namespace for neatness of code */
using namespace std;

class Student {
public:
    /* Student Class Constructor */
    Student();

    /* Accessors */
    string getID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    string getAge();
    int getDays(int atArray);
    DegreeProgram getDegreeProgram();

    /* Mutators */
    void setID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmailAddress(std::string emailAddress);
    void setAge(std::string age);
    void setDays(int num0, int num1, int num2);
    void setDegreeProgram(DegreeProgram degree);


    void print(int result);

private:


    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    string age;
    int daysLeft[3];
    DegreeProgram degreeProgram;
};