#include <algorithm> 
#include <iostream> 
#include <limits> 
#include <string> 
#include <vector> 
#include <memory> 
#include "Admin.h" 
#include "Person.h" 
#include "Teacher.h" 
#include "Student.h" 

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
        } else if (choice >= 1 && choice <= 4) {
            std::cout << "You selected option " << choice << " (Feature not implemented yet).\n" << std::endl;
            // Your logic for adding students/teachers/admins will go here
        } else {
            std::cout << "Invalid choice. Please choose 1-5.\n" << std::endl;
        }
    } 

    return 0; 
}
