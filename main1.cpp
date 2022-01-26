// Blackjack strategy stimulator
// Main file

#include <iostream>
#include "DECKS.hpp"
#include "method.hpp"

int main(int argc, char** argv)
{
	std::cout << "Welcome to the Blackjack Win Percentage Calculator!" << std::endl;
	int numdeck, choice, plays; //numplayer, maxval;
	numdeck = 0;
	plays = 0;
	//std::cout << "How many are playing against dealer" << std::endl;
	//std::cin >> numplayer;

	//Changing rules to see how it changes probabilities
	//std::cout << "What is the max value before bust?" << std::endl;
	//std::cin >> maxval; 



bool readyExit = false;

while(!readyExit)
    {
        std::cout << "What methods to give win probabilities in Blackjack?" << std::endl;
        std::cout << "(1) Always stand over 11" << std::endl;
        std::cout << "(2) Always try to get at least 17." << std::endl;
        std::cout << "(3) Dealer shows 7 or higher, player hit to at least 17." << std::endl;
        std::cout << "(4) Never hit." << std::endl;
		//std::cout << "(6) Change number of deck and plays" << std::endl;
		//std::cout << "(5) Double Downs used when hand score equals 9, 10 or 11." << std::endl;
        std::cout << "(5) Exit Program." << std::endl;
        std::cin >> choice;
		//if (numdeck && plays == 0)
		//{
		// Finding the number of decks to use.2
		std::cout << "How many decks you want to use?" << std::endl;
		//std::cout << "Or input negative values for infinite decks" << std::endl;
		while(!(std::cin >> numdeck))
		{
			std::cout << "Error: enter an integer: ";
			std::cin.clear();
			std::cin.ignore(1000000, '\n');
		}
			// How many iterations for each method.
		std::cout << "How many plays for this method?" << std::endl;
		while(!(std::cin >> plays))
		{
			std::cout << "Come on... enter an integer: ";
			std::cin.clear();
			std::cin.ignore(1000000, '\n');
		}
		DECKS deck(numdeck);
		METHOD MD(deck);
		//}
		
		
        switch(choice)
        {
            case 1:
                MD.not12(plays);
				MD.printWinPerc();
				MD.clearwins();
                break;
                
            case 2:
                MD.hit17(plays);
				MD.printWinPerc();
				MD.clearwins();
                break;
                
            case 3:
                MD.dealerplay(plays);
				MD.printWinPerc();
				MD.clearwins();
                break;
                
            case 4:
                MD.stand(plays);
				MD.printWinPerc();
                MD.clearwins();
				break;
			
			/* case 5:
                MD.DoubleDown(plays);
				MD.printWinPerc();
				MD.clearwins();
                break; */
			
			/* case 6:
				std::cout << "How many decks you want to use?" << std::endl;
				//std::cout << "Or input negative values for infinite decks" << std::endl;
				while(!(std::cin >> numdeck))
				{
					std::cout << "Error: enter an integer: ";
					std::cin.clear();
					std::cin.ignore(1000000, '\n');
				}
				// How many iterations for each method.
				std::cout << "How many plays for this method?" << std::endl;
				while(!(std::cin >> plays))
				{
					std::cout << "Come on... enter an integer: ";
					std::cin.clear();
					std::cin.ignore(1000000, '\n');
				}
				deck = DECKS(numdeck);
				MD = METHOD(deck);
				break; */
			
            case 5:
                std::cout << "Goodbye!" << std::endl;
                readyExit = true;
                break;
                
            default:
                std::cout << "Invalid entry... Goodbye!" << std::endl;
                readyExit = true;
                break;
        }
    }
    
    return EXIT_SUCCESS;
}