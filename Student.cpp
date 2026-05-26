#include "Student.h"
#include <iostream>
#include <string>
#include <array>
#include <vector>

// Constructor 1: With middle name
Student::Student(const std::string& firstName, const std::string& middleName, const std::string& lastName, int age, const std::array<std::string, 8>& classes, int grade, int studentID, double GPA)
    : Person(firstName, middleName, lastName, age), classList(classes), grade(grade), studentID(studentID), GPA(GPA) {
    // The initializer list automatically copies the entire 'classes' array into 'classList'
}

// Constructor 2: Without middle name
Student::Student(const std::string& firstName, const std::string& lastName, int age, const std::array<std::string, 8>& classes, int grade, int studentID, double GPA)
    : Person(firstName, lastName, age), classList(classes), grade(grade), studentID(studentID), GPA(GPA) {
}

// Setters
void Student::setClass(const std::array<std::string, 8>& newClassList) {
    classList = newClassList; // std::array allows direct assignment copying
}   

void Student::setGrade(int newGrade) { 
    grade = newGrade; 
}

void Student::setStudentID(int newID) { 
    studentID = newID; 
}

void Student::setGPA(double newGPA) { 
    GPA = newGPA; 
}

// Getters
std::array<std::string, 8> Student::getClass() const { 
    return classList; 
}

const std::string* Student::getClass(int index) const { 
    if (index < 0 || index >= 8) {
        return nullptr; // Bounds check protection
    }
    return &classList[index];
}

int Student::getGrade() const { 
    return grade; 
}

int Student::getStudentID() const { 
    return studentID; 
}

double Student::getGPA() const { 
    return GPA; 
}