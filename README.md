# M2OEP-epittma1: Casino
## Ted Pittman
## Project Summary
This project is a digital Casino where a user can choose to play from a list of casino games. Some games require further user input to play, others are a single run. This Casino contains Blackjack, Roulette, and Slot Machines.
* Card is an abstract class to be used in casino games involving the use of a standard 52 card deck. This carries rank and suit values.
* Slotmachine has a set of 7 slot symbols, which are randomly ordered on 3 wheels constituting a full machine. 
The user chooses to play, and the three wheels spin and the resulting symbols that were landed on are printed. If all three symbols match, this counts as a win, otherwise as a loss.
* Blackjack has a player and a dealer, and two component classes. A BlackjackCard inherits from Card, the general abstract card structure, and has a correlating Blackjack card value (i.e. King = 10).
A BlackjackHand has a vector that contains BlackjackCards to represent a hand. One BlackjackHand each for the player and dealer is created, a vector of BlackjackCards is created to represent the deck, and then cards are dealt with standard blackjack gameplay following for hit or stand to get 21.
* Roulette has a component class RouletteWheel representing a wheel that holds pockets. That RouletteWheel contains a vector of RoulettePocket struct objects, which each holds an int value and a RouletteColor (an enum for Red, black, green).
A game asks a user to place a bet on color, number, or to spectate. It spins for a random RoulettePocket in the RouletteWheel and checks if the user bet was correct.


## There are no known bugs currently

## Future work
* Generally it would be beneficial to implement a general user token balance, where they are given a starting balance with a defined split of tokens holding dollar value. The balance of a user would last for one Casino session and carry across the different games for betting.
* Each of the existing games can be improved upon or added to. For blackjack I can implement the standard option to split a hand and play separate with two cards of the same value.
Slotmachines could have varying levels of difficulty meaning different number of symbols or number of wheels. I can implement an algorithm to establish a points system based on certain symbol groupings not just total matching.
Roulette could have bets change based on previous spins, add mystery pockets, or a second wheel for multipliers.
* The program would benefit from a GUI, being able to see a roulette wheel spin or have a mock blackjack table to view hands would make this more interactive. Graphical additions would be best if done with another language in tandem to this cpp program.

## Outside code
Below are implementations of concepts not learned in class and their contexts
```
// default constructor
BlackjackGame() = default;
```
https://en.cppreference.com/w/cpp/language/default_constructor
used explicit default constructor based on clion suggestion

`shuffle(deck.begin(), deck.end(), generator);`
https://cplusplus.com/reference/algorithm/shuffle/?
used to shuffle vector using mt random generator

```
// ensure all characters in string are uppercase
transform(inputLine.begin(), inputLine.end(), inputLine.begin(),
[](char c) { return toupper(c); });
```
https://cplusplus.com/reference/algorithm/transform/
used transform with lambda function to iterate through input string ensuring every character is uppercase

`choice = toupper(inputLine[0]);`
https://www.programiz.com/cpp-programming/library-function/cctype/toupper
used toupper on the first char of an input string for input handling


## Self-Grading
I believe I deserve 60 points:

This program uses the M2 concepts well with robust input error handling, and is of scale for an open-ended. The inheritance of the abstract Card class and the component relationships for Blackjack and Roulette demonstrate a clear understanding of class relationship concepts.
There is proper organization and comments accurately describe the workflow of the program. This project should lose points for omitting a testing suite and not utilizing file I/O.  