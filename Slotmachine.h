#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include <iostream>
using namespace std;

// available slot symbols on each wheel
enum SlotOptions {
    CHERRY,
    LUCKYSEVEN,
    MONEY,
    DICE,
    HORSESHOE,
    LEMON,
    DIAMOND
};

// slot machine class
class SlotMachineGame {

public:
    // default constructor
    SlotMachineGame();

    // turn enum symbol into a string equivalent
    static string toString(SlotOptions symbol);
    // chooses random symbols from each wheel containing all 7 symbols
    void spin();
    // print the chosen 3 symbols
    void printSlots() const;
    // main function to play at the machine for one spin
    void playSlots();

private:
    SlotOptions slots[3]{};
};


#endif //SLOTMACHINE_H
