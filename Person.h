#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
    private:
        std::string firstName;
        std::string middleName;
        std::string lastName;
        int age;
    public:
        virtual ~Person() = default;

        Person(const std::string& firstName, const std::string& middleName, const std::string& lastName, int age);
        Person(const std::string& firstName, const std::string& lastName, int age);
        void setFirstName(const std::string& firstName);
        void setMiddleName(const std::string& middleName);
        void setLastName(const std::string& lastName);
        void setAge(int age);

        std::string getFirstName() const ;
        std::string getMiddleName() const ;
        std::string getLastName() const ;
        int getAge() const ;
};
#endif
