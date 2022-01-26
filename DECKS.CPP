// Deck Object
#include "DECKS.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

DECKS::DECKS()   // Default construtor to make number of deck equals 1
{
	std::cout << "Using 1 deck since you didn't input it correctly!" << std::endl;
	this -> numdeck = 1;
	init();
	
}

DECKS::DECKS(int numdeck)  // Constructor to build as many decks as wanted
{
	this -> numdeck = numdeck;
	init();
}
void DECKS::init()       // initializing building the deck of 52 cards times the number of deck and assign the value of each card to a vector
{
	//std::cout << "Setting up deck" << std::endl;
	deck.resize(52*numdeck);
    for (int i=0; i < numdeck * 52; i++) // with use numdeck from main
    {
        deck.at(i) = i % 10 + 1;
    }
	std::shuffle(deck.begin(), deck.end(), std::random_device());   // Shuffle the vector
}
void DECKS::NewDeck()  // make a new deck after clearing the deck object to reuse
{
	deck.clear();
    init();
}

/* void DECKS::ClearDeck()  // 
{
	deck.clear();
}
 */
int DECKS::dealcard()    // function to deal card when called from the vector deck
{
	if (deck.size() < unsigned (1.0/6.0*numdeck*52))
		NewDeck();
	value = deck.front();
	deck.erase(deck.begin());
	return this -> value;
}

void DECKS::printDecks()   // Function to print the current deck
{
	std::cout << "This is your current deck" << std::endl;
	for (int i=0; i < (unsigned) deck.size() ; i++)
		std::cout << deck.at(i) << std::endl;
}
