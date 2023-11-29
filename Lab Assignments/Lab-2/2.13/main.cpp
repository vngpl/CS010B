#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   string inputFile, outputFile, line;
   ifstream inputFS;
   ofstream outputFS;
   unsigned int i = 0;
   int sum = 0, avgVal = 0;
   vector<int> inputIntegers;

   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1]; 

   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2]; 

   // Create input stream and open input csv file.
   inputFS.open(inputFile);

   // Verify file opened correctly.
   if (!inputFS.is_open()) {
      // Output error message and return 1 if file stream did not open correctly.
      cout << "Error opening " << inputFile << endl;
      exit(EXIT_FAILURE);
      return 1;
   }

   // Read in integers from input file to vector.
   while (getline(inputFS, line, ',')) {
      inputIntegers.push_back(stoi(line));
   }

   for (i = 0; i < inputIntegers.size(); ++i) {
      sum += inputIntegers.at(i);
   }
   
   // Get integer average of all values read in.
   avgVal = sum / inputIntegers.size();

   // Create output stream and open/create output csv file.
   outputFS.open(outputFile);

   // Verify file opened or was created correctly.
   if (!outputFS.is_open()) {
      // Output error message and return 1 if file stream did not open correctly.
      cout << "Error opening " << inputFile << endl;
      exit(EXIT_FAILURE);
      return 1;
   }

   for (i = 0; i < inputIntegers.size(); ++i) {
      // Convert each value within vector to be the difference between the original value and the average.
      inputIntegers.at(i) -= avgVal;
      if (inputIntegers.at(i) == inputIntegers.at(inputIntegers.size() - 1)) {
         outputFS << inputIntegers.at(i);
      }
      else {
         outputFS << inputIntegers.at(i) << ",";
      }
      // Write converted values into ouptut csv file, each integer separated by a comma.
   }

   // Close input stream.
   inputFS.close();
   // Close output stream.
   outputFS.close();
   
   return 0;
}