#ifndef TEACHER_H
#define TEACHER_H
#include "Person.h"
#include <iostream>
#include <string>

class Teacher : public Person {
    private:
        std::string subject;
        int employeeID;
        int yearsOfExperience;
    public:
        Teacher(const std::string& firstName, const std::string& middleName, const std::string& lastName, int age, const std::string& subject, int employeeID, int yearsOfExperience);
        Teacher(const std::string& firstName, const std::string& lastName, int age, const std::string& subject, int employeeID, int yearsOfExperience);
        void setSubject(const std::string& subject);
        void setEmployeeID(int employeeID);
        void setYearsOfExperience(int yearsOfExperience);

        std::string getSubject() const ;
        int getEmployeeID() const ;
        int getYearsOfExperience() const ;
};
#endif