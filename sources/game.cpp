#include "player.hpp"
#include "game.hpp"
#include "stdlib.h"
#include "time.h"
#include <iostream>
using namespace ariel;

/*
* Outline implementation of Game
*/

Game::Game(ariel::Player& p1, ariel::Player& p2):
p1{p1}, p2{p2}{
    step(PlayerAction::ReadyToPlay, this->p1);
    step(PlayerAction::ReadyToPlay, this->p2);
    for (size_t i = 0; i < ariel::NUM_OF_CARDS; i++)
    {
        this->cards.push_back(Card(i + 1));
    }
    
}

Game::~Game()
{

}

void Game::playTurn()
{
    // Check if the players are the same, and throw exception if they are
    if (&p1 == &p2)
    {
        throw std::string("The players are the same");
    }
    int num_of_ties = 0;
    if (this->p1.stacksize() == 0 || this->p2.stacksize() == 0)
    {
        throw std::string("One of the players is running out of cards");
    }

    // loop until one of the players win or there is tie
    while (this->p1.stacksize() != 0 && this->p2.stacksize() != 0)
    {
        // Generate random number in range of the number of the remained card
        srand((unsigned)time(NULL));
        unsigned int r1 = (unsigned)rand() % (this->cards.size());
        Card c1 = this->cards[r1];
        // remove the card from the list of cards
        this->cards.erase(this->cards.begin() + r1);
        unsigned int r2 = (unsigned)rand() % (this->cards.size());
        Card c2 = this->cards[r2];
        this->cards.erase(this->cards.begin() + r2);

        // Compare the two cards
        if(compare(c1, c2) > 0){
            // Player 1 win
            step(PlayerAction::Win, this->p1);
            step(PlayerAction::Lose, this->p2);
            this->stats.push_back(1);
            this->turnPrints.push_back(this->p1.to_string() + " played " + c1.to_string() + 
                " " + this->p2.to_string() + " played " + c2.to_string() + " " + this->p1.to_string() + " wins\n");
            for (int i = 0; i < num_of_ties * 4; i++)
            {
                step(PlayerAction::Tie, this->p1);
            }
            return;
        }
        else if(compare(c1, c2) < 0){
            // Player 2 win
            step(PlayerAction::Win, this->p2);
            step(PlayerAction::Lose, this->p1);
            this->stats.push_back(2);
            this->turnPrints.push_back(this->p1.to_string() + " played " + c1.to_string() + 
                " " + this->p2.to_string() + " played " + c2.to_string() + " " + this->p2.to_string() + " wins\n");

            for (int i = 0; i < num_of_ties * 4; i++)
            {
                step(PlayerAction::Tie, this->p2);
            }
            return; 
        }
        else{
            // Tie
            step(PlayerAction::Lose, this->p2);
            step(PlayerAction::Lose, this->p1);
            this->stats.push_back(0);
            this->turnPrints.push_back(this->p1.to_string() + " played " + c1.to_string() + 
                " " + this->p2.to_string() + " played " + c2.to_string() + " Draw ");
            num_of_ties++;

            if (this->p1.stacksize() == 0 || this->p2.stacksize() == 0)
            {
                for (int i = 0; i < (num_of_ties-1) * 2 + 1; i++)
                {
                    step(PlayerAction::Tie, this->p1);
                    step(PlayerAction::Tie, this->p2);
                }
                this->turnPrints.push_back("\n");
                return;
            }
            // remove another card from the list of cards for each player
            step(PlayerAction::Lose, this->p2);
            step(PlayerAction::Lose, this->p1);
            r1 = (unsigned)rand() % (this->cards.size());
            this->cards.erase(this->cards.begin() + r1);
            r2 = (unsigned)rand() % (this->cards.size());
            this->cards.erase(this->cards.begin() + r2);
        }
    }

    // In case the game is over and there is tie
    for (int i = 0; i < (num_of_ties) * 2; i++)
    {
        step(PlayerAction::Tie, this->p1);
        step(PlayerAction::Tie, this->p2);
    }
   
    return;
}
void Game::printLastTurn() const
{
    if (this->cards.size() == 0)
    {
        std::cout << "No turns played yet" << std::endl;
    }
    else
    {
        std::cout << this->turnPrints[this->turnPrints.size() - 1];
    }
}
void Game::playAll()
{
    while (this->p1.stacksize() != 0 && this->p2.stacksize() != 0)
    {
        playTurn();
    }
    return;
}
void Game::printWiner() const
{
    if (this->p1.stacksize() != 0 && this->p2.stacksize() != 0)
    {
        std::cout << "The game is not over yet" << std::endl;
    }
    else
    {
        if (this->p1.cardesTaken() > this->p2.cardesTaken())
        {
            std::cout << this->p1.to_string() << " wins" << std::endl;
        }
        else if (this->p1.cardesTaken() < this->p2.cardesTaken())
        {
            std::cout << this->p2.to_string() << " wins" << std::endl;
        }
        else
        {
            std::cout << "The game is tie" << std::endl;
        }
        
    }
    
    
}
void Game::printLog() const
{
    for (size_t i = 0; i < this->turnPrints.size(); i++)
    {
        std::cout << this->turnPrints[i];
    }
    
}
void Game::printStats() const
{
    int cards_won_p1 = 0;
    int cards_won_p2 = 0;
    int draw_rate = 0;

    // Calculate the win rate of player 1 & player 2 by summing the number of winning turn in the stats vector
    for (size_t i = 0; i < this->stats.size(); i++)
    {
        if (this->stats[i] == 1)
        {
            cards_won_p1++;
        }
        else if (this->stats[i] == 2)
        {
            cards_won_p2++;
        }
        else
        {
            draw_rate++;
        }
    }
    

    std::cout << "Statistics:" << std::endl;
    // The win rate of player 1 is the number of winning turns divided by the number of all turns
    std::cout << "Player 1: " << this->p1.to_string() << " win rate: " << (double)(unsigned int)cards_won_p1 / this->stats.size();
    std::cout << " cards won: " << cards_won_p1 << std::endl;
    // The win rate of player 2 is the number of winning turns divided by the number of all turns
    std::cout << "Player 2: " << this->p2.to_string() << " win rate: " << (double)(unsigned int)cards_won_p2 / this->stats.size();
    std::cout << " cards won: " << cards_won_p2 << std::endl;
    // print the draw rate and the amount of draws
    std::cout << "draw rate: " << (double)(unsigned int)draw_rate / this->stats.size() << " draws: " << draw_rate << std::endl;
}


