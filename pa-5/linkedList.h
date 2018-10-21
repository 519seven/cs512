// Copyright 2018 Peter Akey
// Modified as needed from C++ Programming by D.S. Malik 8th Edition

#ifndef H_LinkedListType
#define H_LinkedListType

#include <iostream>
#include <cassert>

// Definition of the node
template <class Type>
struct nodeType {
    Type info;
    nodeType<Type> *link;
};

template <class Type>
class linkedListIterator {
 public:
    linkedListIterator();
     // Default constructor
     // Postcondition: current = nullptr;

    linkedListIterator(nodeType<Type> *ptr);
     // Constructor with a parameter.
     // Postcondition: current = ptr;

    Type operator*();
     // Function to overload the dereferencing operator *.
     // Postcondition: Returns the info contained in the node.

    linkedListIterator<Type> operator++();
     // Overload the pre-increment operator.
     // Postcondition: The iterator is advanced to the next
     //               node.

    bool operator==(const linkedListIterator<Type>& right) const;
     // Overload the equality operator.
     // Postcondition: Returns true if this iterator is equal to
     //               the iterator specified by right,
     //               otherwise it returns the value false.

    bool operator!=(const linkedListIterator<Type>& right) const;
     // Overload the not equal to operator.
     // Postcondition: Returns true if this iterator is not
     //               equal to the iterator specified by
     //               right; otherwise it returns the value
     //               false.

 private:
    nodeType<Type> *current;          // Pointer to point to the current
                                      //   node in the linked list
};

template <class Type>
linkedListIterator<Type>::linkedListIterator() {
    current = nullptr;
}

template <class Type>
linkedListIterator<Type>::
                  linkedListIterator(nodeType<Type> *ptr) {
    current = ptr;
}

