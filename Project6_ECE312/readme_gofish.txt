Fahim Imtiaz (EID: fmi89)

Go Fish Game Implementation
-----------------------------

This program implements the Go Fish card game with two players. The goal of the game is for each player to form pairs of cards with the same rank and place them in books. The player who forms the most books at the end of the game is the winner.

Files:
- card.h, card.cpp: Defines and implements the Card class, representing a playing card with a rank and a suit.
- deck.h, deck.cpp: Defines and implements the Deck class, representing a deck of 52 cards and providing functionality to shuffle and deal cards.
- player.h, player.cpp: Defines and implements the Player class, representing a player in the game, with functions to manage the player's hand and books.
- go_fish.cpp: Contains the main function and game loop for the Go Fish game.
- card_demo.cpp: A separate program to demonstrate the Card class functionality (not used in the main game).

Compilation and Execution:
- The code can be compiled using any C++ compiler that supports C++11 or later.
- A makefile is included to simplify the compilation process. Use the "make" command to build the executable "Proj6".
- Execute the program by running "Proj6 gofish_results.txt" in the command prompt.

Gameplay and Output:
- The game will simulate the play between two computer players.
- Each turn and the actions of the players will be logged in the "gofish_results.txt" file.
- The game ends when any of the following conditions are met:
  1. The deck is empty, and both players have no more cards to draw.
  2. Both players have formed all possible books (pairs of cards with the same rank).
  3. 30 turns have passed since the start of the game.
- If any of the above conditions are met, the game will end, and the winner will be determined based on the number of books formed by each player.

Note:
- This program is for educational purposes and to demonstrate the implementation of the Go Fish game.
- The program uses a fixed number of turns (30) to end the game for demonstration purposes. In a real game, the game could continue until all books are formed or the deck is empty.

Enjoy the Go Fish game!

