#include "player.hpp"
#include "game.hpp"
#include <string>
using namespace ariel;

/*
* Outline implementation of Player
*/

Player::Player()
{
    Player("");
}

Player::Player(std::string player_name)
{
    this->player_name = player_name;
    this->stackSize = 0;
    this->cardsTaken = 0;
}

Player::~Player()
{

}

// Dummy implementation of the functions below:

int Player::stacksize() const
{
    return this->stackSize;
}

int Player::cardesTaken() const
{
    return this->cardsTaken;
}

std::string Player::to_string() const
{
    return this->player_name;
}

void ariel::step(int actionId, ariel::Player & p)
{
    switch (actionId)
    {
        case PlayerAction::ReadyToPlay:
            p.stackSize = ariel::NUM_OF_CARDS / 2;
            p.cardsTaken = 0;
            break;
        case PlayerAction::Win:
            p.stackSize --;
            p.cardsTaken +=2;
            break;
        case PlayerAction::Lose:
            p.stackSize --;
            break;
        case PlayerAction::Tie:
            p.cardsTaken ++;
            break;
        default:
            break;
    }
}
