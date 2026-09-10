#include <algorithm> 
#include <array>
#include <iostream> 
#include <limits> 
#include <string> 
#include <vector> 
#include <memory> 
#include "Admin.h" 
#include "Person.h" 
#include "Teacher.h" 
#include "Student.h" 

void addStudent(std::vector<std::shared_ptr<Person>>& schoolRegistry);
void addTeacher(std::vector<std::shared_ptr<Person>>& schoolRegistry);
void addAdmin(std::vector<std::shared_ptr<Person>>& schoolRegistry);
void viewAll(const std::vector<std::shared_ptr<Person>>& schoolRegistry);
std::string readString(const std::string& prompt);
int readInt(const std::string& prompt);
double readDouble(const std::string& prompt);

int main() { 
    std::vector<std::shared_ptr<Person>> schoolRegistry; 
    int choice; 

    while(true) { 
        std::cout << "\n=== School Registry System ===" << std::endl; 
        std::cout << "1. Add a new student." << std::endl; 
        std::cout << "2. Add a new teacher." << std::endl; 
        std::cout << "3. Add a new admin." << std::endl; 
        std::cout << "4. View all registered individuals." << std::endl; 
        std::cout << "5. Exit." << std::endl; 
        std::cout << "Enter your choice: ";
        
        std::cin >> choice; 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Fix 1: Check if the user typed letters instead of a number
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
            std::cout << "Invalid input. Please enter a number between 1 and 5.\n" << std::endl;
            continue;
        }

        // Fix 2: Add logic to handle the menu choices
        if (choice == 5) {
            std::cout << "Exiting program. Goodbye!" << std::endl;
            break; // Breaks the while loop and ends the program
        } else if (choice == 1) {
            std::cout << "You selected option 1: Add a new student." << std::endl;
            addStudent(schoolRegistry);
        } else if (choice == 2) {
            std::cout << "You selected option 2: Add a new teacher." << std::endl;
            addTeacher(schoolRegistry);
        } else if (choice == 3) {
            std::cout << "You selected option 3: Add a new admin." << std::endl;
            addAdmin(schoolRegistry);
        } else if (choice == 4) {
            std::cout << "You selected option 4: View all registered individuals." << std::endl;
            viewAll(schoolRegistry);
        } else {
            std::cout << "Invalid choice. Please choose 1-5.\n" << std::endl;
        }
    } 

    return 0; 
}

std::string readString(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

int readInt(const std::string& prompt) {
    int value = 0;
    std::cout << prompt;
    std::cin >> value;

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid integer." << std::endl;
        std::cout << prompt;
        std::cin >> value;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

double readDouble(const std::string& prompt) {
    double value = 0.0;
    std::cout << prompt;
    std::cin >> value;

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid number." << std::endl;
        std::cout << prompt;
        std::cin >> value;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

void addStudent(std::vector<std::shared_ptr<Person>>& schoolRegistry) {
    std::string firstName = readString("Enter first name: ");
    std::string middleName = readString("Enter middle name (or leave blank): ");
    std::string lastName = readString("Enter last name: ");
    int age = readInt("Enter age: ");

    std::array<std::string, 8> classes{};
    for (int i = 0; i < 8; ++i) {
        classes[i] = readString("Enter class " + std::to_string(i + 1) + ": ");
    }

    int grade = readInt("Enter grade level: ");
    int studentID = readInt("Enter student ID: ");
    double GPA = readDouble("Enter GPA: ");

    if (middleName.empty()) {
        schoolRegistry.push_back(std::make_shared<Student>(firstName, lastName, age, classes, grade, studentID, GPA));
    } else {
        schoolRegistry.push_back(std::make_shared<Student>(firstName, middleName, lastName, age, classes, grade, studentID, GPA));
    }

    std::cout << "Student added successfully." << std::endl;
}

void addTeacher(std::vector<std::shared_ptr<Person>>& schoolRegistry) {
    std::string firstName = readString("Enter first name: ");
    std::string middleName = readString("Enter middle name (or leave blank): ");
    std::string lastName = readString("Enter last name: ");
    int age = readInt("Enter age: ");
    std::string subject = readString("Enter subject: ");
    int employeeID = readInt("Enter employee ID: ");
    int yearsOfExperience = readInt("Enter years of experience: ");

    if (middleName.empty()) {
        schoolRegistry.push_back(std::make_shared<Teacher>(firstName, lastName, age, subject, employeeID, yearsOfExperience));
    } else {
        schoolRegistry.push_back(std::make_shared<Teacher>(firstName, middleName, lastName, age, subject, employeeID, yearsOfExperience));
    }

    std::cout << "Teacher added successfully." << std::endl;
}

void addAdmin(std::vector<std::shared_ptr<Person>>& schoolRegistry) {
    std::string firstName = readString("Enter first name: ");
    std::string middleName = readString("Enter middle name (or leave blank): ");
    std::string lastName = readString("Enter last name: ");
    int age = readInt("Enter age: ");
    std::string department = readString("Enter department: ");
    int employeeID = readInt("Enter employee ID: ");

    if (middleName.empty()) {
        schoolRegistry.push_back(std::make_shared<Admin>(firstName, lastName, age, department, employeeID));
    } else {
        schoolRegistry.push_back(std::make_shared<Admin>(firstName, middleName, lastName, age, department, employeeID));
    }

    std::cout << "Admin added successfully." << std::endl;
}

void viewAll(const std::vector<std::shared_ptr<Person>>& schoolRegistry) {
    if (schoolRegistry.empty()) {
        std::cout << "No registered individuals found." << std::endl;
        return;
    }

    std::cout << "\nRegistered individuals:" << std::endl;

    for (const auto& person : schoolRegistry) {
        if (auto student = std::dynamic_pointer_cast<Student>(person)) {
            std::cout << "Student: " << student->getFirstName() << " "
                      << student->getLastName() << ", Age: " << student->getAge()
                      << ", Grade: " << student->getGrade() << ", GPA: " << student->getGPA() << std::endl;
        } else if (auto teacher = std::dynamic_pointer_cast<Teacher>(person)) {
            std::cout << "Teacher: " << teacher->getFirstName() << " "
                      << teacher->getLastName() << ", Age: " << teacher->getAge()
                      << ", Subject: " << teacher->getSubject() << ", Employee ID: "
                      << teacher->getEmployeeID() << std::endl;
        } else if (auto admin = std::dynamic_pointer_cast<Admin>(person)) {
            std::cout << "Admin: " << admin->getFirstName() << " "
                      << admin->getLastName() << ", Age: " << admin->getAge()
                      << ", Department: " << admin->getDepartment()
                      << ", Employee ID: " << admin->getEmployeeID() << std::endl;
        }
    }
}
