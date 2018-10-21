// Copyright 2018 Peter Akey
// Modified as needed from C++ Programming by D.S. Malik 8th Edition

#include <iostream>
#include "unorderedSetType.h"

void unorderedSetType::insertAt(int location,
                                      int insertItem) {
    if (location < 0 || location >= maxSize) {
        std::cout << "The position of the item to be inserted "
             << "is out of range." << std::endl;
    } else if (length >= maxSize) {     // list is full
        std::cout << "Cannot insert in a full list" << std::endl;
    } else {
        int exists = 0;
        exists = seqSearch(insertItem);
        if (exists == -1) {
            for (int i = length; i > location; i--)
                list[i] = list[i - 1];      // move the elements down

            list[location] = insertItem;    // insert the item at
                                            // the specified position

            length++;                       // increment the length
            std::cout << "Your item has been inserted" << std::endl;
        } else {
            std::cout << "Your item is already present in your set!"
                    << "  No changes have been made." << std::endl;
        }
    }
}  // end insertAt

void unorderedSetType::insertEnd(int insertItem) {
    if (length >= maxSize) {           // the list is full
        std::cout << "Cannot insert in a full list." << std::endl;
    } else {
        int loc;
        loc = seqSearch(insertItem);
        if (loc == -1) {
            list[length] = insertItem;    // insert the item at the end
            length++;                     // increment the length
        } else {
            std::cout << "Your set already contains this item." << std::endl;
        }
    }
}  // end insertEnd

int unorderedSetType::seqSearch(int searchItem) const {
    int loc;
    bool found = false;

    loc = 0;

    while (loc < length && !found) {
        if (list[loc] == searchItem) {
            found = true;
            break;
        } else {
            loc++;
        }
    }

    if (found)
        return loc;
    else
        return -1;
}  // end seqSearch


void unorderedSetType::remove(int removeItem) {
    int loc;

    if (length == 0) {
        std::cout << "Cannot delete from an empty list." << std::endl;
    } else {
        loc = seqSearch(removeItem);

        if (loc != -1) {
            removeAt(loc);
            std::cout << "Your item has been removed." << std::endl;
        } else {
            std::cout << "The item to be deleted is not in the list."
                 << std::endl;
        }
    }
}  // end remove

void unorderedSetType::replaceAt(int location, int repItem) {
    if (location < 0 || location >= length) {
        std::cout << "The location of the item to be "
             << "replaced is out of range." << std::endl;
    } else {
        if (seqSearch(repItem) == -1) {
            list[location] = repItem;
            std::cout << "Your new item " << repItem << " has replaced the one "
                       << "previously found at index " << location << std::endl;
        } else {
            std::cout << "Your set already contains this item." << std::endl;
        }
    }
}  // end replaceAt

unorderedSetType::unorderedSetType(int size)
                       : unorderedArrayListType(size) {}      // end constructor

unorderedSetType::~unorderedSetType() {}                      // end destructor

