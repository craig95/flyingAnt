/**
*	@file thief.h
*	@class Thief
*	@author Craig van Heerden U15029779, Dedre Olwage U15015239
*
*	@brief A class for  creating clones of a specific type of player (thief player).
*
*	@section Description
* 	This class provides the functionality of creating clones of the player type Thief, as well as give the player the ability to attack another mob or take damage itself.
*
*/

#ifndef THIEF_H
#define THIEF_H

#include "player.h"
#include "unit.h"

class Thief: public Unit
{
public:	//AbstractFactory and Prototype

		/**
		*	A constructor for setting the values from inherited attributes(from class Unit).
		*/
	Thief();

		/**
		*	This function creates a clone of a Thied player of type Unit.
		*	@return A pointer to a Thief player of type Unit.
		*/
	Unit* clone();

		/**
		*	This function lets this Thief player of type Unit take damage to itself.
		*	@param An integer indicating how much damage should be taken by the Thief player (how much the attribute Health will be decremented by).
		*	@return Nothing is returned (function is void).
		*/
	virtual void takeDamage(int);

		/**
		*	This function creates calls another function in it to determine whether  a player or mob can move or not.
		*	@param Four integers, initial x- and y-coordinate, and the x- and y-coordinate the player/mob wants to move to.
		*	@return A bool indicating whether the player/mob can move or not.
		*/
	bool Move( int,int,int,int) ;//O

		/**
		*	This function calls another function to set a specific cell in the map
		*	@param Four integers, initial x- and y-coordinate, and the x- and y-coordinate the player/mob wants to move to, and a char to indicate what that cell should be set to.
		*	@return Nothing, the function is void.
		*/
	void setCell(int,int,char);

};

#endif
