#pragma once
#include <string>

namespace ariel
{
    const enum CardNames { Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
    const enum CardTypes { Spades = 1, Hearts, Diamonds, Clubs};
    class Card
    {
        private:
            int num; // Number represents a card in a range of 1 - 52
        public:
            Card(int);
            std::string to_string()
            {
                // Extract the number of the card from num
                std::string str, name, type = "";
                switch ((num / 4) + 1)
                {
                    case CardNames::Ace:
                        name = "Ace";
                        break;
                    case CardNames::Two:
                        name = "Two";
                        break;
                    case CardNames::Three:
                        name = "Three";
                        break;
                    case CardNames::Four:
                        name = "Four";
                        break;
                    case CardNames::Five:
                        name = "Five";
                        break;
                    case CardNames::Six:
                        name = "Six";
                        break;
                    case CardNames::Seven:
                        name = "Seven";
                        break;
                    case CardNames::Eight:
                        name = "Eight";
                        break;
                    case CardNames::Nine:
                        name = "Nine";
                        break;
                    case CardNames::Ten:
                        name = "Ten";
                        break;
                    case CardNames::Jack:
                        name = "Jack";
                        break;
                    case CardNames::Queen:
                        name = "Queen";
                        break;
                    default:
                        name = "King";
                        break;
                }
                
                // Extract the type name of the card from num
                switch ((num % 4) + 1)
                {
                    case CardTypes::Spades:
                        name = "Spades";
                        break;
                    case CardTypes::Hearts:
                        name = "Hearts";
                        break;
                    case CardTypes::Diamonds:
                        name = "Diamonds";
                        break;
                    default:
                        name = "Clubs";
                        break;
                }

                // Concatenation of the card name
                str = name.append(" of ").append(type);
                return str;

            }
            ~Card();
    };
    
}