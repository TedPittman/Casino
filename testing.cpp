#include <ctime>
#include <iostream>
#include <random>
#include "Roulette.h"
#include "Blackjack.h"
#include "Slotmachine.h"
using namespace std;

bool testBlackjack();
bool testSlotMachine();
bool testRoulette();

int main() {
    srand(time(nullptr));

    if (testBlackjack()) {
        cout << "Passed all Blackjack test cases" << endl;
    }
    if (testSlotMachine()) {
        cout << "Passed all SlotMachine test cases" << endl;
    }
    if (testRoulette()) {
        cout << "Passed all Roulette test cases" << endl;
    }

    return 0;
}


bool testBlackjack() {
    bool passed = true;
    BlackjackGame bjGame;

    return passed;
}

bool testSlotMachine() {
    bool passed = true;
    SlotMachineGame smGame;

    return passed;
}

bool testRoulette() {
    bool passed = true;
    RouletteGame rGame;

    return passed;
}