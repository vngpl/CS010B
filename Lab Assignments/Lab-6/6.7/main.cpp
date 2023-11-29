#include <iostream>
#include <cassert>
using namespace std;

#include "IntVector.h"

int main() {
    unsigned i = 0;

    // // initializes "_capacity" and "value" to 0 when no argument for "capacity" is passed in
    IntVector test1;
    cout << "------------ Default Constructor with no arguments ------------" << endl;
    cout << "IntVector test1;" << endl << endl;
    cout << "Capacity: (EXPECTING '0', GOT '" << test1.capacity() << "')" << endl;
            assert(test1.capacity() == 0);
    cout << "Size: (EXPECTING '0', GOT '" << test1.size() << "')" << endl;
            assert(test1.size() == 0);
    cout << "Empty: (EXPECTING '1' (TRUE), GOT '" << test1.empty() << "')" << endl;
            assert(test1.empty() == 1);
    cout << endl << endl;

    // initializes "_capacity" to value of 1st argument and all indexes to 0 when no argument for "value" is passed in
    IntVector test2(3);
    cout << "------------ Constructor with \"capacity\" argument only ------------" << endl;
    cout << "IntVector test2(3);" << endl << endl;
    cout << "Capacity: (EXPECTING '3', GOT '" << test2.capacity() << "')" << endl;
            assert(test2.capacity() == 3);
    cout << "Size: (EXPECTING '3', GOT '" << test2.size() << "')" << endl;
            assert(test2.size() == 3);
    cout << "Empty: (EXPECTING '0' (FALSE), GOT '" << test2.empty() << "')" << endl;
            assert(test2.empty() == 0);
    cout << endl;

    cout << "Index | Value" << endl;
    for (i = 0; i < test2.size(); ++i) {
        cout << i << "     | " << test2.at(i) << endl;
    }

    cout << endl;
    cout << "Value @ Index: (EXPECTING '0' AT INDEX '1', GOT '" << test2.at(1) << "')" << endl;
            assert(test2.at(1) == 0);
    cout << "Value @ Front: (EXPECTING '0', GOT '" << test2.front() << "')" << endl;
            assert(test2.front() == 0);
    cout << "Value @ Back: (EXPECTING '0', GOT '" << test2.back() << "')" << endl;
            assert(test2.back() == 0);
    cout << endl << endl;

    // initializes "_capacity" to value of 1st argument and all indexes to the 2nd argument
    IntVector test3(5, 10);
    cout << "------------ Constructor with \"capacity\" and \"value\" arguments ------------" << endl;
    cout << "IntVector test3(5, 10);" << endl << endl;
    cout << "Capacity: (EXPECTING '5', GOT '" << test3.capacity() << "')" << endl;
            assert(test3.capacity() == 5);
    cout << "Size: (EXPECTING '5', GOT '" << test3.size() << "')" << endl;
            assert(test3.size() == 5);
    cout << "Empty: (EXPECTING '0' (FALSE), GOT '" << test3.empty() << "')" << endl;
            assert(test3.empty() == 0);
    cout << endl;
    
    cout << "Index | Value" << endl;
    for (i = 0; i < test3.size(); ++i) {
        cout << i << "     | " << test3.at(i) << endl;
    }
    
    cout << endl;
    cout << "Value @ Index: (EXPECTING '10' AT INDEX '4', GOT '" << test3.at(4) << "')" << endl;
            assert(test3.at(4) == 10);
    cout << "Value @ Front: (EXPECTING '10', GOT '" << test3.front() << "')" << endl;
            assert(test3.front() == 10);
    cout << "Value @ Back: (EXPECTING '10', GOT '" << test3.back() << "')" << endl;
            assert(test3.back() == 10);        
    cout << endl << endl;

    return 0;
}