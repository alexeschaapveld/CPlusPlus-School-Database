#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <iostream>
#include <string>
#include <array>
#include <vector>

class Student : public Person {
    private:
        std::array<std::string, 8> classList;
        int grade;
        int studentID;
        double GPA;

    public:
        // Constructors
        Student(const std::string& firstName, const std::string& middleName, const std::string& lastName, int age, const std::array<std::string, 8>& classes, int grade, int studentID, double GPA);
        Student(const std::string& firstName, const std::string& lastName, int age, const std::array<std::string, 8>& classes, int grade, int studentID, double GPA);
        
        // Setters
        void setClass(const std::array<std::string, 8>& newClassList);
        void setGrade(int grade);
        void setStudentID(int studentID);
        void setGPA(double GPA);

        // Getters
        std::array<std::string, 8> getClass() const;
        const std::string* getClass(int index) const; // Returns a const pointer to prevent outside modifications
        int getGrade() const;
        int getStudentID() const;
        double getGPA() const;
};

#endif