#ifndef __INTVECTOR__
#define __INTVECTOR__

#include <iostream>
#include <stdexcept>
using namespace std;

class IntVector {
    private:
        unsigned _size = 0;
        unsigned _capacity = 0;
        int *_data = nullptr;
    public:
    /* Sets both the size and capacity of the IntVector to the value of the capacity argument passed in 
       or the default value of 0 if no argument is passed in for the capacity parameter. 
       The constructor should dynamically allocate an array of this capacity value passed in. 
       However, if the capacity is 0, then there is no array. Make sure you do not leave a dangling pointer. 
       This function should initialize all elements (if any) of the array to the value of the 2nd argument 
       passed in or to the default value of 0 if no argument passed in for the value parameter. 
       See zyBook section 3.10 if you need a refresher on how default parameters work in constructors. 
    */
        IntVector(unsigned capacity = 0, int value = 0);
    
    /* The destructor is used to clean up (delete) any remaining dynamically-allocated memory. 
       For this class, that will be the array pointed to by the int pointer named _data.
    */
        ~IntVector();

    /* This function returns the current size (not the capacity) of the IntVector object, 
       which is the values stored in the _size member variable.
    */
        unsigned size() const;

    /* This function returns the current capacity (not the size) of the IntVector object, 
       which is the value stored in the _capacity member variable.
    */
        unsigned capacity() const;

    /* Returns whether the IntVector is empty (_size is 0). */
        bool empty() const;

    /* This function will return the value stored in the element at the passed in index position. 
       Your function should throw an outofrange exception if an invalid index is passed in. 
       An invalid index is an index greater than or equal to the size.

       Throwing an exception: You will need to include the standard library stdexcept. 
       Then, when the index is out of range, execute the following statement:

            throw out_of_range("IntVector::at_range_check");
       
       To test if this worked, declare an IntVector of size 10 and then call the at function 
       passing it an index argument of 10 or larger. You should see the following output:

            terminate called after throwing an instance of 'std::out_of_range'
                what():  IntVector::at_range_check
            Aborted
    */
        const int & at(unsigned index) const;
    
    /* This function will return the value stored in the first element of the IntVector. 
       This function does not check the size of the IntVector or the array. 
       If the IntVector is empty then calling this function causes undefined behavior.
    */
        const int & front() const;
    
    /* This function will return the value stored in the last element of the IntVector. 
       This function does not check the size of the IntVector or the array. 
       If the IntVector is empty then calling this function causes undefined behavior.
    */
        const int & back() const;
};

#endif