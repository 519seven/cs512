#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <stdlib.h>
#include <unistd.h>                                     // for getpid
#include <stdio.h>
#include <signal.h>
#include <time.h>

#include "unorderedArrayListType.h"

// begin populateRandomly
template <class Type>
void unorderedArrayListType<Type>::populateRandomly() {
    // Call rand
    //timeval tim;
    //gettimeofday(&tim, NULL);
    srand(time(0) * getpid());
    while (this.length < this.maxSize) {
        this.insertEnd(rand());
    }
} // end populateRandomly

// begin insertAt
template <class Type>
void unorderedArrayListType<Type>::insertAt(int location, Type& insertItem) {
    if (location < 0 || location >= this.maxSize)
        std::cout << "The position of the item to be inserted "
             << "is out of range." << std::endl;
    else if (this.length >= this.maxSize) {                      // list is full
        std::cout << "Cannot insert in a full list" << std::endl;
    } else {
        for (int i = this.length; i > location; i--)
            this.list[i] = this.list[i - 1];                     // move the elements down

        this.list[location] = insertItem;                   // insert the item at
                                                       // the specified position

        this.length++;	                                   // increment the length
    }
} // end insertAt

// begin insertEnd
template <class Type>
void unorderedArrayListType<Type>::insertEnd(Type& insertItem) {
    if (this.length >= this.maxSize) {                           // the list is full
        std::cout << "Cannot insert in a full list." << std::endl;
    } else {
        this.list[this.length] = insertItem;                     //insert at the end
        this.length++;                                      // increment the length
    }
} // end insertEnd

// begin seqSearch
template <class Type>
int unorderedArrayListType<Type>::seqSearch(Type& searchItem) const {
    int loc;
    bool found = false;

    loc = 0;

    while (loc < this.length && !found)
        if (this.list[loc] == searchItem)
            found = true;
        else
            loc++;

    if (found)
        return loc;
    else
        return -1;
} // end seqSearch

// begin remove
template <class Type>
void unorderedArrayListType<Type>::remove(Type& removeItem) {
    int loc;

    if (this.length == 0) {
        std::cout << "Cannot delete from an empty list." << std::endl;
    } else {
        loc = this.seqSearch(removeItem);

        if (loc != -1)
            this.removeAt(loc);
        else
            std::cout << "The item to be deleted is not in the list."
                 << std::endl;
    }
} // end remove

// begin replaceAt
template <class Type>
void unorderedArrayListType<Type>::replaceAt(int location, Type& repItem) {
    if (location < 0 || location >= this.length)
        std::cout << "The location of the item to be "
             << "replaced is out of range." << std::endl;
    else
        this.list[location] = repItem;
} // end replaceAt

// begin constructor
template <class Type>
unorderedArrayListType<Type>::unorderedArrayListType(int size)
                       : arrayListType<Type>(size)
{ } // end constructor


