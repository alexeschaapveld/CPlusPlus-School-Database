#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "Student.h"

void printStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No students in the database.\n";
        return;
    }

    std::cout << "Students:\n";
    for (const auto& student : students) {
        std::cout << "ID: " << student.getStudentID()
                  << ", Name: " << student.getFirstName();
        if (!student.getMiddleName().empty()) {
            std::cout << " " << student.getMiddleName();
        }
        std::cout << " " << student.getLastName()
                  << ", Grade: " << student.getGradeLevel()
                  << ", GPA: " << student.getGPA() << "\n";
    }
}

int main() {
    std::vector<Student> students;

    while (true) {
        std::cout << "\nChoose an option:\n";
        std::cout << "1) Add student\n";
        std::cout << "2) Remove student by ID\n";
        std::cout << "3) Print all students\n";
        std::cout << "4) Exit\n";
        std::cout << "Option: ";

        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 4) {
            break;
        }

        if (choice == 1) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string firstName, middleName, lastName, gradeLevel;
            int studentID;
            double gpa;

            std::cout << "First name: ";
            std::getline(std::cin, firstName);
            std::cout << "Middle name (leave blank if none): ";
            std::getline(std::cin, middleName);
            std::cout << "Last name: ";
            std::getline(std::cin, lastName);
            std::cout << "Grade level: ";
            std::getline(std::cin, gradeLevel);
            std::cout << "Student ID: ";
            std::cin >> studentID;
            std::cout << "GPA: ";
            std::cin >> gpa;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            students.emplace_back(firstName, middleName, lastName, gradeLevel, studentID, gpa);
            std::cout << "Student added.\n";
        } else if (choice == 2) {
            std::cout << "Enter the student ID to remove: ";
            int studentID;
            std::cin >> studentID;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            auto it = std::remove_if(students.begin(), students.end(),
                                     [studentID](const Student& student) {
                                         return student.getStudentID() == studentID;
                                     });
            if (it != students.end()) {
                students.erase(it, students.end());
                std::cout << "Student removed.\n";
            } else {
                std::cout << "No student found with ID " << studentID << ".\n";
            }
        } else if (choice == 3) {
            printStudents(students);
        } else {
            std::cout << "Please choose a valid option (1-4).\n";
        }
    }

    std::cout << "Exiting application.\n";
    return 0;
}