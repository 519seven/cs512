// Copyright 2018 Peter Akey
// Modified as needed from C++ Programming by D.S. Malik 8th Edition

#include <iostream>
#include <limits>
#include "unorderedSetType.h"

int main() {
    int checkInput();
    void printAfterAction(unorderedSetType const userList);

    int number;
    int location;
    char userInput = 0;

    unorderedSetType intList(25);

    // Input such as "23" causes "3" to try to be removed.  Why?
    while (userInput != '8') {
        std::cout << "Manage your unordered set using the menu below: "
                    << std::endl;
        std::cout << "   1 - Insert" << std::endl;
        std::cout << "   2 - Remove" << std::endl;
        std::cout << "   3 - Insert At" << std::endl;
        std::cout << "   4 - Insert End" << std::endl;
        std::cout << "   5 - Replace At" << std::endl;
        std::cout << "   6 - Sequential Search" << std::endl;
        std::cout << "   7 - Print List" << std::endl;
        std::cout << "   8 - Quit" << std::endl;
        std::cin >> userInput;

        if (userInput == '1') {
            // Insert element into array
            std::cout << "Enter integer to insert: ";
            number = checkInput();

            intList.insertEnd(number);
            printAfterAction(intList);
        } else if (userInput == '2') {
            // Remove element from array
            std::cout << "Enter the integer you would like to remove: ";
            number = checkInput();

            intList.remove(number);
            printAfterAction(intList);
        } else if (userInput == '3') {
            // Insert integer at a given location
            std::cout << "Enter the integer you would like to insert: ";
            number = checkInput();
            std::cout << "Enter the location: ";
            location = checkInput();

            intList.insertAt(location, number);
            printAfterAction(intList);
        } else if (userInput == '4') {
            // Insert at the end of the set
            std::cout << "Enter integer to insert: ";
            number = checkInput();

            intList.insertEnd(number);
            printAfterAction(intList);
        } else if (userInput == '5') {
            // Replace a given integer at a specified place in the set
            std::cout << "Enter integer to insert: ";
            number = checkInput();
            std::cout << "Enter location of the integer you would " <<
                                "like to replace: ";
            location = checkInput();

            intList.replaceAt(location, number);
            printAfterAction(intList);
        } else if (userInput == '6') {
            // Perform SeqSearch
            std::cout << "Enter the integer you would like to find: ";
            number = checkInput();
            int loc;
            loc = intList.seqSearch(number);
            if (loc == -1)
                std::cout << "Your number was not found" << std::endl;
            else
                std::cout << "The set index of your number is " << loc
                             << std::endl;
        } else if (userInput == '7') {
            // Print list
            // I'd like to put a length check here but I don't know its scope
            printAfterAction(intList);
        } else if (userInput == '8') {
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

void printAfterAction(unorderedSetType const userList) {
    std::cout << "Your set: " << std::endl;
    userList.print();
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
