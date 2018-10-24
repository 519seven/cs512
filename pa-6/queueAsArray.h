// Copyright 2018 Peter Akey
// Modified as needed from C++ Programming by D.S. Malik 8th Edition

#ifndef H_QueueAsArray
#define H_QueueAsArray

#include <iostream>
#include <cassert>

#include "queueADT.h"

template <class Type>
class queueType: public queueADT<Type> {
 public:
    const queueType<Type>& operator=(const queueType<Type>&);
      // Overload the assignment operator.

    bool isEmptyQueue() const;
      // Function to determine whether the queue is empty.
      // Postcondition: Returns true if the queue is empty,
      //                otherwise returns false.

    bool isFullQueue() const;
      // Function to determine whether the queue is full.
      // Postcondition: Returns true if the queue is full,
      //                otherwise returns false.

    void initializeQueue();
      // Function to initialize the queue to an empty state.
      // Postcondition: The queue is empty.

    Type front() const;
      // Function to return the first element of the queue.
      // Precondition: The queue exists and is not empty.
      // Postcondition: If the queue is empty, the program
      //                terminates; otherwise, the first
      //                element of the queue is returned.

    Type back() const;
      // Function to return the last element of the queue.
      // Precondition: The queue exists and is not empty.
      // Postcondition: If the queue is empty, the program
      //                terminates; otherwise, the last
      //                element of the queue is returned.

    void enqueue(const Type& queueElement);
      // Function to add queueElement to the queue.
      // Precondition: The queue exists and is not full.
      // Postcondition: The queue is changed and queueElement
      //                is added to the queue.

    void dequeue();
      // Function to remove the first element of the queue.
      // Precondition: The queue exists and is not empty.
      // Postcondition: The queue is changed and the first
      //                element is removed from the queue.

    void debugQueue() const;
      // Function to show properties of the queue for debugging purposes

    void printQueue() const;
      // Function to print contents of queueAsArray

    queueType(int queueSize = 100);
      // Constructor

    queueType(const queueType<Type>& otherQueue);
      // Copy constructor

    ~queueType();
      // Destructor

 private:
    int maxQueueSize;  // variable to store the maximum queue size
    int count;         // variable to store the number of
                       // elements in the queue
    int queueFront;    // variable to point to the first
                       // element of the queue
    int queueRear;     // variable to point to the last
                       // element of the queue
    Type *q;           // pointer to the array that holds
                       // the queue elements
};

#endif
