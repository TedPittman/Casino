#include "Roulette.h"

#include <algorithm>
#include <iostream>
#include <random>
#include <sstream>

using namespace std;

RouletteWheel::RouletteWheel() {
    srand(time(nullptr));
    // for standard single zero roulette with 37 pockets
    pockets.push_back({0, GREEN});
    vector<RoulettePocket> standardOrder = {
        {32, RED}, {15, BLACK}, {19, RED}, {4, BLACK},
        {21, RED}, {2, BLACK}, {25, RED}, {17, BLACK},
        {34, RED}, {6, BLACK}, {27, RED}, {13, BLACK},
        {36, RED}, {11, BLACK}, {30, RED}, {8, BLACK},
        {23, RED}, {10, BLACK}, {5, RED}, {24, BLACK},
        {16, RED}, {33, BLACK}, {1, RED}, {20, BLACK},
        {14, RED}, {31, BLACK}, {9, RED}, {22, BLACK},
        {18, RED}, {29, BLACK}, {7, RED}, {28, BLACK},
        {12, RED}, {35, BLACK}, {3, RED}, {26, BLACK}
    };
    // populate pockets vector with standard order
    for (auto &pocket : standardOrder) {
        pockets.push_back(pocket);
    }

}


RoulettePocket RouletteWheel::spin() const {
    int index = rand() % pockets.size();
    return pockets[index];
}

RoulettePocket RouletteWheel::getPocket(int index) const {
    return pockets[index];
}


// RouletteGame gameplay and betting
void RouletteGame::playRoulette() {
    cout << "\nWelcome to Roulette!\n";
    cout << "You can place a bet on:\n"
    << "N. A specific number (0-36)\n"
    << "C. A specific color (R/B)\n"
    << "S. No bet, choose to spectate"<< endl;
    placeBet();
}

// make user choice of how to bet
void RouletteGame::placeBet() {
    string inputLine;
    char choice = ' ';
    bool validChoice = false;
    // loop until an input is acceptable
    while (!validChoice) {
        cout << "Choose bet option\n" << "Choice:";
        // skip leading whitespace
        getline(cin >> ws, inputLine);
        if (!inputLine.empty() && inputLine.size() == 1) {
            choice = toupper(inputLine[0]);
            if (choice == 'N' || choice == 'C' || choice == 'S') {
                validChoice = true;
            } else {
                cout << "Invalid choice. Please enter a valid character choice" << endl;
            }
        } else {
            cout << "Invalid choice. Please enter a valid character choice" << endl;
        }
    }

    int betValue = 0;
    RouletteColor betColor = GREEN;
    // for number
    if (choice == 'N') {
        bool validNumber = false;
        while (!validNumber) {
            cout << "Enter a number (0-36):";
            getline(cin >> ws, inputLine);
            stringstream ss(inputLine);
            if (ss >> betValue) {
                if (betValue >= 0 && betValue <= 36) {
                    validNumber = true;
                } else {
                    cout << "Invalid input. Please try again" << endl;
                }
            } else {
                cout << "Invalid input. Please try again" << endl;
            }
        }
        cout << "You bet on the number " << betValue << endl;
    }
    // for color
    else if (choice == 'C') {
        bool validColor = false;
        while (!validColor) {
            cout << "Enter a color (RED or BLACK):";
            getline(cin >> ws, inputLine);

            // ensure all characters in string are uppercase
            transform(inputLine.begin(), inputLine.end(), inputLine.begin(),
                  [](char c) { return toupper(c); });

            if (inputLine == "RED") {
                betColor = RED;
                validColor = true;
                cout << "You bet on RED\n";
            }
            else if (inputLine == "BLACK") {
                betColor = BLACK;
                validColor = true;
                cout << "You bet on BLACK\n";
            }
            else {
                cout << "Invalid input. Please try again\n";
            }
        }
    }
    else {
        cout << "No bet placed. You will spectate this round." << endl;
    }

    // get a random winning pocket (simulating a real life spin)
    RoulettePocket resultPocket = wheel.spin();

    // print result
    cout << "The wheel landed on " << resultPocket.number << " ";
    if (resultPocket.color == RED) {
        cout << "RED" << endl;
    }
    else if (resultPocket.color == BLACK) {
        cout << "BLACK" << endl;
    }
    else {
        cout << "GREEN" << endl;
    }

    if (choice != 'S') {
        // determine player bet result
        bool won = false;
        if (choice == 'N') {
            if (resultPocket.number == betValue) {
                won = true;
            }
        }
        else if (choice == 'C') {
            if (resultPocket.color == betColor) {
                won = true;
            }
        }

        // output win/loss
        if (won) {
            cout << "You win!\n";
        }
        else {
            cout << "You lose!\n";
        }
    }
}

