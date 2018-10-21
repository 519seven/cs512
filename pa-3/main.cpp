// Copyright 2018 Peter Akey
// Modified as needed from C++ Programming by D.S. Malik 8th Edition

#include <iostream>
#include <sstream>
#include "newClock.h"

// I'm only including three separate classes because the assignment said so:
// Your program must contain three exception classes: invalidHr...and so on...
class invalidHr {
 public:
    invalidHr() {
        // default
        message = "The value entered for hours was not able to be processed";
        std::cout << "invalidHr exception thrown!" << std::endl;
    }
    invalidHr(std::string msg) {
        // overload when a string is given
        message = msg;
        std::cout << "invalidHr exception thrown!" << std::endl;
    }
    std::string what() {
        return message;
    }
 private:
    std::string message;
};
class invalidMin {
 public:
    invalidMin() {
        // default
        message = "The value entered for minutes was not able to be processed";
        std::cout << "invalidMin exception thrown!" << std::endl;
    }
    invalidMin(std::string msg) {
        // overload when a string is given
        message = msg;
        std::cout << "invalidMin exception thrown!" << std::endl;
    }
    std::string what() {
        return message;
    }
 private:
    std::string message;
};
class invalidSec {
 public:
    invalidSec() {
        // default
        message = "The value entered for seconds was not able to be processed";
        std::cout << "invalidSec exception thrown!" << std::endl;
    }
    invalidSec(std::string msg) {
        // overload when a string is given
        message = msg;
        std::cout << "invalidSec exception thrown!" << std::endl;
    }
    std::string what() {
        return message;
    }
 private:
    std::string message;
};

// prototype the functions
void getUserInput();

// main
int main() {
    getUserInput();
    return 0;
}

// get user input
void getUserInput() {
    clockType yourClock;
    std::string userInput;
    int timeArray[3] = {0, 0, 0};
    std::string amorpm;
    int i = 0;  // Need to define here so we can use it in 'catch'
    std::string token;  // Need to define here so we can use it in 'catch'

    std::string littleToken;
    std::size_t found;

    try {
        std::cout << "Enter time of day in 12-hour notation: ";
        std::getline(std::cin, userInput);
        found = userInput.find(":");
        if (found != std::string::npos) {
            std::istringstream ss(userInput);
            while (std::getline(ss, token, ' ')) {
                // assuming user entered AM or PM at the end split on space 1st
                // if we only split on : then the last "token" is "<ss> <am|pm>"
                std::istringstream subtoken(token);
                found = token.find(":");
                if (found != std::string::npos) {
                    // if the string has : in it, process it
                    while (std::getline(subtoken, littleToken, ':')) {
                        try {
                            timeArray[i] = std::stoi(littleToken);
                            i++;
                            if (i == 1) {
                                if (timeArray[0] > 12) {
                                    std::cout << "I'm looking for the time in "
                                                << "12-hour notation.  The "
                                                << "hour value you entered "
                                                << "is greater than 12"
                                                << std::endl;
                                    throw invalidHr();
                                }
                            }
                        } catch (std::logic_error le) {
                            if (i == 0)
                                throw invalidHr();
                            else if (i == 1)
                                throw invalidMin();
                            else if (i == 2)
                                throw invalidSec();
                        }
                    }
                } else {
                    // assign the token each time through
                    // the last time through ought to have the token
                    amorpm = token;
                }
            }
            if (token == "am" || token == "AM" ||
                 token == "pm" || token == "PM" ||
                 token == "a.m." || token == "A.M." ||
                 token == "p.m." || token == "P.M." ) {
                if (token == "am" || token == "AM" ||
                     token == "a.m." || token == "A.M.") {
                    amorpm = "A.M.";
                } else if (token == "pm" || token == "PM" ||
                            token == "p.m." || token == "P.M.") {
                    amorpm = "P.M.";
                    timeArray[0] += 12;
                }
                yourClock.setTime(timeArray[0], timeArray[1], timeArray[2]);

                std::cout << "Your clock in 24-hour notation is: "
                            << yourClock << std::endl;
            } else {
                std::cout << "AM/PM entry was not able to be processed.  "
                            << "Terminating program..." << std::endl;
            }
        } else {
            std::cout << "I am expecting to find at least one space between "
                        << "the time (hh:mm:ss) and either A.M. or P.M.  "
                        << "Double check your entry" << std::endl;
        }
    } catch (invalidHr& e) {
        std::cout << e.what() << std::endl;
    } catch (invalidMin& e) {
        std::cout << e.what() << std::endl;
    } catch (invalidSec& e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "General error.  Terminating program" << std::endl;
    }
}
