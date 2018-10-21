// Copyright 2018 Peter Akey
// Modified as needed from C++ Programming by D.S. Malik 8th Edition

#include <iostream>
#include <sstream>
#include <limits>
#include "unorderedLinkedList.h"

// I'm only including three separate classes because the assignment said so:
// Your program must contain three exception classes: invalidHr...and so on...
class invalidEntry {
 public:
    invalidEntry() {
        // default
        message = "The value entered was not accepted";
        std::cout << "invalidEntry exception thrown!" << std::endl;
    }
    invalidEntry(std::string msg) {
        // cpplint throws the following message:
        // Single-parameter constructors should be marked explicit (line 18)
        // overload when a string is given
        message = msg;
        std::cout << "invalidEntry exception thrown!" << std::endl;
    }
    std::string what() {
        return message;
    }
 private:
    std::string message;
};

// prototype the functions
void runProgram();
std::string checkInputStr();
int checkInputInt(std::string);

// main
int main() {
    runProgram();
    return 0;
}

// get user input
void runProgram() {
    unorderedLinkedList<int> linkedList, list2;

    int userInput = 0;
    try {
        do {
            std::cout << std::endl << "Welcome to PA-5 - Linked Lists"
                        << std::endl;
            std::cout << "   1 - Add a new item to the list" << std::endl;
            std::cout << "   2 - Delete the first occurrence of a given item "
                        << "from the list" << std::endl;
            std::cout << "   3 - Delete all occurrences of a given item from "
                        << "the list" << std::endl;
            std::cout << "   4 - Delete the smallest item from the list"
                        << std::endl;
            std::cout << "   5 - Print the kth item in the list" << std::endl;
            std::cout << "   6 - Delete the kth item from the list"
                        << std::endl;
            std::cout << "   7 - Print the list in reverse" << std::endl;
            std::cout << "   8 - Print the list" << std::endl;
            std::cout << "   9 - Quit" << std::endl;
            userInput = checkInputInt("Make your selection");

            if (userInput == 1) {
                // Add a new item to the list
                int info;
                info = checkInputInt("Enter your new item");
                linkedList.insertFirst(info);
                std::cout << info << " has been inserted into the beginning "
                            << "of your list." << std::endl;
            } else if (userInput == 2) {
                // Delete the first occurrence of an item
                // AND stop traversing the list!
                int info;
                std::cout << "You've chosen to remove the first occurrence "
                            << "of an item." << std::endl;
                info = checkInputInt("Enter the value to be removed");
                linkedList.deleteItem(info);
            } else if (userInput == 3) {
                // Delete all occurrences of an item
                int info;
                std::cout << "You've chosen to remove all occurrences "
                            << "of an item." << std::endl;
                info = checkInputInt("Enter the value to be removed");
                linkedList.deleteAll(info);
            } else if (userInput == 4) {
                // Delete the smallest item from the list
                std::cout << "You've chosen to remove the smallest item"
                            << " in your list." << std::endl;
                linkedList.deleteSmallest();
            } else if (userInput == 5) {
                // Print the kth item in the list
                int info;
                std::cout << "You've chosen to print the kth item in the list"
                            << std::endl;
                std::string msg = "Enter the position of the element you "
                            "would like to print\n"
                            "(the \"position\" starts at 1)";
                info = checkInputInt(msg);
                linkedList.print(info);
            } else if (userInput == 6) {
                // Delete the kth item in the list
                int info;
                std::cout << "You've chosen to delete the kth item in the list"
                            << std::endl;
                std::string msg = "Enter the position of the element you "
                            "would like to delete\n"
                            "(the \"position\" starts at 1)";
                info = checkInputInt(msg);
                linkedList.deleteNode(info);
            } else if (userInput == 7) {
                // Print the list in reverse
                std::cout << "Recursively:" << std::endl;
                linkedList.recursiveReversePrint();
                // Does not work, unsure how to instantiate an object
                // while that object is being defined :)
                std::cout << "Non-Recursively (poorly implemented):"
                        << std::endl;
                linkedList.reversePrint();
            } else if (userInput == 8) {
                // Print the list
                linkedList.print();
            } else if (userInput != 9) {
                std::cout << "Invalid entry. Select an option from the list:"
                        << std::endl;
            }
        }
        while (userInput != 9);
        std::cout << "All done!  Exiting." << std::endl;
    } catch (invalidEntry& e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "General error.  Terminating program" << std::endl;
    }
}

int checkInputInt(std::string strMsg) {
    int num;
    while (true) {
        std::cout << strMsg << ": ";
        std::cin >> num;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "The value entered was either not an integer or\n"
                    << "outside of the range of an int (+/-2147483648)."
                    << std::endl;
        } else {
            return num;
        }
    }
}
