#include "Deck.h"

#include <algorithm>

Deck::Deck() {
    string suits = "shdc";
    for (char suit : suits) {
        for (unsigned rank = 13; rank >= 1; --rank) {
            theDeck.push_back(Card(suit, rank));
        }
    }
}

Card Deck::dealCard() {
    Card dealtCard = theDeck.back();
    theDeck.pop_back();
    dealtCards.push_back(dealtCard);
    return dealtCard;
}

void Deck::shuffleDeck() {
    for (unsigned i = 0; i < dealtCards.size(); ++i) {
        theDeck.push_back(dealtCards.at(i));
    }
    dealtCards.clear();

    random_shuffle(theDeck.begin(), theDeck.end());
}

unsigned Deck::deckSize() const {
    return theDeck.size();
}