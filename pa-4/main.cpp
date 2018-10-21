// Copyright 2018 Peter Akey
// Modified as needed from C++ Programming by D.S. Malik 8th Edition

#include <iostream>
#include <sstream>
#include <limits>

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
bool isPal(const std::string, int, int);
int gcd(int, int);
std::string checkInputStr();
int checkInputInt(std::string);
std::string shortenString(std::string);

// main
int main() {
    runProgram();
    return 0;
}

// get user input
void runProgram() {
    char userInput = 0;
    try {
        while (userInput != '3') {
            std::cout << "Choose a program: "
                        << std::endl;
            std::cout << "   1 - Run the palindrome" << std::endl;
            std::cout << "   2 - Run the GCD" << std::endl;
            std::cout << "   3 - Quit" << std::endl;
            std::cin >> userInput;

            if (userInput == '1') {
                // Run the palindrome
                std::cout << "Enter your string to test if it's a palindrome: ";
                std::string pString;
                pString = checkInputStr();
                bool pal = isPal(pString, 0, pString.length()-1);
                if (pal) {
                    std::cout << "Your string " << pString << " IS a palindrome"
                                << std::endl << std::endl;
                } else {
                    std::cout << "Your string " << pString << " IS NOT a "
                                << "palindrome" << std::endl << std::endl;
                }
            } else if (userInput == '2') {
                // Find the greatest common denominator
                int x, y, theGCD;
                x = y = 0;
                try {
                    x = checkInputInt("x");
                } catch (invalidEntry& e) {
                    throw invalidEntry();
                }
                try {
                    y = checkInputInt("y");
                } catch (invalidEntry& e) {
                    throw invalidEntry();
                }
                theGCD = gcd(x, y);
                std::cout << "The GCD for " << x << " and " << y << " is: "
                            << theGCD << std::endl << std::endl;
            } else if (userInput == '3') {
                // Terminate program
                std::cout << "Terminating program." << std::endl;
                break;
            } else {
                std::cout << "Invalid entry. Select an option from the list below:";
                std::cout << std::endl;
            }
        }
    } catch (invalidEntry& e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "General error.  Terminating program" << std::endl;
    }
}

bool isPal(const std::string p, int start, int end) {
    // if the start is greater than the end
    // we've gone past the middle of the string
    if (start >= end ) { return true; }
    if (p[start] != p[end]) {
        return false;
    }
    return isPal(p, ++start, --end);
}

int gcd(int x, int y) {
    if (y == 0) { return x; }
    if (y != 0) { return gcd(y,x%y); }
    return false;
}

std::string shortenString(std::string p) {
    // create a new string based on size of entered string (dynamic)
    std::string s;
    // loop and discard the first and last characters of string
    for (std::string::size_type i = 0; i < p.size()-1; i++){
        //std::cout << "i=" << i << std::endl;
        if (i != 0)
            s += p[i];
    }
    // return shortened string to calling function
    return s;
}

std::string checkInputStr() {
    std::string palindrome;
    while (!(std::cin >> palindrome)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "You entered " << palindrome << std::endl;
        std::cout << "Invalid input, try again." << std::endl;
        std::cout << "Enter string to test if it's a palindrome: ";
    }
    return palindrome;
}

int checkInputInt(std::string strGet) {
    int num;
    std::cout << "Enter " << strGet << ": " << std::endl;
    std::cin >> num;
    while(!std::cin) {
        std::cout << "That was no integer! Please enter an integer: " 
                    << std::endl;
        std::cin.clear();
        std::cin.ignore();
        std::cin >> num;
    }
    return num;
}
