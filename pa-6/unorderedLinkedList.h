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

#endif