template <class Type>
Type linkedListIterator<Type>::operator*() {
    return current->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::
                                  operator++() {
    current = current->link;

    return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==
               (const linkedListIterator<Type>& right) const {
    return (current == right.current);
}

template <class Type>
bool linkedListIterator<Type>::operator!=
                 (const linkedListIterator<Type>& right) const {
    return (current != right.current);
}


// *****************  class linkedListType   ****************

template <class Type>
class linkedListType {
 public:
    const linkedListType<Type>& operator=
                         (const linkedListType<Type>&);
      // Overload the assignment operator.

    void initializeList();
      // Initialize the list to an empty state.
      // Postcondition: first = nullptr, last = nullptr,
      //               count = 0;

    bool isEmptyList() const;
      // Function to determine whether the list is empty.
      // Postcondition: Returns true if the list is empty,
      //               otherwise it returns false.

    void print() const;
      // Function to output the data contained in each node.
      // Postcondition: none

    void print(const int nodePosition) const;
      // Function to output the data contained in each node.
      // Postcondition: none

    void reversePrint() const;
      // Function to output the data contained in each node.
      // Printed in reverse order without recursion.
      // Postcondition: none

    void recursiveReversePrint() const;
      // Function to output the data contained in each node.
      // Printed in reverse order
      // Postcondition: none

    void recursiveReversePrint(const nodeType<Type> *current) const;
      // Function to output the data contained in each node.
      // Printed in reverse order
      // Postcondition: none

    int length() const;
      // Function to return the number of nodes in the list.
      // Postcondition: The value of count is returned.

    void destroyList();
      // Function to delete all the nodes from the list.
      // Postcondition: first = nullptr, last = nullptr,
      //               count = 0;

    Type front() const;
      // Function to return the first element of the list
      // Precondition: The list must exist and must not be
      //              empty.
      // Postcondition: If the list is empty, the program
      //               terminates; otherwise, the first
      //               element of the list is returned.

    Type back() const;
      // Function to return the last element of the list.
      // Precondition: The list must exist and must not be
      //              empty.
      // Postcondition: If the list is empty, the program
      //               terminates; otherwise, the last
      //               element of the list is returned.

    virtual bool search(const Type& searchItem) const = 0;
      // Function to determine whether searchItem is in the list.
      // Postcondition: Returns true if searchItem is in the
      //               list, otherwise the value false is
      //               returned.

    virtual void insertFirst(const Type& newItem) = 0;
      // Function to insert newItem at the beginning of the list.
      // Postcondition: first points to the new list, newItem is
      //               inserted at the beginning of the list,
      //               last points to the last node in the list,
      //               and count is incremented by 1.

    virtual void insertLast(const Type& newItem) = 0;
      // Function to insert newItem at the end of the list.
      // Postcondition: first points to the new list, newItem
      //               is inserted at the end of the list,
      //               last points to the last node in the
      //               list, and count is incremented by 1.

    virtual void deleteItem(const Type& deleteItem) = 0;
      // Function to delete deleteItem from the list.
      // Postcondition: If found, the node containing
      //               deleteItem is deleted from the list.
      //               first points to the first node, last
      //               points to the last node of the updated
      //               list, and count is decremented by 1.

    virtual void deleteNode(Type& deleteNode) = 0;
      // Function to delete a node from the list.
      // Postcondition: If the node index is within list bounds
      //               the node is removed.  If the removed node was
      //               the end of the list, last points to the new
      //               end of the list, and count is decremented by 1

    virtual void deleteSmallest() = 0;
      // Function to delete the smallest deleteItem from the list
      // Postcondition: If found, the node containing deleteItem
      //                is removed from the list.  first points to
      //                first node, last points to the last node of
      //                of the updated list, and count is decremented by 1

    virtual void deleteAll(const Type& deleteItem) = 0;
      // Function to delete all deleteItem from the list
      // Postcondition: If found, the node(s) containing deleteItem
      //                are removed from the list.  first points to
      //                first node, last points to the last node of
      //                of the updated list, and count is decremented by 1

    linkedListIterator<Type> begin();
      // Function to return an iterator at the begining of
      // the linked list.
      // Postcondition: Returns an iterator such that current
      //               is set to first.

    linkedListIterator<Type> end();
      // Function to return an iterator one element past the
      // last element of the linked list.
      // Postcondition: Returns an iterator such that current
      //               is set to nullptr.

    linkedListType();
      // Default constructor
      // Initializes the list to an empty state.
      // Postcondition: first = nullptr, last = nullptr,
      //               count = 0;

    linkedListType(const linkedListType<Type>& otherList);
      // Copy constructor

    ~linkedListType();
      // Destructor
      // Deletes all the nodes from the list.
      // Postcondition: The list object is destroyed.

 protected:
    int count;                // Variable to store the number of
                              //   elements in the list
    nodeType<Type> *first;    // Pointer to the first node of the list
    nodeType<Type> *last;     // Pointer to the last node of the list

 private:
    void copyList(const linkedListType<Type>& otherList);
      // Function to make a copy of otherList.
      // Postcondition: A copy of otherList is created and
      //               assigned to this list.
};


template <class Type>
bool linkedListType<Type>::isEmptyList() const {
    return (first == nullptr);
}

template <class Type>
linkedListType<Type>::linkedListType() {                  // Default constructor
    first = nullptr;
    last = nullptr;
    count = 0;
}

template <class Type>
void linkedListType<Type>::destroyList() {
    nodeType<Type> *temp;                   // Pointer to deallocate the memory
                                            //   occupied by the node
    while (first != nullptr) {              // While there are nodes in the list
        temp = first;                       // Set temp to the current node
        first = first->link;                // Advance first to the next node
        delete temp;                        // Free up memory occupied by temp
    }
    last = nullptr;             // Initialize last to nullptr; first has already
                                //   been set to nullptr by the while loop
    count = 0;
}

template <class Type>
void linkedListType<Type>::initializeList() {
    destroyList();                     // If the list has any nodes, delete them
}

template <class Type>
void linkedListType<Type>::print() const {
    nodeType<Type> *current;                     // Pointer to traverse the list

    current = first;                             // Set current to point to
                                                 //   the first node
    while (current != nullptr) {                 // While more data to print
        std::cout << current->info << " ";
        current = current->link;
    }
    std::cout << std::endl;
}  // End print

template <class Type>
void linkedListType<Type>::print(const int nodePos) const {
    nodeType<Type> *current;                     // Pointer to traverse the list

    current = first;                         // Set current so that it points to
                                             //   the first node
    int pos = 0;                             // Position counter
    bool found = false;                      // Feedback to user
    if (nodePos == 0) {
      std::cout << "0 is invalid." << std::endl;
    } else {
      while (current != nullptr) {             // While more data to print
          if (++pos == nodePos) {
            std::cout << "The value located at position #" << nodePos
                    << " is " << current->info << std::endl;
            found = true;
            break;
          }
          current = current->link;
      }
      if (!found)
          std::cout << "Nothing was found in location " << nodePos << std::endl;
    }  // End if nodePos == 0
}  // End print

template <class Type>
void linkedListType<Type>::reversePrint() const {
    /*
        The idea here is to create a linkedList in the other direction.
        Then, just pass it to print()
    */
    int i = 0;

    // I'd like to use a linkedList but I don't know how to use it in this scope
    // linkedListType<int> tempList;
    nodeType<Type> *current;            // Pointer to traverse the list
    // Create dynamic array
    // Dirty -- not ideal because the linkedList may be very large
    // std::cout << "count=" << count << std::endl;
    int *llArray = new int[count];
    current = first;    // Set current so that it points to the first node
    while (current->link != nullptr) {
        // tempList.insertLast(current->info);
        // std::cout << current->info << " ";
        llArray[i] = current->info;
        current = current->link;
        i++;
    }
    llArray[i] = current->info;
    // std::cout << std::endl;
    // Reverse loop through the array
    for (i = count-1; i >= 0; i--) {
        std::cout << llArray[i] << " ";
    }
    std::cout << std::endl;
    delete [] llArray;
}  // End reversePrint

template <class Type>
void linkedListType<Type>::recursiveReversePrint() const {
    nodeType<Type> *current;                     // Pointer to traverse the list

    current = first;          // Set current so that it points to the first node
    if (current != nullptr) {                  // Print if the pointer ≠ nullptr
        recursiveReversePrint(current->link);  // Print the tail (p.1132)
        std::cout << current->info << " ";     // Print the node
    }
    std::cout << std::endl;
}  // End recursiveReversePrint

template <class Type>
void linkedListType<Type>::
              recursiveReversePrint(const nodeType<Type> *current) const {
    if (current != nullptr) {               // Print if the pointer ≠ nullptr
        recursiveReversePrint(current->link);        // Print the tail (p.1132)
        std::cout << current->info << " ";  // Print the node
    }
}  // End recursiveReversePrint

template <class Type>
int linkedListType<Type>::length() const {
    return count;
}  // End length

template <class Type>
Type linkedListType<Type>::front() const {
    assert(first != nullptr);
    return first->info;                     // Return the info of the first node
}  // End front

template <class Type>
Type linkedListType<Type>::back() const {
    assert(last != nullptr);
    return last->info;                      // Return the info of the last node
}  // End back

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin() {
    linkedListIterator<Type> temp(first);
    return temp;
}  // End begin

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end() {
    linkedListIterator<Type> temp(nullptr);
    return temp;
}  // End end

template <class Type>
void linkedListType<Type>::copyList
                   (const linkedListType<Type>& otherList) {
    nodeType<Type> *newNode;                     // Pointer to create a node
    nodeType<Type> *current;                     // Pointer to traverse the list

    if (first != nullptr)              // If the list is nonempty, make it empty
       destroyList();

    if (otherList.first == nullptr) {            // OtherList is empty
        first = nullptr;
        last = nullptr;
        count = 0;
    } else {
        current = otherList.first;    // current points to the list to be copied
        count = otherList.count;

            // copy the first node
        first = new nodeType<Type>;   // Create the node

        first->info = current->info;  // Copy the info
        first->link = nullptr;        // Set the link field of the node to
                                      //   nullptr
        last = first;                 // Make last point to the first node
        current = current->link;      // Make current point to the next node

        // Copy the remaining list
        while (current != nullptr) {
            newNode = new nodeType<Type>;     // Create a node
            newNode->info = current->info;    // Copy the info
            newNode->link = nullptr;          // Set the link of
                                              //   newNode to nullptr
            last->link = newNode;             // Attach newNode after last
            last = newNode;                   // Make last point to
                                              //   the actual last node
            current = current->link;          // Make current point
                                              //   to the next node
        }  // End while
    }  // End else
}  // End copyList

template <class Type>
linkedListType<Type>::~linkedListType() {  // Destructor
    destroyList();
}  // End destructor

template <class Type>
linkedListType<Type>::linkedListType
                      (const linkedListType<Type>& otherList) {
    first = nullptr;
    copyList(otherList);
}  // End copy constructor

// Overload the assignment operator
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=
                      (const linkedListType<Type>& otherList) {
    if (this != &otherList) {         // Avoid self-copy
        copyList(otherList);
    }
    return *this;
}

#endif
