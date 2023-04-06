#pragma once
#include <string>

namespace ariel
{
    enum CardNames { Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
    enum CardTypes { Spades = 1, Hearts, Diamonds, Clubs};
    class Card
    {
        private:
            int num; // Number represents a card in a range of 1 - 52
        public:
            Card(int);
            Card(const Card&) = default; // copy constructor
            Card(Card&&) noexcept = default; // move constructor
            Card& operator=(Card&&) noexcept = default; // move assignment operator
            Card& operator=(Card&) noexcept = delete; // copy assignment operator
            std::string to_string() const;
            friend int compare(const Card&, const Card&); // compare between two cards
            ~Card();
    };
    
}