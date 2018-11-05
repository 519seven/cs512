#ifndef H_arrayListType
#define H_arrayListType

#define LISTITEMS 1000

template <class Type>
class arrayListType
{
public:
    bool isEmpty() const;
      //Function to determine whether the list is empty
      //Postcondition: Returns true if the list is empty;
      //               otherwise, returns false.

    bool isFull() const;
      //Function to determine whether the list is full
      //Postcondition: Returns true if the list is full;
      //               otherwise, returns false.

    int listSize() const;
      //Function to determine the number of elements in
      //the list.
      //Postcondition: Returns the value of length.

    int maxListSize() const;
      //Function to determine the maximum size of the list
      //Postcondition: Returns the value of maxSize.

    void print() const;
      //Function to output the elements of the list
      //Postcondition: Elements of the list are output on the
      //               standard output device.

    void print(int s) const;
      //Function to output the elements of the list.  If passed
      //    an integer, it will print only that many items
      //Postcondition: Elements of the list are output on the
      //               standard output device.

    void print(int s, bool first) const;
      //Function to output the elements of the list.  If passed
      //    an integer, it will print only that many items
      //Postcondition: Elements of the list are output on the
      //               standard output device.

    bool isItemAtEqual(int location, Type& item) const;
      //Function to determine whether item is the same as
      //the item in the list at the position specified
      //by location.
      //Postcondition: Returns true if list[location]
      //               is the same as item; otherwise,
      //               returns false.
      //               If location is out of range, an
      //               appropriate message is displayed.

    virtual void insertAt(int location, Type& insertItem) = 0;
      //Function to insert insertItem in the list at the
      //position specified by location.
      //Note that this is an abstract function.
      //Postcondition: Starting at location, the elements of
      //               the list are shifted down,
      //               list[location] = insertItem; length++;
      //               If the list is full or location is
      //               out of range, an appropriate message
      //               is displayed.

    virtual void insertEnd(Type& insertItem, const bool force) = 0;
      //Function to insert insertItem an item at the end of
      //the list. Note that this is an abstract function.
      //Postcondition: list[length] = insertItem; and length++;
      //               If the list is full, an appropriate
      //               message is displayed.

    void removeAt(int location);
      //Function to remove the item from the list at the
      //position specified by location
      //Postcondition: The list element at list[location] is
      //               removed and length is decremented by 1.
      //               If location is out of range, an
      //               appropriate message is displayed.

    void retrieveAt(int location, Type& retItem) const;
      //Function to retrieve the element from the list
      //at the position specified by location
      //Postcondition: retItem = list[location]
      //               If location is out of range, an
      //               appropriate message is displayed.

    virtual void replaceAt(int location, Type& repItem) = 0;
      //Function to replace the elements in the list
      //at the position specified by location.
      //Note that this is an abstract function.
      //Postcondition: list[location] = repItem
      //               If location is out of range, an
      //               appropriate message is displayed.

    void clearList();
      //Function to remove all the elements from the list
      //After this operation, the size of the list is zero.
      //Postcondition: length = 0;

    virtual int seqSearch(Type& searchItem) = 0;
      //Function to search the list for searchItem.
      //Note that this is an abstract function.
      //Postcondition: If the item is found, returns the
      //               location in the array where the item
      //               is found; otherwise, returns -1.

    virtual void remove(Type& removeItem) = 0;
      //Function to remove removeItem from the list.
      //Note that this is an abstract function.
      //Postcondition: If removeItem is found in the list,
      //               it is removed from the list and
      //               length is decremented by one.

    arrayListType(int size = LISTITEMS);
      //Constructor
      //Creates an array of the size specified by the
      //parameter size. The default array size is 100.
      //Postcondition: The list points to the array,
      //               length = 0, and maxSize = size;

    arrayListType (const arrayListType& otherList);
       //Copy constructor

    virtual ~arrayListType();
      //Destructor
      //Deallocate the memory occupied by the array.

protected:
    int *list;    //array to hold the list elements
    int length;   //variable to store the length of the list
    int maxSize;  //variable to store the maximum
                  //size of the list
};

// begin print
template <class Type>
void arrayListType<Type>::print() const {
    if (this->length !=0) {
        for (int i = 0; i < this->length; i++)
            std::cout << list[i] << " ";
        std::cout << std::endl;
    } else {
        std::cout << "<empty>" << std::endl;
    }
}  // end print

// begin print
template <class Type>
void arrayListType<Type>::print(int s) const {
    if (this->length !=0) {
        if (s > this->length)
            s = this->length;
        for (int i = 1; i <= s; i++)
            std::cout << list[i-1] << " ";
        std::cout << std::endl;
    } else {
        std::cout << "<empty>" << std::endl;
    }
}  // end print

// begin print
template <class Type>
void arrayListType<Type>::print(int sc, bool pFirst) const {
    if (this->length !=0) {
        int s, start, end = 0;
        bool tooLarge = false;

        // quick check to make sure the subset count isn't larger than the array
        if (sc > this->length) { s = 5; tooLarge = true; } else { s = sc; }
        // let's find out if we have to reverse it first
        if (!pFirst) {
            // print the last X items (in the same order, just the last ones)
            start = this->length - s;
            end = start + s;
        } else {
            start = 0;
            end = s;
        }
        if (pFirst)
          std::cout << "[INFO] First ";
        else
          std::cout << "[INFO] Last ";
        std::cout << s << " items in the current array: ";
        for (int i = start; i <= end-1; i++)
            std::cout << list[i] << " ";
        if (tooLarge)
            std::cout << std::endl << "(Requested item count of " << sc
                      << " is too large. Showing only "
                      << std::to_string(s) << " items.)"  << std::endl;
        std::cout << std::endl;
    } else {
        std::cout << "<empty>" << std::endl;
    }
}  // end print

// begin removeAt
template <class Type>
void arrayListType<Type>::removeAt(int location) {
    if (location < 0 || location >= length) {
        std::cout << "The location of the item to be removed "
             << "is out of range." << std::endl;
    } else {
        for (int i = location; i < length - 1; i++)
            list[i] = list[i+1];

        length--;
    }
}  // end removeAt

// begin constructor
template <class Type>
arrayListType<Type>::arrayListType(int size) {
    if (size <= 0) {
        std::cout << "The array size must be positive. Creating "
             << "an array of the size 100." << std::endl;

        maxSize = LISTITEMS;
    } else {
        maxSize = size;
    }

    length = 0;

    list = new int[maxSize];
}  // end constructor

// begin destructor
template <class Type>
arrayListType<Type>::~arrayListType() {
    delete [] list;
}  // end destructor

#endif
