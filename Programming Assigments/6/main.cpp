#include <iostream>
using namespace std;

#include "IntList.h"
#include "SortedSet.h"

int main() {

   cout << "-------------------------- COPY CONSTRUCTOR TEST --------------------------" << endl;
   IntList list;

   list.push_back(7);
   list.push_back(14);
   list.push_back(16);
   list.push_back(100);
   list.push_back(24);
   
   cout << "IntList list: " << list << endl << endl;

   SortedSet testSet = list;
   cout << "SortedSet testSet = list;" << endl
        << "SortedSet Copy Constructor (IntList): " << testSet << endl << endl;

   SortedSet testSet2 = testSet;
   cout << "SortedSet testSet2 = testSet;" << endl
        << "SortedSet Copy Constructor (SortedSet): " << testSet2 << endl << endl;
   cout << endl;
   
   cout << "-------------------------- TESTING \".in()\" --------------------------" << endl;
   cout << "CONTAINS '11' ? (0 = FALSE, 1 = TRUE): " << testSet.in(11) << endl << endl
        << "CONTAINS '14' ? (0 = FALSE, 1 = TRUE): " << testSet.in(14) << endl << endl;
   cout << endl;

   cout << "-------------------------- TESTING \".add()\", \".push_front()\", \".push_back()\", \".insert_ordered()\" --------------------------" << endl;
   SortedSet testSet3;
   
   cout << "CONSTRUCTED EMPTY SET 'testSet3'" << endl << endl;

   testSet3.add(5);
   cout << "ADD '5': " << testSet3 << endl << endl;
   testSet3.push_front(19);
   cout << "PUSH FRONT '19': " << testSet3 << endl << endl;
   testSet3.push_back(1);
   cout << "PUSH BACK '1': " << testSet3 << endl << endl;
   testSet3.insert_ordered(21);
   cout << "INSERT ORDERED '21': " << testSet3 << endl << endl;
   cout << endl;

   cout << "-------------------------- TESTING \"|\" AND \"&\" OPERATOR --------------------------" << endl;
   cout << "'testSet3': " << testSet3 << endl << endl;
   
   SortedSet testSet4;
   testSet4.add(0);
   testSet4.add(27);
   testSet4.add(12);
   testSet4.add(7);
   testSet4.add(4);
   testSet4.add(77);
   testSet4.add(81);
   testSet4.add(19);
   testSet4.add(1);
   testSet4.add(11);

   cout << "'testSet4': " << testSet4 << endl << endl;

   SortedSet testSet5 = testSet3 | testSet4;
   cout << "'testSet3' | 'testSet4': " << testSet5 << endl << endl;

   SortedSet testSet6 = testSet3 & testSet4;
   cout << "'testSet3' & 'testSet4': " << testSet6 << endl << endl;
   cout << endl;

   cout << "-------------------------- TESTING \"=|\" AND \"=&\" OPERATOR --------------------------" << endl;
   cout << "'testSet': " << testSet << endl << endl;
   cout << "'testSet2': " << testSet2 << endl << endl;
   cout << "'testSet3': " << testSet3 << endl << endl;
   cout << "'testSet4': " << testSet4 << endl << endl;

   testSet4 |= testSet;
   cout << "'testSet4' |= 'testSet': " << testSet4 << endl << endl;

   testSet4 &= testSet;
   cout << "'testSet4' &= 'testSet': " << testSet4 << endl << endl;
   cout << endl;

   return 0;
}