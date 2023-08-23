// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks
#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <vector>

#include "card.h"
#include "deck.h"
#include <string>

// Existing player class and functions...

class Player
{

public:
    Player();

    Player(string name) {
        myName = name;
    }

    string getName() const {
        return myName;
    }

    void addCard(Card c);  //adds a card to the hand
    void bookCards(Card c1, Card c2);

    bool checkHandForBook(Card &c1, Card &c2);

    bool rankInHand(Card c) const;

    Card chooseCardFromHand() const;

    bool cardInHand(Card c) const;

    Card removeCardFromHand(Card c);

    string showHand() const;
    string showBooks() const;

    int getHandSize() const;
    int getBookSize() const;

    bool checkHandForPair(Card &c1, Card &c2);

    bool sameRankInHand(Card c) const;

private:

    vector <Card> myHand;
    vector <Card> myBook;

    string myName;
};// Existing Player class code...



#endif
