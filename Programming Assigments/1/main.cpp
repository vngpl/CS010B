#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Function declarations
void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

int main(int argc, char *argv[]) {
    // Get input file from 2nd argument in command line
    string inputFile = argv[1];
    double minVal = 0;
    double maxVal = 0;
    double userPathAngle;
    string userOption;
    vector<double> pathAngle, liftCoeff;

    // Calls readData function
    readData(inputFile, pathAngle, liftCoeff);

    // If pathAngle is unordered or either one of the two vectors are empty, reorder function is called
    if ((isOrdered(pathAngle) == false) || ((pathAngle.empty()) || (liftCoeff.empty()))) {
        reorder(pathAngle, liftCoeff);
    }

    // Determines the min and max value from the pathAngle vector
    for (unsigned i = 0; i < pathAngle.size(); ++i) {
        if (pathAngle.at(i) < minVal) {
            minVal = pathAngle.at(i);
        }
        if (pathAngle.at(i) > maxVal) {
            maxVal = pathAngle.at(i);
        }
    }

    cout << "Enter a flight-path angle: ";
    cin >> userPathAngle;

    // Continues asking for userPathAngle until value is in bounds/range
    while ((userPathAngle > maxVal) || (userPathAngle < minVal)) {
        cout << "(OUT OF BOUNDS) Enter a flight-path angle: ";
        cin >> userPathAngle;
    }

    // Calls and outputs interpolated value
    cout << interpolation(userPathAngle, pathAngle, liftCoeff) << endl;

    // Continues asking user to enter a new path angle until "No" is entered
    while (userOption != "No") {
        cout << "Would you like to enter another flight-path angle?" << endl << "(Yes or No): ";
        cin >> userOption;
        cout << endl;

        if (userOption == "Yes") {
            cout << "Enter another flight-path angle: ";
            cin >> userPathAngle;

            while ((userPathAngle > maxVal) || (userPathAngle < minVal)) {
                cout << "(OUT OF BOUNDS) Enter another flight-path angle: ";
                cin >> userPathAngle;
            }

            cout << interpolation(userPathAngle, pathAngle, liftCoeff) << endl;
        }
        else if (userOption == "No") {
            break;
        }
        else {
            cout << "Invalid input. Enter \"Yes\" to input another flight-path angle or \"No\" to exit the program." << endl;
        }
    }
    return 0;
}

void readData(const string &inputFile, vector<double> &angleVector, vector<double> &liftVector) {
    ifstream inputFS;
    double angle, liftCoeff;
    
    inputFS.open(inputFile);

    // Checks if file opened correctly, exits if is_open returns false (not false = true)
    if (!inputFS.is_open()) {
        cout << "Error opening " << inputFile << endl;
        exit(1);
    }

    // If inputFS can read an angle, it will read corresponding liftCoeff and append values to corresponding vector
    while (inputFS >> angle) {
        inputFS >> liftCoeff;
        angleVector.push_back(angle);
        liftVector.push_back(liftCoeff);
    }

    inputFS.close();
}

double interpolation(double userVal, const vector<double> &angleVector, const vector<double> &liftVector) {
    double nextLargest = 0;
    double previousSmallest = 0;
    int previousSmallest_IDX = 0;
    int nextLargest_IDX = 0;
    double liftVector_userVal = 0;

    // Find next value greater than userVal and previous value less than userVal in angleVector
    for (unsigned i = 0; i < angleVector.size(); ++i) {
        // if userVal exists in angleVector, return corresponding liftVector value
        if (angleVector.at(i) == userVal) {
            return liftVector.at(i);
        }
        else if (angleVector.at(i) < userVal) {
            if (angleVector.at(i+1) > userVal) {
                previousSmallest = angleVector.at(i);
                previousSmallest_IDX = i;
            }
        }
        else if (angleVector.at(i) > userVal) {
            if (angleVector.at(i-1) < userVal){
                nextLargest = angleVector.at(i);
                nextLargest_IDX = i;
            }
        }
    }

    // If path angle userVal doesnt exist in angleVector, then use the formula below to find coefficient of lift at path angle userVal:    

        // f(b) = f(a) + ((b - a)/(c - a))(f(c) - f(a))

    liftVector_userVal = liftVector.at(previousSmallest_IDX) + ((userVal - previousSmallest) / (nextLargest - previousSmallest)) * (liftVector.at(nextLargest_IDX) - liftVector.at(previousSmallest_IDX));

    return liftVector_userVal;

}

bool isOrdered(const vector<double> &vector) {
    // Vectors with less than or equal to 1 elements are ordered
    if (vector.size() <= 1) {
        return true;
    }
    // Else if size > 1, verifies that the vector is ordered
    else if (vector.size() > 1) {
        for (unsigned i = 0; i < vector.size() - 1; ++i) {
            if (vector.at(i) > vector.at(i + 1)) {
                return false;
            }
        }
    }
    return true;
}

void reorder(vector<double> &angleVector, vector<double> &liftVector) {
    // If either of the two vectors are empty, return to main
    if ((angleVector.empty()) || (liftVector.empty())) {
        cout << "One or more vectors are empty." << endl;
        return;
    }
    // Else, use selection sort algorithm and swap function to reorder both vectors
    else {
        for (unsigned i = 0; i < angleVector.size() - 1; ++i) {
            int indexSmallest = i;
            for (unsigned j = i + 1; j < angleVector.size(); ++j) {
                if (angleVector[j] < angleVector[indexSmallest]) {
                    indexSmallest = j;
                }
            }
            swap(angleVector[indexSmallest], angleVector[i]);
            swap(liftVector[indexSmallest], liftVector[i]);
        }
    }
}