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
