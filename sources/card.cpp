#include "card.hpp"
#include <string>
using namespace ariel;

/*
* Outline implementation of Card
*/

Card::Card(int num)
{
    this->num = num;
}

std::string Card::to_string() const
{
    // Extract the number of the card from num
    std::string str, name, type = "";
    switch ((this->num / 4) + 1)
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
            type = "Spades";
            break;
        case CardTypes::Hearts:
            type = "Hearts";
            break;
        case CardTypes::Diamonds:
            type = "Diamonds";
            break;
        default:
            type = "Clubs";
            break;
    }

    // Concatenation of the card name
    str = name + " of " + type;
    return str;
}


Card::~Card()
{

}

int ariel::compare(const Card & c1, const Card & c2)
{
    return (c1.num / 4) - (c2.num / 4);
}
