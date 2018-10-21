// Copyright 2018 Peter Akey
// Modified as needed from C++ Programming by D.S. Malik 8th Edition

#include <iostream>
#include <limits>
#include "orderedArrayListType.h"

int main() {
    int checkInput();

    int number;
    char userInput = 0;

    orderedArrayListType intList(25);

    // Input such as "23" causes "3" to try to be removed.  Why?
    while (userInput != '5') {
        std::cout << "Manage your list using the menu below: " << std::endl;
        std::cout << "   1 - Insert" << std::endl;
        std::cout << "   2 - Remove" << std::endl;
        std::cout << "   3 - Sequential Search" << std::endl;
        std::cout << "   4 - Print List" << std::endl;
        std::cout << "   5 - Quit" << std::endl;
        std::cin >> userInput;

        if (userInput == '1') {
            // Insert element into array
            std::cout << "Enter integer to insert: ";
            number = checkInput();
            intList.insert(number);
        } else if (userInput == '2') {
            // Remove element from array
            std::cout << "Enter the integer you would like to remove: ";
            number = checkInput();
            intList.remove(number);
            // intList.print();
        } else if (userInput == '3') {
            // Perform SeqSearch
            std::cout << "Enter the integer you would like to find: ";
            number = checkInput();
            intList.seqSearch(number);
        } else if (userInput == '4') {
            // Print list
            std::cout << "Your list contains:" << std::endl;
            // I'd like to put a length check here but I don't know its scope
            intList.print();
        } else if (userInput == '5') {
            // Quit
            std::cout << "Terminating program." << std::endl;
            break;
        } else {
            std::cout << "Invalid entry. Select an option from the list below:";
            std::cout << std::endl;
        }
    }
    // end while userInput
    return 0;
}

int checkInput() {
    int x;

    while (!(std::cin >> x)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "You entered " << x << std::endl;
        std::cout << "Invalid input, try again." << std::endl;
        std::cout << "Enter integer to add to your list: ";
    }
    return x;
}
