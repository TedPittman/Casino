#ifndef CASINO_H
#define CASINO_H

#include "Blackjack.h"
#include "Slotmachine.h"
#include "Roulette.h"


// Casino class
class Casino {
public:
    // constructor
    Casino();
    // run game menu and process user input to start a game
    void run();

private:
    // initialize each of available games
    BlackjackGame bjGame;
    SlotMachineGame smGame;
    RouletteGame rGame;
    // displays the menu and gets user game choice
    static int menuChoice();
};


#endif //CASINO_H
