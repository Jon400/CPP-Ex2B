#pragma once
#include "player.hpp"
#include "card.hpp"
#include <vector>

namespace ariel
{
    const int NUM_OF_CARDS = 52;
    class Game
    {
    private:
        ariel::Player& p1, p2; // Player objects of the game
        std::vector<ariel::Card> cards; // List of cards in the play
    public:
        Game(ariel::Player&, ariel::Player&);
        ~Game();
        // Const prevents function from modify the pointer this and its values
        void playTurn();
        void printLastTurn() const;
        void playAll();
        void printWiner() const;
        void printLog() const;
        void printStats() const;
    };    
}