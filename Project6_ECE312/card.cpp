//This is card.cpp
// Created by fahim on 7/26/2023.
//
#include "card.h"

Card::Card() : myRank(1), mySuit(spades) {
    // Default constructor initializes card to Ace of Spades
}

Card::Card(int rank, Suit s) : myRank(rank), mySuit(s) {
    // initializes card with provided rank and suit
}

string Card::toString() const {
    return rankString(myRank) + suitString(mySuit);
}

bool Card::sameSuitAs(const Card& c) const {
    return mySuit == c.mySuit;
}

int Card::getRank() const {
    return myRank;
}

string Card::suitString(Suit s) const {
    switch(s) {
        case spades:   return "s";
        case hearts:   return "h";
        case diamonds: return "d";
        case clubs:    return "c";
        default:       return "invalid suit";
    }
}

string Card::rankString(int r) const {
    static const string ranks[] = {"", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    if (r < 1 || r > 13) {
        return "invalid rank";
    }
    return ranks[r];
}

bool Card::operator == (const Card& rhs) const {
    return myRank == rhs.myRank && mySuit == rhs.mySuit;
}

bool Card::operator != (const Card& rhs) const {
    return !(*this == rhs);
}

ostream& operator << (ostream& out, const Card& c) {
    out << c.toString();
    return out;
}
