#include <iostream>
#include <fstream>
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;

void dealInitialCards(Deck& deck, Player& player1, Player& player2, int numCards);

int main() {
    ofstream logFile("gofish_results.txt");
    if (!logFile) {
        cerr << "Error opening the log file." << endl;
        return 1;
    }

    // Create the deck and shuffle it
    Deck deck;
    deck.shuffle();

    // Create the players
    Player player1("Player 1");
    Player player2("Player 2");

    // Deal initial cards to the players
    int numInitialCards = 7;
    dealInitialCards(deck, player1, player2, numInitialCards);

    // Start the game
    Player* currentPlayer = &player1; // Player 1 goes first
    Player* otherPlayer = &player2;

    int turnCounter = 0;
    const int maxTurns = 30; // Maximum number of turns before ending the game

    while (true) {
        // Check if the game has reached the maximum number of turns
        if (turnCounter >= maxTurns) {
            cout << "Game ends after " << maxTurns << " turns. It's a tie!" << endl;
            logFile << "Game ends after " << maxTurns << " turns. It's a tie!" << endl;
            break;
        }

        // Output the current state of the game to the log file and console for debugging
        cout << currentPlayer->getName() << "'s turn" << endl;
        logFile << currentPlayer->getName() << "'s turn" << endl;
        cout << "Hand: " << currentPlayer->showHand() << endl;
        logFile << "Hand: " << currentPlayer->showHand() << endl;
        cout << "Books: " << currentPlayer->showBooks() << endl;
        logFile << "Books: " << currentPlayer->showBooks() << endl;

        // Check if the current player's hand is empty
        if (currentPlayer->getHandSize() == 0) {
            // If the hand is empty, draw a card from the deck
            if (deck.size() > 0) {
                Card drawnCard = deck.dealCard();
                currentPlayer->addCard(drawnCard);
                cout << currentPlayer->getName() << " draws a card: " << drawnCard.toString() << endl;
                logFile << currentPlayer->getName() << " draws a card: " << drawnCard.toString() << endl;
            } else {
                cout << "Deck is empty. No cards left to draw." << endl;
                logFile << "Deck is empty. No cards left to draw." << endl;
            }
        }

        // Ask the other player for a card rank
        Card chosenCard = currentPlayer->chooseCardFromHand();
        cout << "Asks: Do you have a " << chosenCard.rankString(chosenCard.getRank()) << "?" << endl;
        logFile << "Asks: Do you have a " << chosenCard.rankString(chosenCard.getRank()) << "?" << endl;

        // Check if the other player has the requested card
        if (otherPlayer->cardInHand(chosenCard)) {
            // Move all cards of the same rank from the other player's hand to the current player's hand
            Card pairCard = otherPlayer->removeCardFromHand(chosenCard);
            currentPlayer->addCard(pairCard);
            currentPlayer->addCard(chosenCard);
            cout << otherPlayer->getName() << " gives " << currentPlayer->getName() << " " << pairCard.toString() << " and " << chosenCard.toString() << endl;
            logFile << otherPlayer->getName() << " gives " << currentPlayer->getName() << " " << pairCard.toString() << " and " << chosenCard.toString() << endl;

            // Check if the current player formed a book (pair)
            if (currentPlayer->checkHandForPair(pairCard, chosenCard)) {
                currentPlayer->bookCards(pairCard, chosenCard);
                cout << currentPlayer->getName() << " books the " << pairCard.rankString(pairCard.getRank()) << endl;
                logFile << currentPlayer->getName() << " books the " << pairCard.rankString(pairCard.getRank()) << endl;
            }
        } else {
            cout << otherPlayer->getName() << " says: Go Fish!" << endl;
            logFile << otherPlayer->getName() << " says: Go Fish!" << endl;
            // If the other player doesn't have the requested card, draw a card from the deck
            if (deck.size() > 0) {
                Card drawnCard = deck.dealCard();
                currentPlayer->addCard(drawnCard);
                cout << currentPlayer->getName() << " draws a card: " << drawnCard.toString() << endl;
                logFile << currentPlayer->getName() << " draws a card: " << drawnCard.toString() << endl;
            } else {
                cout << "Deck is empty. No cards left to draw." << endl;
                logFile << "Deck is empty. No cards left to draw." << endl;
            }
        }

        // Check if the current player has any books
        if (currentPlayer->getBookSize() == 13) {
            // If all books are formed, end the game
            cout << currentPlayer->getName() << " wins!" << endl;
            logFile << currentPlayer->getName() << " wins!" << endl;
            break;
        }

        // Increment the turn counter and swap players for the next turn
        turnCounter++;
        swap(currentPlayer, otherPlayer);
    }

    // Close the log file
    logFile.close();

    return 0;
}

// Helper function to deal initial cards to players
void dealInitialCards(Deck& deck, Player& player1, Player& player2, int numCards) {
    for (int i = 0; i < numCards; i++) {
        player1.addCard(deck.dealCard());
        player2.addCard(deck.dealCard());
    }
}
