// Copyright 2018 Peter Akey
// Modified as needed from C++ Programming by D.S. Malik 8th Edition

#ifndef H_unorderedSetType
#define H_unorderedSetType

#include "unorderedArrayListType.h"

class unorderedSetType: public unorderedArrayListType {
 public:
    void insertAt(int location, int insertItem);
    void insertEnd(int insertItem);
    void replaceAt(int location, int repItem);
    int seqSearch(int searchItem) const;
    void remove(int removeItem);

    unorderedSetType(int size = 100);
      // Constructor
    ~unorderedSetType();
};

#endif