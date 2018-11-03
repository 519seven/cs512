// Copyright 2018 Peter Akey
// Modified as needed from C++ Programming by D.S. Malik 8th Edition

#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

#include "linkedList.h"

template <class Type>
class unorderedLinkedList: public linkedListType<Type> {
 public:
    bool search(const Type& searchItem) const;
      // Function to determine whether searchItem is in the list.
      // Postcondition: Returns true if searchItem is in the
      //               list, otherwise the value false is
      //               returned.

    void insertFirst(const Type& newItem);
      // Function to insert newItem at the beginning of the list.
      // Postcondition: first points to the new list, newItem is
      //               inserted at the beginning of the list,
      //               last points to the last node in the
      //               list, and count is incremented by 1.

    void insertLast(const Type& newItem);
      // Function to insert newItem at the end of the list.
      // Postcondition: first points to the new list, newItem
      //               is inserted at the end of the list,
      //               last points to the last node in the
      //               list, and count is incremented by 1.

    void deleteItem(const Type& deleteItem);
      // Function to delete deleteItem from the list.
      // Postcondition: If found, the node containing
      //               deleteItem is deleted from the list.
      //               first points to the first node, last
      //               points to the last node of the updated
      //               list, and count is decremented by 1.

    void deleteNode(Type& deleteNode);
      // Function to delete a node from the list.
      // Postcondition: If the node index is within list bounds
      //               the node is removed.  If the removed node was
      //               the end of the list, last points to the new
      //               end of the list, and count is decremented by 1

    void deleteSmallest();
      // Function to delete the smallest deleteItem from the list
      // Postcondition: If found, the node containing deleteItem
      //                is removed from the list.  first points to
      //                first node, last points to the last node of
      //                of the updated list, and count is decremented by 1

    void deleteAll(const Type& deleteItem);
      // Function to delete all deleteItem from the list
      // Postcondition: If found, the node(s) containing deleteItem
      //                are removed from the list.  first points to
      //                first node, last points to the last node of
      //                of the updated list, and count is decremented by 1
};

template <class Type>
bool unorderedLinkedList<Type>::
                   search(const Type& searchItem) const {
    nodeType<Type> *current;                // Pointer to traverse the list
    bool found = false;
    current = this->first;                  // Set current to point to the first
                                            //   node in the list
    while (current != nullptr && !found)    // Search the list
        if (current->info == searchItem)    // SearchItem is found
            found = true;
        else
            current = current->link;       // Make current point to the next one
    return found;
}  // End search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem) {
    nodeType<Type> *newNode;                // Pointer to create the new node

    newNode = new nodeType<Type>;           // Create the new node

    newNode->info = newItem;                // Store the new item in the node
    newNode->link = this->first;            // Insert newNode before first
    this->first = newNode;                  // Make first point to the
                                            //   actual first node
    this->count++;                          // Increment count

    if (this->last == nullptr)              // If the list was empty, newNode is
                                            //   also the last node in the list
        this->last = newNode;
}  // End insertFirst

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem) {
    nodeType<Type> *newNode;                 // Pointer to create the new node

    newNode = new nodeType<Type>;            // Create the new node

    newNode->info = newItem;                 // Store the new item in the node
    newNode->link = nullptr;                 // Set the link field of newNode
                                             //   to nullptr

    if (this->first == nullptr) {            // If the list is empty, newNode is
                                             //   both the first and last node
        this->first = newNode;
        this->last = newNode;
        this->count++;      // Increment count
    } else {                // The list is not empty, insert newNode after last
        this->last->link = newNode;           // Insert newNode after last
        this->last = newNode;                 // Make last point to the actual
                                              //   last node in the list
        this->count++;                        // Increment count
    }
}  // End insertLast

template <class Type>
void unorderedLinkedList<Type>::deleteItem(const Type& deleteItem) {
    /*
        Delete a node based on what it contains:
        a.) Ask the user for the value stored in "info"
        b.) Search for the value and remove the node
    */
    nodeType<Type> *current;        // Pointer to traverse the list
    nodeType<Type> *trailCurrent;   // Pointer just before current
    bool found;

    if (this->first == nullptr) {       // The list is empty
        std::cout << "Cannot delete from an empty list."
             << std::endl;
    } else {
        if (this->first->info == deleteItem) {  // Special case - first node
            current = this->first;
            this->first = this->first->link;
            if (this->first == nullptr)         // The list has only one node
                this->last = nullptr;
            delete current;
            this->count--;
            std::cout << deleteItem << " was found and removed." << std::endl;
        } else {           // Search the list for the node with the given info
            found = false;
            current = this->first;      // Set current to point to
                                        //   the second node
            while (current != nullptr && !found) {
                if (current->info != deleteItem) {
                    trailCurrent = current;
                    current = current-> link;
                } else {
                    found = true;
                }
            }  // End while
            if (found) {                          // If found, delete the node
                trailCurrent->link = current->link;
                if (this->last == current)        // Node to be deleted
                                                  //   was the last node
                    this->last = trailCurrent;    // Update the value of last
                delete current;                   // Delete the node
                this->count--;
                std::cout << deleteItem << " was found and removed."
                      << std::endl;
            } else {
                std::cout << deleteItem << " is not in the list." << std::endl;
            }
        }  // End else
    }  // End else
}  // End deleteNode

