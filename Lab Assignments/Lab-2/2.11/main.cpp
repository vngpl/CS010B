#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

//[vnagp002@xe-02 ~]$ g++ Lab-2/2.11/main.cpp -Wall -Werror -o a.out
//[vnagp002@xe-02 ~]$ ./a.out
   // Enter the name of the input file: Lab-2/2.11/lab2part1a.txt

int fileSum (const string&);

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

int fileSum (const string &filename) {
   ifstream inputFS;

   inputFS.open(filename);

   if (!inputFS.is_open()) {
      cout << "Error opening " << filename << endl;
      exit(EXIT_FAILURE);
      return 1;
   }

   int fileNum, fileNumSum = 0;

   while (inputFS >> fileNum) {
      fileNumSum += fileNum;
   }

   inputFS.close();

   return fileNumSum;

}