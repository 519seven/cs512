#ifndef H_orderedArrayListType
#define H_orderedArrayListType

#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iostream>
#include <limits>
#include <random>
#include <signal.h>
#include <sstream>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>                                     // for getpid

#include "arrayListType.h"

template <class Type>
class orderedArrayListType: public arrayListType<Type> {
public:
    const orderedArrayListType<Type>& operator=(const orderedArrayListType<Type>&);
    // Overload the assignment operator.
    void insertAt(int location, Type& insertItem);
    void insertEnd(Type& insertItem, const bool f);
    void replaceAt(int location, Type& repItem);
    int seqSearch(Type& searchItem);
    int binSearch(Type& searchItem);
    void remove(Type& removeItem);
    void populateRandomly();
    int minLocation(int f, int e);
    void swap(int f, int s);
    void selectionSort ();
    void insertionSort ();
    int printComps();
    int printSwaps();
    void printStats(bool c, bool s);

    orderedArrayListType(int size = LISTITEMS);               // Constructor

 protected:
    int keyComparisons;
    int numberOfSwaps;
};

// begin populateRandomly
template <class Type>
void orderedArrayListType<Type>::populateRandomly() {
    this->length = 0;
    // To test some things, I added a "force" for insertEnd
    // In general, it ought to be false but sometimes I want to stick something
    //             on the end so I can easily identify my array
    bool force = false;
    int r = 0;
    while (this->length < this->maxSize) {
        r = rand()%1000;
        insertEnd(r, force);
    }
} // end populateRandomly

// begin insertAt
template <class Type>
void orderedArrayListType<Type>::insertAt(int location, Type& insertItem) {
    if (location < 0 || location >= this->maxSize)
        std::cout << "The position of the item to be inserted "
             << "is out of range." << std::endl;
    else if (this->length >= this->maxSize) {                      // list is full
        std::cout << "Cannot insert in a full list" << std::endl;
    } else {
        for (int i = this->length; i > location; i--)
            this->list[i] = this->list[i - 1];                     // move the elements down

        this->list[location] = insertItem;                   // insert the item at
                                                       // the specified position

        this->length++;                                     // increment the length
    }
} // end insertAt

// begin insertEnd
template <class Type>
void orderedArrayListType<Type>::insertEnd(Type& insertItem, const bool force) {
    if (this->length >= this->maxSize && ! force) {         // the list is full
        std::cout << "Cannot insert in a full list." << std::endl;
    } else if (this->length >= this->maxSize && force) {    // force it in
        this->list[this->length-1] = insertItem;
    } else {
        this->list[this->length] = insertItem;              // insert at the end
        this->length++;                                     // incnt the length
    }
} // end insertEnd

// begin remove
template <class Type>
void orderedArrayListType<Type>::remove(Type& removeItem) {
    int loc;

    if (this->length == 0) {
        std::cout << "Cannot delete from an empty list." << std::endl;
    } else {
        loc = seqSearch(removeItem);

        if (loc != -1)
            this->removeAt(loc);
        else
            std::cout << "The item to be deleted is not in the list."
                 << std::endl;
    }
} // end remove

// begin replaceAt
template <class Type>
void orderedArrayListType<Type>::replaceAt(int location, Type& repItem) {
    if (location < 0 || location >= this->length)
        std::cout << "The location of the item to be "
             << "replaced is out of range." << std::endl;
    else
        this->list[location] = repItem;
} // end replaceAt

// *****************************************************************************
// Searching algorithms
// begin seqSearch
template <class Type>
int orderedArrayListType<Type>::seqSearch(Type& searchItem) {
    int loc;
    bool found = false;

    loc = 0;

    while (loc < this->length && !found)
        if (this->list[loc] == searchItem)
            found = true;
        else
            loc++;

    if (found)
        return loc;
    else
        return -1;
} // end seqSearch