template <class Type>
void unorderedLinkedList<Type>::deleteNode(Type& deleteNode) {
    /*
        Delete a node found at the kth index (counting from beginning to end):
        a.) Ask the user for the "index" of the node to be removed
        b.) Iterate over list, remove the node at kth position
        (Since I am asking a human for the "index" this is a 1-based index)
    */
    nodeType<Type> *current;        // Pointer to traverse the list
    nodeType<Type> *trailCurrent;   // Pointer just before current
    int index = 0;                  // Loop index
    deleteNode--;                   // Since current is already one ahead...

    if (this->first == nullptr) {   // List is empty
        std::cout << "Cannot delete from an empty list."
             << std::endl;
    } else if (deleteNode > this->count) {
        std::cout << "The node you wish to delete is beyond the boundary "
                << "of the list.\nSelect a smaller index." << std::endl;
    } else if (deleteNode < 0) {
        std::cout << "The node you wish to delete is outside of the boundary "
                << "of the list.\nSelect a position beginning with 1."
                << std::endl;
    } else {
        current = this->first;       // Set current to point to
                                     //   the second node
        //  std::cout << "deleteNode = " << deleteNode << std::endl;
        while (current != nullptr) {
            if (deleteNode == 0) {  // Remove the first node
                                    // deleteNode-- already happened
                                    // (this is probably our first time through)
                if (current->link != nullptr) {
                    this->first = current->link;    // Assign next node to first
                } else {
                    // A one-item list
                    this->first = nullptr;
                    this->last = nullptr;
                }
                delete current;
                this->count--;
                std::cout << "The first node has been removed." << std::endl;
                break;
            } else if (index == deleteNode) {
                if (this->last == current) {    // Remove the last node
                    trailCurrent->link = nullptr;
                    delete current;
                    this->count--;
                    this->last = trailCurrent;  // Update the value of last
                    std::cout << "The last node has been removed." << std::endl;
                } else {                        // Remove a node in the middle
                    trailCurrent->link = current->link;
                    delete current;             // Delete the node from the list
                    this->count--;
                    std::cout << "Node at position #" << ++deleteNode
                            << " has been removed." << std::endl;
                    break;                   // We're done, break from the while
                }
            }
            index++;
            trailCurrent = current;
            current = current->link;
        }  // End while
    }  // End else
}  // End deleteNode

template <class Type>
void unorderedLinkedList<Type>::deleteSmallest() {
    nodeType<Type> *current;        // Pointer to traverse the list
    nodeType<Type> *trailCurrent;   // Pointer just before current
    nodeType<Type> *smallestNode;   // Pointer to the smallest node
    nodeType<Type> *previousNode;   // Pointer to the node just before
                                // the smallest
    int smallest;                   // Int value holder (make this a Type&????)

    if (this->first == nullptr) {   // Empty list
        std::cout << "Cannot delete from an empty list."
             << std::endl;
    } else {
        smallest = this->first->info;   // Start tracking the smallest
        trailCurrent = this->first;     // Starting out, these are the same
        previousNode = this->first;     // Starting out, these are the same
        smallestNode = this->first;     // Starting out, these are the same
        current = this->first;          // Set current to point to first node

        while (current != nullptr) {     // Traverse the whole list
            if (current->info < smallest) {
                smallest = current->info;
                smallestNode = current;
                previousNode = trailCurrent;
            }
            trailCurrent = current;
            current = current->link;
        }  // End while

        // After looping through, *something* will be the smallest
        if (this->first == smallestNode) {
            // We're removing the first node, update first
            this->first = smallestNode->link;
        }
        previousNode->link = smallestNode->link;
        this->count--;

        if (this->last == smallestNode)  // Node to be deleted was the last node
            this->last = previousNode;   // Update the value of last
        delete smallestNode;             // Delete the node from the list
    }  // End else
    if (smallest)
      std::cout << smallest << " was removed from your list." << std::endl;
}  // End deleteSmallest

template <class Type>
void unorderedLinkedList<Type>::deleteAll(const Type& deleteItem) {
    nodeType<Type> *current;        // Pointer to traverse the list
    nodeType<Type> *trailCurrent;   // Pointer just before current
    nodeType<Type> *d;              // Intermediary pointer
    bool found = false;             // Send message to user if found

    if (this->first == nullptr) {   // Empty list
        std::cout << "Cannot delete from an empty list."
             << std::endl;
    } else {
        current = this->first;                    // Set current to first node

        while (current != nullptr) {              // Traverse the whole list
            if (current->info == deleteItem) {
                if (this->first == current) {     // Special case - first node
                    //  std::cout << "Removing first element." << std::endl;
                    this->first = this->first->link;  // Update "first"
                    if (this->first == nullptr)   // Not sure why this is here
                        this->last = nullptr;     // But the book said do this
                    d = current->link;
                    delete current;
                    current = d;
                    found = true;
                } else if (this->last == current) {   // Special case: last node
                    //  std::cout << "Removing last element." << std::endl;
                    delete current;             // Delete the node from the list
                    this->last = trailCurrent;  // Update the value of last
                    this->last->link = nullptr;  // Setting last link to nullptr
                } else {
                    //  std::cout << "Removing element in the middle."
                    //        << std::endl;
                    trailCurrent->link = current->link;
                    d = current->link;
                    delete current;           // Delete the node from the list
                    current = d;
                    found = true;
                }
                this->count--;    // For all of these cases, reduce count by 1
            } else {
                trailCurrent = current;
                current = current->link;
            }
        }  // End while
    }  // End else
    if (found)
        std::cout << "Value(s) of " << deleteItem << " have been removed from "
              << "your list." << std::endl;
    else
        std::cout << "Your list does not contain a " << deleteItem << "."
              << std::endl;
}  // End deleteNode

#endif
