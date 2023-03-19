#include <iostream>
#include <string>
#include "roster.h"
using namespace std;
/* Named my main.cpp file as C867.cpp because VS Studio
    thought it was a duplicate declaration of int main
    and kept throwing a build error. This was the only
    solution I could find unfortunately */

int main() {
    /* Requirement F.1 "Print out to the screen via your application, the course title, the programming language used,
    WGU Student ID, and my Name" */

    cout << "C867 C++ Application" << endl;
    cout << "By Spencer Vedenoff" << endl;
    cout << "Student ID: 002838342" << endl;
    cout << "Dated 3/15/2023" << endl << endl;

    /* Requirement F.2 "Create and Instance of the Roster class called classRoster" */

    Roster* classRoster = new Roster();

    /* Requirement F.3 "Add each student to classRoster" */
    for (int i = 0; i <= 5; i++) { classRoster->parseArray(i); }

    /* Requirement F.4 "Convert the following pseudo code to complete the rest of the main() function:" */

    cout << "Printing all students: ";
    cout << endl;
    classRoster->printAll();
    classRoster->printInvalidEmails();

    cout << "Printing average days in course for each student:" << endl;

    for (int i = 0; i < 5; i++) {
        classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->getID());
    }

    cout << endl;
    classRoster->printByDegreeProgram(SOFTWARE);

    cout << endl;
    classRoster->removeStudent("A3");

    cout << endl;
    cout << "Printing all students:\n";
    classRoster->printAll();
    classRoster->removeStudent("A3");

    return 0;
}