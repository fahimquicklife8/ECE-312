// player.cpp
// Created by fahim on 7/26/2023.

#include "player.h"
#include <algorithm>




Player::Player() : myName("") {}

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);

    myHand.erase(remove(myHand.begin(), myHand.end(), c1), myHand.end());
    myHand.erase(remove(myHand.begin(), myHand.end(), c2), myHand.end());
}

bool Player::checkHandForBook(Card &c1, Card &c2) {
    // implementation depends on your specific game logic
    return false;
}

bool Player::rankInHand(Card c) const {
    for (const auto& card : myHand) {
        if (card.getRank() == c.getRank()) {
            return true;
        }
    }
    return false;
}

Card Player::chooseCardFromHand() const {
    // Choosing the first card in the hand
    if (!myHand.empty()) {
        return myHand[0];
    }
    // TODO: Handle the error case when the hand is empty
    return Card();
}

bool Player::cardInHand(Card c) const {
    return find(myHand.begin(), myHand.end(), c) != myHand.end();
}

Card Player::removeCardFromHand(Card c) {
    auto pos = find(myHand.begin(), myHand.end(), c);
    if (pos != myHand.end()) {
        myHand.erase(pos);
        return c;
    }
    // TODO: Handle the error case when the card is not in hand
    return Card();
}

string Player::showHand() const {
    string hand;
    for (const auto& card : myHand) {
        hand += card.toString() + " ";
    }
    return hand;
}

string Player::showBooks() const {
    string books;
    for (const auto& card : myBook) {
        books += card.toString() + " ";
    }
    return books;
}

int Player::getHandSize() const {
    return myHand.size();
}

int Player::getBookSize() const {
    return myBook.size();
}

bool Player::checkHandForPair(Card &c1, Card &c2) {
    // implementation depends on your specific game logic
    return false;
}

bool Player::sameRankInHand(Card c) const {
    return rankInHand(c);
}
