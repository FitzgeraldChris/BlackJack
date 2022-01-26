OPTS = -Wall -std=c++14 -g

all: BlackJack

BlackJack: DECKS.o main1.o method.o
	g++ DECKS.o main1.o method.o -o BlackJack

main1.o: main1.cpp DECKS.hpp method.hpp
	g++ $(OPTS) -c main1.cpp

DECKS.o: DECKS.cpp DECKS.hpp
	g++ $(OPTS) -c DECKS.cpp

method.o: method.cpp method.hpp
	g++ $(OPTS) -c method.cpp
	
clean:
	rm *.o IsingMaker