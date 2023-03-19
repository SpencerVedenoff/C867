#pragma once
#include <string>
#include "student.h"
/* Using Namespace for neatness of code */
using namespace std;

/* Requirement A: Modify the “studentData Table” to include your personal information as the last item. */

static string studentData[5] = {
        "A1,John,Smith,John1989@gm il.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Spencer,Vedenoff,svedeno@wgu.edu,27,30,45,60,SOFTWARE"
};

class Roster {

public:


    Roster(); /* Constructor */

    ~Roster(); /* Destructor */

    /* Class Roster array, using double '*' so it can talk to main and roster.cpp */
    Student** classRosterArray;

    /* Requirement E3: Define the following functions */
    /* Add function for students in the roster class */
    void addStudent(int index, string a, string b, string c, string d, string e, int f, int g, int h, DegreeProgram x);

    /* Remove function for students in the roster class */
    void removeStudent(string stID);

    /* Parse function */
    void parseArray(int rosterIndex);

    /* the Print all Function */
    void printAll();

    /* Function to Print out the average days in each course */
    void printAverageDaysInCourse(string stID);

    /* Function to print out invalid emails */
    void printInvalidEmails();

    /* Functin to print out by Degree Program with the enum data type */
    void printByDegreeProgram(DegreeProgram degreeprogram);

private:

    /* Function to turn int value for Degree Program into a String value*/
    void printDegreeStr(int major);
};