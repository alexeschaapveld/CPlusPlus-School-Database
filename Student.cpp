#include <iostream>
#include <string>
#include "Student.h"

Student::Student(const std::string& firstName, const std::string& middleName, const std::string& lastName, const std::string& gradeLevel, int studentID, double gpa)
    : firstName(firstName), middleName(middleName), lastName(lastName), gradeLevel(gradeLevel), studentID(studentID), gpa(gpa) {
    // Constructor body can stay empty because the initializer list did all the work!
}

// Constructor 2: Without Middle Name
Student::Student(const std::string& firstName, const std::string& lastName, const std::string& gradeLevel, int studentID, double gpa)
    : firstName(firstName), middleName(""), lastName(lastName), gradeLevel(gradeLevel), studentID(studentID), gpa(gpa) {
}
void Student::setFirstName(const std::string& newName) { firstName = newName; }
void Student::setMiddleName(const std::string& newName) { middleName = newName; }
void Student::setLastName(const std::string& newName ) { lastName = newName; }
void Student::setGradeLevel(const std::string& grade) { gradeLevel = grade; }
void Student::setStudentID(int studentIDNum) { studentID = studentIDNum; }
void Student::setGPA(double gpaNew) { gpa = gpaNew; }

std::string Student::getFirstName() const { return firstName; }
std::string Student::getMiddleName() const { return middleName; }
std::string Student::getLastName() const { return lastName; }
std::string Student::getGradeLevel() const { return gradeLevel; }
int Student::getStudentID() const { return studentID; }
double Student::getGPA() const { return gpa; }
