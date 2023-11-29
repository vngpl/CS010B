#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &);

// Sends to output stream a hand of Cards on a single line, 
// each Card separated by a comma.
// If the vector is empty, do not output anything.
// Example (vector size of 3): Ace of Spades, Two of Hearts, King of Clubs 
ostream & operator<<(ostream &, const vector<Card> &);

int main() {
    srand(2222);
    string yesOrNo = " ", filename = " ";
    ofstream outputFS;
    unsigned numCardsPerHand = 0, numDeals = 0;
    double pairCount = 0;
    Deck test;
    Card cardDealt;
    vector<Card> hand;
    double monteCarloCalc = 0.0;

    while (yesOrNo != "No") {
        cout << "Do you want to output all hands to a file? (Yes/No) ";
        cin >> yesOrNo;
        if (yesOrNo == "Yes") {
            cout << endl << "Enter name of output file: ";
            cin >> filename;
            
            outputFS.open(filename);

            if (!outputFS.is_open()) {
                cout << "Error opening the file." << endl;
            }

            break;
        }
    }
    cout << endl;

    cout << "Enter number of cards per hand: ";
    cin >> numCardsPerHand;
    cout << endl;

    cout << "Enter number of deals (simulations): ";
    cin >> numDeals;
    cout << endl;    

    for (unsigned i = 0; i < numDeals; ++i) {
        test.shuffleDeck();
        for (unsigned j = 0; j < numCardsPerHand; ++j) {
            cardDealt = test.dealCard();
            Card cardForVector(cardDealt.getSuit(), cardDealt.getRank());
            hand.push_back(cardForVector);
        }
        if (hasPair(hand) == true) {
            pairCount += 1;
        }
        if (yesOrNo == "Yes") {
            if (hasPair(hand) == true) {
                outputFS << "Found Pair!! " << hand << endl;
            }
            else {
                outputFS << "             " << hand << endl;
            }
        }
        hand.clear();
    }
    
    if (outputFS.is_open()) {
        outputFS.close();
    }

    monteCarloCalc = (pairCount / static_cast<double> (numDeals)) * 100;

    cout << "Chances of receiving a pair in a hand of " << numCardsPerHand << " cards is: " << monteCarloCalc << "%" << endl;

    return 0;
}

bool hasPair(const vector<Card> &hand) {
    for (unsigned i = 0; i < hand.size(); ++i) {
        for (unsigned j = i + 1; j < hand.size(); ++j) {
            if (hand.at(i).getRank() == hand.at(j).getRank()) {
                return true;
            }
        }
    }
    return false;
}
ostream & operator<<(ostream &out, const vector<Card> &hand) {
    for (unsigned i = 0; i < hand.size(); ++i) {
        if (i != hand.size() - 1) {
            out << hand.at(i) << ", ";
        }
        else {
            out << hand.at(i);
        }
    }
    return out;
}