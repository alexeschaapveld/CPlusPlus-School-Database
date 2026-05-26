#include <iostream>
#include <string>
#include "Person.h"

Person::Person(const std::string& firstName, const std::string& middleName, const std::string& lastName, int age)
    : firstName(firstName), middleName(middleName), lastName(lastName), age(age) {}

Person::Person(const std::string& firstName, const std::string& lastName, int age)
    : firstName(firstName), middleName(""), lastName(lastName), age(age) {}

void Person::setFirstName(const std::string& newName) { firstName = newName; }
void Person::setMiddleName(const std::string& newName) { middleName = newName; }
void Person::setLastName(const std::string& newName ) { lastName = newName; }
void Person::setAge(int newAge) { age = newAge; }

std::string Person::getFirstName() const { return firstName; }
std::string Person::getMiddleName() const { return middleName; }    
std::string Person::getLastName() const { return lastName; }
int Person::getAge() const { return age; }
