//Methods Object to configure how the game is played in Blackjack

#include "method.hpp"
#include <vector>
#include <iostream>

METHOD::METHOD(DECKS& d) : deck(d)  // Constructor for Building player's and dealer's hand.
{
	for (int i = 0; i < 2; i++)
	{
		playerhand.push_back(deck.dealcard());
		dealerhand.push_back(deck.dealcard());
	}
	//std::cout << "Player Cards " << playerhand.at(0) << " " << playerhand.at(1) << std::endl;
}

int METHOD::PlayerScore() // Function to add the score of the Player
{
	int sum = 0;
	for (int i = 0; i < playerhand.size(); i++)
	{
		if (playerhand.at(i) == 1 && (sum + 11 <= 21))
			playerhand.at(i) = 11;
		sum += playerhand.at(i);
	}
	return sum;
}

int METHOD::DealerScore()   // Function to add the score of the Dealer
{
	int sum = 0;
	for (int i = 0; i < dealerhand.size(); i++)
	{
		if (dealerhand.at(i) == 1 && (sum + 11 <= 21))
			dealerhand.at(i) = 11;
		sum += dealerhand.at(i);
	}
	return sum;
}

int METHOD::not12(int plays)   // One method where the player never hit over 11.
{
	wins = 0;
	totplays = plays;
	for (int i = 0; i < plays; i++)
	{
		if (!((DealerScore() == 21) && (PlayerScore() < 21)))
		{
		while(PlayerScore() < 12)
		{	
			playerhand.push_back(deck.dealcard());
			PlayerScore();
		}
		while(DealerScore() < 17)
		{
			dealerhand.push_back(deck.dealcard());
			DealerScore();
		}
		if (DealerScore() > 21)
			wins += 1;
		else if (PlayerScore() > DealerScore() && (PlayerScore() <= 21))
			wins += 1;
		}
		clearhands();
	}
	return wins;
}

int METHOD::hit17(int plays)        // Always try to hit up to 17
{
	wins = 0;
	totplays = plays;
	for (int i = 0; i < plays; i++)
	{
		if (!(DealerScore() == 21 && (PlayerScore() < 21)))
		{
		while(PlayerScore() < 17)
		{	
			playerhand.push_back(deck.dealcard());
			PlayerScore();
		}
		while(DealerScore() < 17)
		{
			dealerhand.push_back(deck.dealcard());
			DealerScore();
		}
		if (DealerScore() > 21)
			wins += 1;
		else if ((PlayerScore() > DealerScore()) && (PlayerScore() <= 21))
			wins += 1;
		}
		clearhands();
	}
	return wins;
}

// other methods
int METHOD::dealerplay(int plays)       // Always try to hit to 17 when dealer shows 7 or higher
{
	wins = 0;
	totplays = plays;
	for (int i = 0; i < plays; i++)
	{
		if (!((DealerScore() == 21) && (PlayerScore() < 21)))
		{
		while(PlayerScore() < 12 || (dealerhand.back() >= 7 && (PlayerScore() < 17)))
		{	
			playerhand.push_back(deck.dealcard());
			PlayerScore();
		}
		while(DealerScore() < 17)
		{
			dealerhand.push_back(deck.dealcard());
			DealerScore();
		}
		if (DealerScore() > 21)
			wins += 1;
		else if (PlayerScore() > DealerScore() && (PlayerScore() <= 21))
			wins += 1;
		}
		clearhands();
	}
	return wins;
}

int METHOD::stand(int plays)   // Always stand no matter what
{
	wins = 0;
	totplays = plays;
	for (int i = 0; i < plays; i++)
	{
		if (!((DealerScore() == 21) && (PlayerScore() < 21)))
		{
		while(DealerScore() < 17)
		{
			dealerhand.push_back(deck.dealcard());
			DealerScore();
		}
		if (DealerScore() > 21)
			wins += 1;
		else if (PlayerScore() > DealerScore() && (PlayerScore() <= 21))
			wins += 1;
		}
		clearhands();
	}
	return wins;
	
}

/* int METHOD::DoubleDown(int plays)     // DoubleDown when the hard count is 9,10, or 11 drawing once to player hand
{
	wins = 0;
	totplays = plays;
	for (int i = 0; i < plays; i++)
	{
		if (!(DealerScore() == 21 && PlayerScore() < 21))
		{
			std::cout << "playerscore " << PlayerScore() << std::endl;
			if (PlayerScore() == 9 || PlayerScore() == 10 || PlayerScore() == 11)
			{
				playerhand.push_back(deck.dealcard());
				PlayerScore();
				std::cout << "DoubleDown" << std::endl;
			}
			while(PlayerScore() < 12)
			{	
				playerhand.push_back(deck.dealcard());
				PlayerScore();
				std::cout << "here" << std::endl;
			}
			while(DealerScore() < 17)
			{
				dealerhand.push_back(deck.dealcard());
				DealerScore();
			}
			if (DealerScore() > 21)
			{
				wins += 1;
			std::cout << DealerScore() << std::endl;
			}
			else if (PlayerScore() > (DealerScore() && (PlayerScore() <= 21)))
			{
				wins += 1;
				std::cout << DealerScore() << std::endl;
			}
		}
		clearhands();
	}
	return wins;
	
} */

void METHOD::clearhands()  // Function to clear the players and dealers hand for next play
{
	playerhand.clear();
	dealerhand.clear();
	//METHOD();
}

void METHOD::clearwins()  // Function to clear wins for next set of methods in main.
{
	wins = 0;
}

void METHOD::printWinPerc()   // Prints out to screen the total wins and plays as well as the percentage
{
	perc = wins*1.0/(1.0*totplays);
	std::cout << "You have won " << wins << " out of " << totplays << " plays!" << std::endl;
	std::cout << "The win percentage for this type of method is " << perc << std::endl;
}