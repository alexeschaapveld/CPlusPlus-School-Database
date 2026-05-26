#include <iostream>
#include <string>
#include "Admin.h"

Admin::Admin(const std::string& firstName, const std::string& middleName, const std::string& lastName, int age, const std::string& department, int employeeID)
    : Person(firstName, middleName, lastName, age), department(department), employeeID(employeeID) {
}
Admin::Admin(const std::string& firstName, const std::string& lastName, int age, const std::string& department, int employeeID)
    : Person(firstName, lastName, age), department(department), employeeID(employeeID) {
}

void Admin::setDepartment(const std::string& newDepartment) { department = newDepartment; }
void Admin::setEmployeeID(int newID) { employeeID = newID; }

std::string Admin::getDepartment() const { return department; }
int Admin::getEmployeeID() const { return employeeID; }