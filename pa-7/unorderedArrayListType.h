#ifndef H_unorderedArrayListType
#define H_unorderedArrayListType

#include "arrayListType.h"

template <class Type>
class unorderedArrayListType: public arrayListType<Type>
{
public:
    void insertAt(int location, Type& insertItem);
    void insertEnd(Type& insertItem);
    void replaceAt(int location, Type& repItem);
    int seqSearch(Type& searchItem) const;
    void remove(Type& removeItem);
    void populateRandomly();

    unorderedArrayListType(int size = LISTITEMS);               // Constructor
};


#endif
