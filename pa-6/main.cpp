// Copyright 2018 Peter Akey
// Modified as needed from C++ Programming by D.S. Malik 8th Edition

#include <iostream>
#include <sstream>
#include <limits>
#include "queueAsArray.h"

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
int checkInputInt(std::string);

// main
int main() {
    runProgram();
    return 0;
}

// get user input
void runProgram() {
    queueType<int> queue1, queue2;

    int userInput = 0;
    try {
        do {
            std::cout << std::endl << "Welcome to PA-6 - Queue As Array"
                        << std::endl;
            std::cout << "   1 - enqueue" << std::endl;
            std::cout << "   2 - dequeue" << std::endl;
            std::cout << "   3 - copy queue" << std::endl;
            std::cout << "   4 - print the original queue" << std::endl;
            std::cout << "   5 - print the copy queue" << std::endl;
            std::cout << "   6 - debug queue" << std::endl;
            std::cout << "   7 - quit" << std::endl;
            userInput = checkInputInt("Make your selection");

            if (userInput == 1) {
                // enqueue
                int info;
                info = checkInputInt("Enter your new item");
                queue1.enqueue(info);
                std::cout << info << " has been inserted into the beginning "
                            << "of your list." << std::endl;
            } else if (userInput == 2) {
                // dequeue
                std::cout << "You've chosen to dequeue" << std::endl;
                queue1.dequeue();
            } else if (userInput == 3) {
                // copy queue
                std::cout << "Copying queue..." << std::endl;
                queue2 = queue1;
                std::cout << "Done!" << std::endl;
            } else if (userInput == 4) {
                // print the original queue
                std::cout << "Your primary queue contains the "
                            << "following elements" << std::endl;
                queue1.printQueue();
            } else if (userInput == 5) {
                // print the copy queue
                std::cout << "Printing the copied queue:" << std::endl;
                queue2.printQueue();
            } else if (userInput == 6) {
                // debug queue
                std::cout << std::endl << "*********************" << std::endl;
                std::cout << "queue1 debug info:" << std::endl;
                queue1.debugQueue();
                std::cout << std::endl << "*********************" << std::endl;
                std::cout << "queue2 debug info:" << std::endl;
                queue2.debugQueue();
            } else if (userInput != 7) {
                std::cout << "Invalid entry. Select an option from the list:"
                        << std::endl;
            }
        } while (userInput != 7);
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
                    << "outside of the range of an acceptable integer."
                    << std::endl;
        } else {
            return num;
        }
    }
}
