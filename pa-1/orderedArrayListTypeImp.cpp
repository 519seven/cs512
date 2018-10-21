// Copyright 2018 Peter Akey
// Modified as needed from C++ Programming by D.S. Malik 8th Edition

#include <iostream>
#include "orderedArrayListType.h"

void orderedArrayListType::insertAt(int location, int insertItem) {}
void orderedArrayListType::insertEnd(int insertItem) {}
void orderedArrayListType::replaceAt(int location, int repItem) {}

int orderedArrayListType::seqSearch(int searchItem) const {
    int i;

    if (length == 0) {
        std::cout << "Your array is empty!" << std::endl;
        return -1;
    }

    for (i = 0; i < length; i++) {
        if (list[i] == searchItem) {
            std::cout << "Your integer has been found!  It's element # ";
            std::cout << (i+1) << " (index " << i << ")" << std::endl;
            return i;
        }
    }
    std::cout << "Your integer was not found :(" << std::endl;
    return -1;
}  // end seqSearch

void orderedArrayListType::insert(int insertItem) {
    if (length == 0) {                  // list is empty
        list[length++] = insertItem;    // insert insertItem
                                        // and increment length
        std::cout << insertItem << " inserted into list" << std::endl;
    } else if (length == maxSize) {
        std::cout << "Cannot insert in a full list." << std::endl;
    } else {
        int index;
        bool found = false;

        for (index = 0; index < length; index++) {
            if (list[index] == insertItem) {
                std::cout << "Element found to be in your list already. ";
                std::cout << "Skipping insert." << std::endl;
                found = true;
                break;
            } else if (list[index] > insertItem) {
                break;
            }
        }
        if (!found) {
            for (int i = length; i > index; i--)
                 list[i] = list[i - 1];     // move the elements down

            list[index] = insertItem;       // insert insertItem
            std::cout << insertItem << " inserted into list" << std::endl;

            length++;   // increment the length
        }
    }
}  // end insert

void orderedArrayListType::remove(int removeItem) {
    int intLoc;
    int i;

    intLoc = seqSearch(removeItem);
    if (intLoc != -1 && length != 0) {
        std::cout << "Removing element..." << std::endl;
        for (i = intLoc; i < length; i++) {
            list[i] = list[i+1];
        }
        length--;  // decrement the length
        std::cout << "done!" << std::endl;
    } else if (length == 0) {
        std::cout << "I cannot empty an array that contains nothing. ";
        std::cout << "Try another option." << std::endl;
    }
}  // end remove

orderedArrayListType::orderedArrayListType(int size) {}  // end constructor
orderedArrayListType::~orderedArrayListType() {}  // end destructor
