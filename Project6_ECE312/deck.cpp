#include "deck.h"
#include <algorithm>
#include <random>

Deck::Deck() : myIndex(0) {
    int card = 0;
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 1; rank <= 13; rank++) {
            myCards[card++] = Card(rank, static_cast<Card::Suit>(suit));
        }
    }
}

void Deck::shuffle() {
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(myCards), std::end(myCards), rng);
    myIndex = 0;
}

Card Deck::dealCard() {
    if (size() > 0)
        return myCards[myIndex++];
    else
        throw std::out_of_range("Deck is empty");
}

int Deck::size() const {
    return SIZE - myIndex;
}
