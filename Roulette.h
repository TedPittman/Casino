#ifndef ROULETTE_H
#define ROULETTE_H

#include <string>
#include <vector>
using namespace std;

enum RouletteColor {
    RED,
    BLACK,
    GREEN
};

// struct to represent one pocket on the wheel
struct RoulettePocket {
    int number;
    RouletteColor color;
};

// represents a roulette wheel
class RouletteWheel {
public:
    // constructs wheel
    RouletteWheel();
    // spins for a random pocket and returns that RoulettePocket object
    RoulettePocket spin() const;
    // gets a pocket at an index and returns that object
    RoulettePocket getPocket(int index) const;
    // returns int number of pockets
    int getNumPockets() const { return pockets.size(); }

private:
    // wheel has a vector of each of the defined pockets
    vector<RoulettePocket> pockets;
};

class RouletteGame {
public:
    RouletteGame() = default;
    // manages one round of roulette
    void playRoulette();

private:
    // a wheel holds a vector of pockets for gameplay
    RouletteWheel wheel;
    // functionality for betting process
    void placeBet();
};



#endif //ROULETTE_H
