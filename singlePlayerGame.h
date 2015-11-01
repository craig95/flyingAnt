/**
*	@file singlePlyerGame.h
*	@class Player
*	@author Craig van Heerden U15029779, Dedre Olwage U15015239
*
*	@brief A class to easily setup and start a single player game.
*
*	@section Description
* 	This class creates all the units. It also loads the map and handels the game loop.
*
*/

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
#define MAGENTA "\035[31m"
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
	/**
	*	This function is used to set up the game.
	*	@return Nothing is returned (function is void).
	*/
	void setupSinglePlayerGame();
	/**
	*	This function is used to start the game and run the game loop
	*	@return Nothing is returned (function is void).
	*/
	void startGame();

private:
	/**
	*	This function is used to start the game and run the game loop.
	*	@param Two integers that are the coordinates of a cell.
	*	@return The unit in the cell at the coordinates provided.
	*/
	Unit* findUnitAtCords(int x, int y);

	/**
		@brief A temorary pointer to store a player unit.
	*/
	Unit *army;

	/**
		@brief A temorary pointer to store a enemy unit.
	*/
	Unit *enemy;

	/**
		@brief A temorary variable to store a enemy unit.
	*/
	Unit *adapterA;

	/**
		@brief A pointer pointing to a map object..
	*/
	Map *map;

	/**
		@brief A vector storing player units.
	*/
	vector<Unit*> persons;

	/**
		@brief A vector storing monster units.
	*/
	vector<Unit*> monsters;

	/**
		@brief The number of enemys that are generated randomly.
	*/
	int numberOfEnemys;

};

#endif
