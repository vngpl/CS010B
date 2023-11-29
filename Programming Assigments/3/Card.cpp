#include "Card.h"

Card::Card() {
    suit = 'c';
    rank = 2;
}

Card::Card(char s, int r) {
    if (s == 'c' || s == 'C' || s == 'h' || s == 'H' || s == 'd' || s == 'D' || s == 's' || s == 'S') {
        suit = tolower(s);
    }
    if (r <= 13 || r >= 1) {
        rank = r;
    }
    else {
        rank = 2;
    }
}

char Card::getSuit() const {
    return suit;
}

int Card::getRank() const {
    return rank;
}

ostream & operator<<(ostream &out, const Card &rhs) {
    string suitName = "-";
    string rankName = "-";

    if (rhs.suit == 'c') {
        suitName = "Clubs";
    }
    else if (rhs.suit == 'h') {
        suitName = "Hearts";
    }
    else if (rhs.suit == 'd') {
        suitName = "Diamonds";
    }
    else if (rhs.suit == 's') {
        suitName = "Spades";
    }

    if (rhs.rank == 1 || rhs.rank == 11 || rhs.rank == 12 || rhs.rank == 13) {
        if (rhs.rank == 1) {
            rankName = "Ace";
        }
        else if (rhs.rank == 11) {
            rankName = "Jack";
        }
        else if (rhs.rank == 12) {
            rankName = "Queen";
        }
        else if (rhs.rank == 13) {
            rankName = "King";
        }
        out << rankName << " of " << suitName;
    }
    else {
        out << rhs.rank << " of " << suitName;
    }

    return out;
}