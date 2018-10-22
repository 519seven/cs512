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

template <class Type>
bool queueType<Type>::isEmptyQueue() const {
    return (count == 0);
}  // end isEmptyQueue

template <class Type>
bool queueType<Type>::isFullQueue() const {
    return (count == maxQueueSize);
}  // end isFullQueue

template <class Type>
void queueType<Type>::initializeQueue() {
    queueFront = 0;
    queueRear = maxQueueSize - 1;
    count = 0;
}  // end initializeQueue

// Pointer to the front of the queue
template <class Type>
Type queueType<Type>::front() const {
    assert(!isEmptyQueue());
    return q[queueFront];
}  // end front

// Pointer to the rear of the queue
template <class Type>
Type queueType<Type>::back() const {
    assert(!isEmptyQueue());
    return q[queueRear];
}  // end back

// Add to the queue
template <class Type>
void queueType<Type>::enqueue(const Type& newElement) {
    if (!isFullQueue()) {
        queueRear = (queueRear + 1) % maxQueueSize;
                            // use mod operator to advance queueRear
                            // because the array is circular
        count++;
        q[queueRear] = newElement;
    } else {
        std::cout << "Cannot add to a full queue." << std::endl;
    }
}  // end enqueue

// Remove from queue
template <class Type>
void queueType<Type>::dequeue() {
    if (!isEmptyQueue()) {
        count--;
        queueFront = (queueFront + 1) % maxQueueSize;  // use the
                                        // mod operator to advance queueFront
                                        // because the array is circular
    } else {
        std::cout << "Cannot remove from an empty queue." << std::endl;
    }
}  // end dequeue

// Debug queue
template <class Type>
void queueType<Type>::debugQueue() const {
    if (count > 0) {
      std::cout << std::endl;
      std::cout << "-------Debug Info-------" << std::endl;
      std::cout << "--Your Queue Contains:--" << std::endl;
      printQueue();
      std::cout << "-------Queue Info-------" << std::endl;
      std::cout << "maxQueueSize = " << maxQueueSize << std::endl;
      std::cout << "item count = " << count << std::endl;
      std::cout << "queueFront = " << queueFront << std::endl;
      std::cout << "Front item = " << q[queueFront] << std::endl;
      std::cout << "queueRear = " << queueRear << std::endl;
      std::cout << "Rear item = " << q[queueRear] << std::endl;
      std::cout << "-----End Debug Info-----" << std::endl << std::endl;
    } else {
      std::cout << "Your queue is empty." << std::endl;
    }
}  // end debugQueue

// Print queue
template <class Type>
void queueType<Type>::printQueue() const {
    if (count != 0) {
        for (int i = queueFront; i < queueRear+1; i++)
            std::cout << q[i] << " ";
        std::cout << std::endl;
    } else {
        std::cout << "<empty>" << std::endl;
    }
}  // end printQueue

// Constructor
template <class Type>
queueType<Type>::queueType(int queueSize) {
    if (queueSize <= 0) {
        std::cout << "Size of the array to hold the queue must "
             << "be positive." << std::endl;
        std::cout << "Creating an array of size 100." << std::endl;

        maxQueueSize = 100;
    } else {
        maxQueueSize = queueSize;   // set maxQueueSize to
                                    // queueSize
    }
    queueFront = 0;                 // initialize queueFront
    queueRear = maxQueueSize - 1;   // initialize queueRear
    count = 0;
    q = new Type[maxQueueSize];  // create the array to
                                    // hold the queue elements
}  // end constructor

// Destructor
template <class Type>queueType<Type>::~queueType() {
    delete [] q;
}  // end destructor

// Overloading the assignment operator
template <class Type>
const queueType<Type>& queueType<Type>::operator=
                       (const queueType<Type>& otherQueue) {
    // Check that I'm not copying it to itself
    if (this != &otherQueue) {
        // delete existing queue
        delete [] q;
        maxQueueSize = otherQueue.maxQueueSize;
        queueFront = otherQueue.queueFront;
        queueRear = otherQueue.queueRear;
        count = otherQueue.count;
        q = new int[maxQueueSize];
        for (int i = queueFront; i < queueRear+1; i++)
            q[i] = otherQueue.q[i];
    }
    return *this;
}  // end assignment operator

// Copy constructor
template <class Type>
queueType<Type>::queueType(const queueType<Type>& otherQueue) {
    // check to make sure this isn't the same object
    if (this != &otherQueue) {
        // delete existing queue
        delete [] q;
        maxQueueSize = otherQueue.maxQueueSize;
        queueFront = otherQueue.queueFront;
        queueRear = otherQueue.queueRear;
        count = otherQueue.count;
        q = new int[maxQueueSize];
        for (int i = queueFront; i < queueRear+1; i++)
            q[i] = otherQueue.q[i];
    }
}  // end copy constructor

#endif
