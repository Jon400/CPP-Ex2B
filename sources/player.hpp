#pragma once

#include <string>

namespace ariel
{
    enum PlayerAction{ReadyToPlay, Win, Lose, Tie};

    class Player
    {
    private:
        std::string player_name;
        int stackSize; // number of cards that the player has
        int cardsTaken; // number of cards which the player take during the game
    public:
        Player();
        Player(std::string);
        ~Player();
        // Const prevents function from modify the pointer this and its values
        int stacksize() const;
        int cardesTaken() const;
        std::string to_string() const;
        friend void step(int, ariel::Player&);
    };
}