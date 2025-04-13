#include "Blackjack.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <sstream>
using namespace std;


// BlackjackHand class implement
// -----------------------------------------------------------
BlackjackHand& BlackjackHand::operator += (const BlackjackCard& inputCard) {
    // add input cards to hand and return reference to changed hand
    cardsInHand.push_back(inputCard);
    return *this;
}

int BlackjackHand::getTotalCardValue() const {
    int total = 0;
    // for every card in hand, add its value to total
    for (const auto& card : cardsInHand) {
        total += card.getCardValue();
    }
    return total;
}

bool BlackjackHand::busted() const {
    return getTotalCardValue() > 21;
}

void BlackjackHand::clear() {
    cardsInHand.clear();
}

void BlackjackHand::printHand() const {
    // example (7D, 3S) == Total: 10
    cout << "(";
    for (int i = 0; i < handSize(); i++) {
        cout << cardsInHand[i].cardToString();
        if (i < handSize() - 1) {
            cout << ", ";
        }
    }
    cout << ") == Total: " << getTotalCardValue() << "\n";
}

// bool BlackjackHand::isPair() const {
//     if (cardsInHand.size() == 2) {
//         return (cardsInHand[0].getCardValue() == cardsInHand[1].getCardValue());
//     }
//     return false;
// }

// for split hands
// BlackjackCard BlackjackHand::removeSecondCard() const {
//     BlackjackCard secondCard = cardsInHand[1];
//     // erase from vec
// }

string BlackjackHand::getCardString(int index) const {
    if (index < handSize()) {
        return cardsInHand[index].cardToString();
    }
    return "";
}

// return non const reference to change value of ace
BlackjackCard& BlackjackHand::getCardReference(int index) {
    return cardsInHand[index];
}




// BlackjackGame class implement
// --------------------------------------------------------------------
void BlackjackGame::playBlackjack() {
    srand(time(nullptr));
    initializeDeck();

    cout << "\nWelcome to the Blackjack Game!\n";
    BlackjackHand playerHand;
    BlackjackHand dealerHand;

    // generate 2 random cards for player and dealer
    for (int i = 0; i < 2; i++) {
        // use overloaded operator to add cards
        playerHand += drawCard();
        dealerHand += drawCard();
    }

    // if an ace is in the players initial dealt cards then prompt for value
    for (int i = 0; i < playerHand.handSize(); i++) {
        if (playerHand.getCardReference(i).isAce()) {
            promptAceValue(playerHand.getCardReference(i));
        }
    }

    // show only dealer first card and keep second hidden
    cout << "Dealer's hand: (" << dealerHand.getCardString(0) << ", [Hidden])\n";

    playerTurn(playerHand, "Player's hand");

    if (playerHand.busted()) {
        cout << "You busted. Dealer wins!\n";
        return;
    }

    // if dealer busted
    if (dealerTurn(dealerHand)) {
        return;
    }

    int dealerTotal = dealerHand.getTotalCardValue();
    int playerTotal = playerHand.getTotalCardValue();

    if (playerHand.busted()) {
        cout << "You busted. Dealer wins!\n";
    } else if (dealerHand.busted()) {
        cout << "Dealer busted. You win!\n";
    } else {
        if (playerTotal > dealerTotal) {
            cout << "You win!\n";
        } else if (playerTotal < dealerTotal) {
            cout << "Dealer wins!\n";
        } else {
            cout << "It's a tie!\n";
        }
    }
}

void BlackjackGame::initializeDeck() {
    deck.clear();
    // fill with the 52 unique cards
    for (int s = HEARTS; s <= SPADES; s++) {
        for (int r = ACE; r <= KING; r++) {
            deck.push_back(BlackjackCard(static_cast<Rank>(r), static_cast<Suit>(s)));
        }
    }
    // shuffle deck
    random_device rd;
    mt19937 generator(rd());
    shuffle(deck.begin(), deck.end(), generator);
    nextCardIndex = 0;
}

// draw cards without replacement
BlackjackCard BlackjackGame::drawCard() {
    return deck[nextCardIndex++];
}


void BlackjackGame::playerTurn(BlackjackHand& playerHand, const string &handName) {
    cout << handName << ": ";
    playerHand.printHand();

    while (!playerHand.busted()) {
        cout << "Hit[h] or stand[s]?:";
        string input;
        getline(cin >> ws, input);
        stringstream ss(input);
        char choice;

        if (input.empty()) {
            cout << "No input provided. Please try again\n";
            continue;
        }
        if (input.size() != 1) {
            cout << "Invalid input. Please try again\n";
            continue;
        }

        if (ss >> choice) {
            if (choice == 'h' || choice == 'H') {
                playerHand += drawCard();
                cout << handName << " after Hit: ";
                playerHand.printHand();
            } else if (choice == 's' || choice == 'S') {
                cout << "You chose to stand.\n";
                break;
            } else {
                cout << "Invalid input, please enter either H or S!\n";
            }
        }


    }
}
// hits until total >= 17
bool BlackjackGame::dealerTurn(BlackjackHand& dealerHand) {
    cout << "\nDealer's turn!\n";
    cout << "Dealer reveals hidden card: " << dealerHand.getCardString(1) << "\n";

    cout << "Dealer's hand: ";
    dealerHand.printHand();

    while (dealerHand.getTotalCardValue() < 17) {
        cout << "Dealer hits.\n";
        dealerHand += drawCard();
        cout << "Dealer's hand: ";
        dealerHand.printHand();

        if (dealerHand.busted()) {
            cout << "Dealer busted. You win!\n";
            return true;
        }
    }
    // dealer did not bust and stands
    cout << "Dealer stands.\n";
    return false;
}

void BlackjackGame::promptAceValue(BlackjackCard& card) {
    while (true) {
        cout << "You have an Ace in your hand, would you like it to be [1] or [11]?";
        string input;
        getline(cin >> ws, input);
        stringstream ss(input);
        int choice;

        if (ss >> choice) {
            if (choice == 1) {
                card.setAceAsEleven(false);
                break;
            } else if (choice == 11) {
                card.setAceAsEleven(true);
                break;
            } else {
                cout << "Invalid input, please enter either 1 or 11!\n";
            }
        } else {
            cout << "Invalid input, please enter either 1 or 11!\n";
        }
    }
    cout << endl;
}

