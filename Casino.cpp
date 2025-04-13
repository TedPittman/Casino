#include "Casino.h"
#include <iostream>
#include <sstream>

using namespace std;

// Casino class implement
Casino::Casino() {
    srand(time(nullptr));
}

int Casino::menuChoice() {
    string input;
    int choice;

    while (true) {
        cout << "\nWelcome to the Casino!\nPlease choose an option below.\n"
        << "1. Play Blackjack\n" << "2. Play SlotMachine\n" << "3. Play Roulette\n" << "4. Exit\n"
        << "Enter your choice:";
        getline(cin >> ws, input);
        stringstream ss(input);
        if (!input.empty() && input.size() == 1) {
            if (ss >> choice) {
                return choice;
            } else {
                cout << "Invalid input, please enter a valid integer choice.\n";
            }
        } else {
            cout << "Invalid input, please enter a valid integer choice.\n";
        }
    }
}

void Casino::run() {
    bool running = true;
    while (running) {
        int choice = menuChoice();
        switch (choice) {
            case 1:
                bjGame.playBlackjack();
                break;
            case 2:
                smGame.playSlots();
                break;
            case 3:
                rGame.playRoulette();
                break;
            case 4:
                cout << "Exiting Casino.\n";
                running = false;
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}


// main
int main() {
    Casino casino;
    casino.run();
    return 0;
}