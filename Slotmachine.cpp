#include "Slotmachine.h"


SlotMachineGame::SlotMachineGame() {
    slots[0] = CHERRY;
    slots[1] = CHERRY;
    slots[2] = CHERRY;
}

string SlotMachineGame::toString(SlotOptions symbol) {
    switch (symbol) {
        case CHERRY: return "CHERRY";
        case LUCKYSEVEN: return "LUCKYSEVEN";
        case MONEY: return "MONEY";
        case DICE: return "DICE";
        case HORSESHOE: return "HORSESHOE";
        case LEMON: return "LEMON";
        case DIAMOND: return "DIAMOND";
    }
    return "";
}

void SlotMachineGame::spin() {
    srand(time(nullptr));

    static const SlotOptions reelSymbols[7] = {
        CHERRY, LUCKYSEVEN, MONEY, DICE, HORSESHOE, LEMON, DIAMOND
    };


    for (auto &slot : slots) {
        int outcome = rand() % 7;
        slot = reelSymbols[outcome];
    }
}

void SlotMachineGame::printSlots() const {
    cout << toString(slots[0]) << ", "
        << toString(slots[1]) << ", "
        << toString(slots[2]) << endl;
}


void SlotMachineGame::playSlots() {
    cout << "\nWelcome to the SlotMachine Game!\n";
    spin();
    printSlots();

    // if all three symbols match then win
    if (slots[0] == slots[1] && slots[1] == slots[2]) {
        cout << "You win!\n";
    } else {
        cout << "You lose!\n";
    }
}
