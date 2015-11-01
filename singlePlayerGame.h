#ifndef SINGLEPLAYERGAME_H
#define SINGLEPLAYERGAME_H

#include "magicfactory.h"
#include "bludgeoningfactory.h"
#include "piercingfactory.h"
#include "Map.h"
#include "adapter.h"

#include <time.h>
#include <vector>
#include <cctype>
#include <cstring>
#include <string>

#define RED "\033[31m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\035[35m"
#define CYAN "\036[36m"
#define WHITE "\033[37m"

class SinglePlayerGame
{
public:

	/**
	*	This function returns determines which Unit (player or mob) should take damage and how each of them should deal damage.
	*	@param An reference to either the player/mobs health value, and two chars containing the player/mobs descriptions.
	*	@return An integer indicating how much damage should be taken by the player/mob itself.
	*/
	int amountDamage(int &,char ch1, char ch2);
	void setupSinglePlayerGame();
	void startGame();
	Unit* findUnitAtCords(int x, int y);

private:
	Unit *army;
	Unit *enemy;
	Unit *adapterA;
	Map *map;
	vector<Unit*> persons;
	vector<Unit*> monsters;
	int numberOfEnemys;

};

#endif
