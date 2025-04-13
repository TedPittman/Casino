#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;
// card class to be used in casino games with cards

enum Rank {
    ACE = 1,
    TWO, THREE, FOUR, FIVE, SIX,
    SEVEN, EIGHT, NINE, TEN,
    JACK, QUEEN, KING
};

enum Suit {
    CLUBS, DIAMONDS, HEARTS, SPADES
};

class Card {
protected:
    Rank rank;
    Suit suit;
public:
    // constructs card with inputted rank and suit
    Card(Rank r, Suit s) : rank(r), suit(s) {}
    // virtual destructor
    virtual ~Card() = default;

    Rank getRank() const { return rank; }
    Suit getSuit() const { return suit; }

    virtual int getCardValue() const = 0;
    virtual string cardToString() const = 0;
};

#endif //CARD_H
