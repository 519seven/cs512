// Copyright 2018 Peter Akey
// Modified as needed from C++ Programming by D.S. Malik 8th Edition

#include <iostream>
#include <sstream>
#include <limits>

#include "unorderedArrayListType.h"

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
int checkInputInt(std::string s);

// get user input
void runProgram() {
    unorderedArrayListType<int> originalList, copy1, copy2;

    int userInput = 0;
    int loopCount = 0;
    std::string msg = "";

    try {
        std::cout << std::endl << "Welcome to HWNUMBER" << std::endl;
        msg = "How many times would you like to sort your lists?";
        loopCount = checkInputInt(msg);

        // Initlialize the first list with random integers
        originalList.populateRandomly();
        originalList.print();
        // make two copies, one for each sorting algorithm
        copy1 = originalList;
        copy2 = originalList;



        std::cout << "All done!  Exiting." << std::endl;
    } catch (invalidEntry& e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "General error.  Terminating program" << std::endl;
    }
}

// main
int main() {
    runProgram();
    return 0;
}

int checkInputInt(std::string strMsg) {
    int num;
    while (true) {
        std::cout << strMsg << ": ";
        std::cin >> num;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "The value entered doesn't appear to be an integer."
                    << std::endl;
        } else {
            return num;
        }
    }
}