// begin binSearch
template <class Type>
int orderedArrayListType<Type>::binSearch(Type& item) {
    this->keyComparisons = 0;
    this->numberOfSwaps = 0;
    int first = 0;
    int last = this->length - 1;
    int mid;

    bool found = false;

    while (first <= last && !found) {
        this->keyComparisons++;
        mid = (first + last) / 2;
        if (this->list[mid] == item)
            found = true;
        else if (this->list[mid] > item)
            last = mid - 1;
        else
            first = mid + 1;
    }

    if (found)
        return mid;
    return -1;
}  // end binSearch

// *****************************************************************************
// Sorting Algorithms
// begin minLocation for Selection Sort
template <class Type>
int orderedArrayListType<Type>::minLocation(int first, int last) {
  int minIndex;
  minIndex = first;

  for (int loc = first + 1; loc <= last; loc++)
    if (this->list[loc] < this->list[minIndex]) {
      minIndex = loc;
      this->keyComparisons++;
    }
  return minIndex;
} // end minLocation

// begin swap for Selection Sort
template <class Type>
void orderedArrayListType<Type>::swap(int first, int second) {
  Type temp;

  temp = this->list[first];
  this->list[first] = this->list[second];
  this->list[second] = temp;
  this->numberOfSwaps++;
} // end swap

// begin selectionSort
template <class Type>
void orderedArrayListType<Type>::selectionSort() {
  int minIndex;
  this->keyComparisons = 0;
  this->numberOfSwaps = 0;

  for (int loc = 0; loc < this->length; loc++) {
    minIndex = minLocation(loc, this->length - 1);
    swap(loc, minIndex);
  }
} // end selectionSort

// begin insertionSort
template <class Type>
void orderedArrayListType<Type>::insertionSort() {
    // reset stats from any other sorting that has occurred
    this->keyComparisons = 0;
    this->numberOfSwaps = 0;

    // OOO = "OutOfOrder"
    for (int firstOOO = 1; firstOOO < this->length; firstOOO++) {
        if (this->list[firstOOO] < this->list[firstOOO - 1]) {
            keyComparisons++;
            Type temp = this->list[firstOOO];
            int loc = firstOOO;

            do {
                this->list[loc] = this->list[loc - 1];
                numberOfSwaps++;
                loc--;
            } while (loc > 0 && this->list[loc - 1] > temp);

            this->list[loc] = temp;
        }
    }
} // end insertionSort
// *****************************************************************************

// *****************************************************************************
// Print Statistics

// begin printComps
template <class Type>
int orderedArrayListType<Type>::printComps() {
    return this->keyComparisons;
} // end printComps

// begin printSwaps
template <class Type>
int orderedArrayListType<Type>::printSwaps() {
    return this->numberOfSwaps;
} // end printSwaps

// begin printStats
template <class Type>
void orderedArrayListType<Type>::printStats(bool comps, bool swaps) {
    if (comps)
        std::cout << "Number of comparisons: " << this->printComps()
                    << std::endl;
    if (swaps)
        std::cout << "Number of swaps      : " << this->printSwaps()
                    << std::endl << std::endl;
} // end printStats
// *****************************************************************************

// *****************************************************************************
// Overloading

// = operator
template <class Type>
const orderedArrayListType<Type>& orderedArrayListType<Type>::operator=
                       (const orderedArrayListType<Type>& otherArray) {
    // Check that I'm not copying it to itself
    if (this != &otherArray) {
        // delete existing queue
        delete [] this->list;
        this->maxSize = otherArray.maxSize;
        this->length = otherArray.length;
        this->list = new int[this->maxSize];
        for (int i = 0; i < this->length; i++)
            this->list[i] = otherArray.list[i];
    }
    return *this;
}  // end = operator
// *****************************************************************************

// begin constructor
template <class Type>
orderedArrayListType<Type>::orderedArrayListType(int size)
                       : arrayListType<Type>(size)
{ } // end constructor

#endif
