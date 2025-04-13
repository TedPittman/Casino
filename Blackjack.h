#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <string>
#include <vector>
#include "Card.h"
using namespace std;


// blackjack card class inheriting from Card
class BlackjackCard : public Card {
public:
    // constructor for a card with given rank and suit
    BlackjackCard(Rank r, Suit s) : Card(r, s), aceValue(false) {}

    // sets the bool of whether ace is treated as an 11
    void setAceAsEleven(bool isEleven) {
        if (rank == ACE) {
            aceValue = isEleven;
        }
    }
    // checks if this card is an Ace
    bool isAce() const {
        return (rank == ACE);
    }
    // return blackjack value for each card
    int getCardValue() const override {
        // All number cards hold their own value, A = 1, face cards = 10
        if (rank >= JACK && rank <= KING) {
            return 10;
        }
        if (rank == ACE) {
            return (aceValue ? 11 : 1);
        }
        return rank;
    }

    // string representation of a card with rank and suit
    string cardToString() const override {
        string rankString;
        switch (rank) {
            case ACE: rankString = "A"; break;
            case TWO: rankString = "2"; break;
            case THREE: rankString = "3"; break;
            case FOUR: rankString = "4"; break;
            case FIVE: rankString = "5"; break;
            case SIX: rankString = "6"; break;
            case SEVEN: rankString = "7"; break;
            case EIGHT: rankString = "8"; break;
            case NINE: rankString = "9"; break;
            case TEN: rankString = "10"; break;
            case JACK: rankString = "J"; break;
            case QUEEN: rankString = "Q"; break;
            case KING: rankString = "K"; break;
            default: rankString = "?"; break;
        }

        string suitString;
        switch (suit) {
            case HEARTS: suitString = "H"; break;
            case DIAMONDS: suitString = "D"; break;
            case CLUBS: suitString = "C"; break;
            case SPADES: suitString = "S"; break;
        }

        return rankString + suitString;
    }

private:
    bool aceValue; // whether ace is a 1(f) or 11(t)
};


// Blackjack player hand class
class BlackjackHand {
public:
    BlackjackHand() = default;
    // adds given card to hand
    BlackjackHand& operator += (const BlackjackCard& inputCard);

    // calculates total value of a hand
    int getTotalCardValue() const;
    // t if busted (value > 21), f if not
    bool busted() const;
    // removes all cards from hand
    void clear();
    // prints hand
    void printHand() const;

    // check for availability to split hands
    //      bool isPair() const;
    // return and remove the second card if split
    //      BlackjackCard removeSecondCard() const;

    // return string of a card at an index to allow dealer to hide card
    string getCardString(int index) const;
    // returns number of cards in a hand
    int handSize() const { return cardsInHand.size(); }
    // access card object to set ace value, returns reference to card object
    BlackjackCard& getCardReference(int index);

private:
    // vector to represent a game hand of BlackjackCards
    vector<BlackjackCard> cardsInHand;
};


// Blackjack game class
class BlackjackGame {
public:
    // default constructor
    BlackjackGame() = default;
    // starts and controls one blackjack round
    void playBlackjack();

private:
    // deck is a vector holding cards
    vector<BlackjackCard> deck;
    int nextCardIndex = 0;
    // initializes standard 52 card deck
    void initializeDeck();
    // draws a card without replacement from deck and returns that card object
    BlackjackCard drawCard();

    // starts player turn
    void playerTurn(BlackjackHand& playerHand, const string &handName);
    // starts dealers turn
    bool dealerTurn(BlackjackHand& dealerHand);
    // prompts user to choose the value of an Ace in their hand
    static void promptAceValue(BlackjackCard& card);
};



#endif //BLACKJACK_H
