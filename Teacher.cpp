#include <iostream>
#include <string>
#include "Teacher.h"

Teacher::Teacher(const std::string& firstName, const std::string& middleName, const std::string& lastName, int age, const std::string& subject, int employeeID, int yearsOfExperience)
    : Person(firstName, middleName, lastName, age), subject(subject), employeeID(employeeID), yearsOfExperience(yearsOfExperience) {
}
Teacher::Teacher(const std::string& firstName, const std::string& lastName, int age, const std::string& subject, int employeeID, int yearsOfExperience)
    : Person(firstName, lastName, age), subject(subject), employeeID(employeeID), yearsOfExperience(yearsOfExperience) {
}

void Teacher::setSubject(const std::string& newSubject) { subject = newSubject; }
void Teacher::setEmployeeID(int newID) { employeeID = newID; }
void Teacher::setYearsOfExperience(int newYears) { yearsOfExperience = newYears; }

std::string Teacher::getSubject() const { return subject; }
int Teacher::getEmployeeID() const { return employeeID; }
int Teacher::getYearsOfExperience() const { return yearsOfExperience; }

