
//Data:  21 10 56 43 78 11 20 18

#include <iostream>
#include "orderedArrayListType.h" 

using namespace std; 
 
int main()
{
    orderedArrayListType intList(25);               //Line 1

    int number;                                     //Line 2

    cout << "List 3: Enter 8 integers: ";           //Line 3

    for (int count = 0; count < 8; count++)         //Line 4
    {
        cin >> number;                              //Line 5
        intList.insert(number);                     //Line 6
    }

    cout << endl;                                   //Line 7
    cout << "Line 8: intList: ";                    //Line 8
    intList.print();                                //Line 9
    cout << endl;                                   //Line 10

    cout << "Line 11: Enter the number to be " 
         << "deleted: ";                            //Line 11
    cin >> number;                                  //Line 12
    cout << endl;                                   //Line 13

    intList.remove(number);                         //Line 14

    cout << "Line 15: After removing " << number
         << " intList: ";                           //Line 15
    intList.print();                                //Line 16
    cout << endl;                                   //Line 17
 
    cout << "Line 18: Enter the search item: ";     //Line 18

    cin >> number;                                  //Line 19
    cout << endl;                                   //Line 20

    if (intList.seqSearch(number) != -1)            //Line 21
        cout << "Line 22: " << number 
             << " found in intList." << endl;       //Line 22
    else                                            //Line 23
        cout << "Line 24: " << number 
             << " is not in intList." << endl;      //Line 24

	return 0; 
}