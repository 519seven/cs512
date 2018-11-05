// Copyright 2018 Peter Akey
// Modified as needed from C++ Programming by D.S. Malik 8th Edition

#include "orderedArrayListType.h"               // Ordered array stuff

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
bool checkInputBool(std::string s, char t, char f);
    // Look for chars t or f and return true or false
void theSortingPart(int cnt, bool pf);
void theSearchingPart(int cnt, bool pf);

// Declaring these globally...may not be ideal
// I'm trying to clean up this codebase by creating smaller routines
orderedArrayListType<int> originalList, copy1, copy2;

// get user input
void runProgram() {
    std::string hw_no = "PA-7 Sorting and Searching";
    std::string my_name = "Peter Akey";
    std::string msg = "";
    int subCnt = 0;
    bool printFirstElements = true;

    try {
        std::cout << std::endl << "Welcome to " << hw_no << std::endl;
        msg = "Before we get started, I'd like to know if you would "
                "like to print\na subset of the array in question "
                "before each step? [y/N]";
        if (checkInputBool(msg, 'y', 'n')) {
            msg = "How many array items would you like to see printed?";
            subCnt = checkInputInt(msg);
            msg = "Lastly, shall I print the [f]irst or the [l]ast "
                    +std::to_string(subCnt)+
                    " items of the array?";
            printFirstElements = checkInputBool(msg, 'f', 'l');
        }
        std::cout << std::endl << "First, the sorting part..." << std::endl;
        theSortingPart(subCnt, printFirstElements);
        std::cout << std::endl << "And now, the searching part..." << std::endl;
        theSearchingPart(subCnt, printFirstElements);
        std::cout << std::endl << "I, " << my_name << ", thank you for playing."
                    << std::endl;
        std::cout << "Terminating program!" << std::endl;
    } catch (invalidEntry& e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "General error.  Terminating program" << std::endl;
    }
}

// main
int main() {
    struct timeval t1;
    gettimeofday(&t1, NULL);
    srand(t1.tv_usec * t1.tv_sec * getpid());

    runProgram();
    return 0;
}

// theSearchingPart
void theSearchingPart(int sc, bool pFirst) {
    std::string msg = "";
    int whatToLookFor = 0;

    while (1) {
        if (sc > 0) { copy1.print(sc, true); copy1.print(sc, false); }
        msg = "What would you like me to look for? (\"0\" exits the program)";
        whatToLookFor = checkInputInt(msg);
        std::cout << std::endl;
        if (whatToLookFor == 0) { break; }
        if (copy1.doBinary(whatToLookFor) != -1) {
            std::cout << whatToLookFor << " was found." << std::endl;
            copy1.printStats(true, false);
        } else {
            std::cout << whatToLookFor << " was not found.  " << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "It looks like we're done here." << std::endl;
}

// theSortingPart
void theSortingPart(int sc, bool pFirst) {
    int loopCount = 0;
    std::string msg = "";
    //int forceItem = 1111;
    //bool force = true;

    msg = "How many times would you like to sort your lists?";
    loopCount = checkInputInt(msg);
    std::cout << std::endl << "You've chosen to run through sorting "
                << loopCount << " times." << std::endl;

    for (int i=1; i <= loopCount; i++) {
        // Initlialize the first list with random integers
        originalList.populateRandomly();
        copy1 = originalList;
        copy2 = originalList;
        //originalList.insertEnd(++forceItem, force);
        //copy1.insertEnd(++forceItem, force);
        //copy2.insertEnd(++forceItem, force);
        std::cout << "## LOOP #" << i
                    << "------------------------------------------------"
                    << "-----------------------" << std::endl;
        if (sc > 0) {
            copy1.print(sc, pFirst);
        }
        copy1.selectionSort();
        std::cout << "___Selection Sort___" << std::endl;
        if (sc > 0) {
            copy1.print(sc, pFirst);
        }
        copy1.printStats(true, true);
        copy2.insertionSort();
        std::cout << "___Insertion Sort___" << std::endl;
        if (sc > 0) {
            copy1.print(sc, pFirst);
        }
        copy2.printStats(true, true);
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
            std::cout << "The value entered doesn't appear to be an integer."
                    << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return num;
        }
    }
}

bool checkInputBool(std::string strMsg, char theTrueOne, char theFalseOne) {
    char c;

    while (true) {
        std::cout << strMsg << ": ";
        std::cin >> c;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "The value entered doesn't appear to be '"
                        << theTrueOne << "'' or '"
                        << theFalseOne << "'" << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            c = tolower(c);
            if (c != theTrueOne && c != theFalseOne) {
                std::cout << std::endl << "Please enter '"
                            << theTrueOne << "' or '"
                            << theFalseOne << "'" << std::endl;
            } else {
                if (c == theTrueOne)
                    return true;
                else
                    return false;
            }
        }
    }
}
