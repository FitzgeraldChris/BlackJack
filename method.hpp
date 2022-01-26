#ifndef _method_HPP
#define _method_HPP
#include "DECKS.hpp"

class METHOD
{
	private:
	int card, plays;
	double perc;
	std::vector<int> playerhand;
	std::vector<int> dealerhand;
	int PlayerScore(), DealerScore();
	DECKS& deck;
	void clearhands();
	
	public:
	void printWinPerc();
	void clearwins();
	int wins, totplays;
	
	METHOD (DECKS& d);
	int not12(int plays);
	int hit17(int plays); 
	int dealerplay(int plays);
	int stand(int plays);
	//~METHOD();
	//int DoubleDown(int plays);
};
#endif