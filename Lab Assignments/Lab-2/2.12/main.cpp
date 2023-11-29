#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt (const string&, char&);

int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

// Place charCnt implementation here

int charCnt (const string &filename, char &userChar) {
   ifstream inputFS;
   int numChar = 0;
   char currChar;

   inputFS.open(filename);

   if (!inputFS.is_open()) {
      cout << "Error opening " << filename << endl;
      exit(EXIT_FAILURE);
      return 1;
   }

   while (inputFS.get(currChar)) {
      if (currChar == userChar) {
         ++numChar;
      }
   }

   inputFS.close();

   return numChar;
}


