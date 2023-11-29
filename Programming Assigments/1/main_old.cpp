#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Function Declarations
void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

int main(int argc, char *argv[]) {
    string inputFile;
    double userPathAngle;
    string userOption;
    vector<double> pathAngle, liftCoeff;

    // Get input file from 2nd argument in command line
    inputFile = argv[1];

    readData(inputFile, pathAngle, liftCoeff);

    cout << "Enter a flight-path angle: "; 
    cin >> userPathAngle;

    // Calculate the min and max of the flight path angle
    double minVal = 0;
    double maxVal = 0;
    for (unsigned i = 0; i < pathAngle.size(); ++i) {
        if (pathAngle.at(i) < minVal) {
            minVal = pathAngle.at(i);
        }
        if (pathAngle.at(i) > maxVal) {
            maxVal = pathAngle.at(i);
        }
    }

    bool vectorOrdered = isOrdered(pathAngle);

    if (vectorOrdered == true) {
        // Verifies that the user-inputted path angle is within the given data range
        if ((userPathAngle >= minVal) && (userPathAngle <= maxVal)) {
            cout << interpolation(userPathAngle, pathAngle, liftCoeff) << endl;
        }
        else {
            cout << "Enter another flight-path angle: ";
            cin >> userPathAngle;
            cout << interpolation(userPathAngle, pathAngle, liftCoeff) << endl;
        }
    }
    else {
        reorder(pathAngle, liftCoeff);

        if ((userPathAngle >= minVal) && (userPathAngle <= maxVal)) {
            cout << interpolation(userPathAngle, pathAngle, liftCoeff) << endl;
        }
        else {
            cout << "Enter another flight-path angle: ";
            cin >> userPathAngle;
            cout << interpolation(userPathAngle, pathAngle, liftCoeff) << endl;
        }
    }
    
    while (userOption != "No") {
        cout << "Would you like to enter another flight-path angle? (\"Yes\" or \"No\"): ";
        cin >> userOption;

        if (userOption == "Yes") {
            cout << "Enter a flight-path angle: "; 
            cin >> userPathAngle;

            if (isOrdered(pathAngle) == 1) {
                // Verifies that the user-inputted path angle is within the given data range
                if ((userPathAngle >= minVal) && (userPathAngle <= maxVal)) {
                    cout << interpolation(userPathAngle, pathAngle, liftCoeff) << endl;
                }
                else {
                    cout << "Enter another flight-path angle: ";
                    cin >> userPathAngle;
                    cout << interpolation(userPathAngle, pathAngle, liftCoeff) << endl;
                }
            }
            else {
                reorder(pathAngle, liftCoeff);

                if ((userPathAngle >= minVal) && (userPathAngle <= maxVal)) {
                    cout << interpolation(userPathAngle, pathAngle, liftCoeff) << endl;
                }
                else {
                    cout << "Enter another flight-path angle: ";
                    cin >> userPathAngle;
                    cout << interpolation(userPathAngle, pathAngle, liftCoeff) << endl;
                }
            }
        }
    }

}

void readData(const string &inputFile, vector<double> &angleVector, vector<double> &liftVector) {
    ifstream inputFS;
    double angle, liftCoeff;
    
    inputFS.open(inputFile);

    if (!inputFS.is_open()) {
        cout << "Error opening " << inputFile << endl;
        exit(1);
    }

    while (inputFS >> angle) {
        inputFS >> liftCoeff;
        angleVector.push_back(angle);
        liftVector.push_back(liftCoeff);
    }

    inputFS.close();
}

double interpolation(double userVal, const vector<double> &angleVector, const vector<double> &liftVector) {
    // find next value greater than userVal and previous value less than userVal in angleVector
    double nextLargest = 0;
    double previousSmallest = 0;
    int previousSmallest_IDX = 0;
    int nextLargest_IDX = 0;
    double liftVector_userVal = 0;

    for (unsigned i = 0; i < angleVector.size(); ++i) {
        if (angleVector.at(i) == userVal) {
            return liftVector.at(i);
        }
        if (angleVector.at(i) < userVal) {
            if (angleVector.at(i+1) > userVal) {
                previousSmallest = angleVector.at(i);
                previousSmallest_IDX = i;
            }
        }
        if (angleVector.at(i) > userVal) {
            if (angleVector.at(i-1) < userVal){
                nextLargest = angleVector.at(i);
                nextLargest_IDX = i;
            }
        }
    }

    // if path angle userVal doesnt exist in angleVector, then use the formula below to find coefficient of lift at path angle userVal:    

    // f(b) = f(a) + ((b - a)/(c - a))(f(c) - f(a))

    liftVector_userVal = liftVector.at(previousSmallest_IDX) + ((userVal - previousSmallest) / (nextLargest - previousSmallest)) * (liftVector.at(nextLargest_IDX) - liftVector.at(previousSmallest_IDX));

    return liftVector_userVal;

}

bool isOrdered(const vector<double> &vector) {
    if (vector.size() <= 1) {
        return true;
    }
    for (unsigned i = 0; i < vector.size() - 1; ++i) {
        if (vector.at(i) > vector.at(i + 1)) {
            return false;
        }
    }
    return true;
}

void reorder(vector<double> &angleVector, vector<double> &liftVector) {
    if ((angleVector.empty()) || (liftVector.empty())) {
        cout << "One or more vectors are empty" << endl;
        exit(EXIT_FAILURE);
    }
    for (unsigned i = 0; i < angleVector.size() - 1; ++i) {
        if ((i < 2) && (angleVector[i] > angleVector[i + 1])) {
            swap(angleVector[0], angleVector[1]);
            swap(liftVector[0], liftVector[1]);
        }
        else {
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