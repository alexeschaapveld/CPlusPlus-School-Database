#ifndef Admin_h
#define Admin_h
#include "Person.h"
#include <iostream>
#include <string>
class Admin : public Person {
    private:
        std::string department;
        int employeeID;
    public:
        Admin(const std::string& firstName, const std::string& middleName, const std::string& lastName, int age, const std::string& department, int employeeID);
        Admin(const std::string& firstName, const std::string& lastName, int age, const std::string& department, int employeeID);
        void setDepartment(const std::string& department);
        void setEmployeeID(int employeeID);

        std::string getDepartment() const ;
        int getEmployeeID() const ;
};
#endif