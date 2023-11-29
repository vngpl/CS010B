#include <iostream>
using namespace std;

#include "IntList.h"

int main() {

   // // tests constructor, destructor, push_front, pop_front, display
   // {
   //    cout << "|||||||||||||||| BEGIN TESTING ||||||||||||||||" << endl << endl << endl;
   //    IntList test;
   //    cout << "CONSTRUCTED EMPTY IntList: \"IntList test;\"" << endl << endl << endl;

   //    cout << "--------------------- TESTING \".empty()\" ---------------------" << endl;
   //    cout << "EMPTY? (0 = FALSE / 0 = TRUE): " << test.empty() << endl << endl;
   //    cout << "~~ push_front: 19 ~~" << endl << endl;
   //    test.push_front(19);
   //    cout << "EMPTY? (0 = FALSE / 0 = TRUE): " << test.empty() << endl << endl << endl;

   //    cout << "--------------------- TESTING \".push_front()\" & \".front()\" ---------------------" << endl;
   //    cout << "VALUE @ FRONT: " << test.front() << endl << endl;
   //    cout << "~~ push_front: 16 ~~" << endl << endl;
   //    test.push_front(16);
   //    cout << "~~ push_front: 9 ~~" << endl << endl;
   //    test.push_front(9);
   //    cout << "~~ push_front: 11 ~~" << endl << endl;
   //    test.push_front(11);
   //    cout << "VALUE @ FRONT: " << test.front() << endl << endl << endl;

   //    cout << "--------------------- TESTING OUTPUT/DISPLAY FUNCTION ---------------------" << endl;
   //    cout << "IntList test: " << test << endl << endl << endl;

   //    cout << "--------------------- TESTING \".pop_front()\" ---------------------" << endl;
   //    cout << "VALUE @ FRONT: " << test.front() << endl << endl;
   //    cout << "~~ pop_front ~~" << endl << endl;
   //    test.pop_front();

   //    cout << "VALUE @ FRONT: " << test.front() << endl << endl << endl;

   //    cout << "--------------------- TESTING \".back()\" ---------------------" << endl;
   //    cout << "VALUE @ BACK: " << test.back() << endl << endl << endl;

   //    cout << "--------------------- TESTING \".clear()\" ---------------------" << endl;
   //    cout << "~~ CLEARING LIST ~~" << endl << endl;
   //    test.clear();
   //    cout << "EMPTY? (1 = TRUE / 2 = FALSE): " << test.empty() << endl << endl << endl;

   //    cout << "|||||||||||||||| END TESTING ||||||||||||||||" << endl << endl;

   //    cout << "~~ calling the....DESTRUCTOR !!! ~~" << endl << endl;
   // }
      
   {
      cout << "\nlist1 constructor called" << endl;
      IntList list1;
      cout << "pushfront 10" << endl;
      list1.push_front(10);
      cout << "pushfront 20" << endl;
      list1.push_front(20);
      cout << "pushfront 30" << endl;
      list1.push_front(30);
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pushfront 100" << endl;
      list1.push_front(100);
      cout << "pushfront 200" << endl;
      list1.push_front(200);
      cout << "pushfront 300" << endl;
      list1.push_front(300);
      cout << "list1: " << list1 << endl;
      cout << endl;
      cout << "Calling list1 destructor..." << endl;
   }
   cout << "list1 destructor returned" << endl;
   
   // Test destructor on empty IntList
   {
      IntList list2;
      cout << "Calling list2 destructor..." << endl;
   }
   cout << "list2 destructor returned" << endl;
   
   return 0;
}
