#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student {
    private:
        std::string firstName;
        std::string middleName;
        std::string lastName;
        std::string gradeLevel;
        int studentID;
        double gpa;
    public:
        Student(const std::string& firstName, const std::string& middleName, const std::string& lastName, const std::string& gradeLevel, int studentID, double gpa);
        Student(const std::string& firstName, const std::string& lastName, const std::string& gradeLevel, int studentID, double gpa);
        void setFirstName(const std::string& firstName);
        void setMiddleName(const std::string& middleName);
        void setLastName(const std::string& lastName);
        void setGradeLevel(const std::string& gradeLevel);
        void setStudentID(int studentID);
        void setGPA(double gpa);

        std::string getFirstName() const ;
        std::string getMiddleName() const ;
        std::string getLastName() const ;
        std::string getGradeLevel() const ;
        int getStudentID() const ;
        double getGPA() const ;
};

#endif