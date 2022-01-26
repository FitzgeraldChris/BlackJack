#ifndef _DECKS_HPP
#define _DECKS_HPP

#include <vector>

class DECKS
{
	private:
	std::vector<int> deck;
	void init();
	
	public:
	int value, numdeck;
	DECKS();
	DECKS(int numdeck);
	int dealcard();
	void NewDeck();
	void printDecks();
	//~DECKS();
	//void ClearDeck();
};
#endif