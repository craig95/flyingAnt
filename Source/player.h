/**
*	@file player.h
*	@class Player
*	@author Craig van Heerden U15029779, Dedre Olwage U15015239
*
*	@brief An abstract class for  creating players of type Unit.
*
*	@section Description
* 	This class provides the functionality of cloning a  player, as well as enable the players  to attack mobs or take damage on themselves.
*
*/

#ifndef PLAYER_H
#define PLAYER_H


#include "unit.h"
#include "UnitImp.h"


class Player: public UnitImp
{
	public:
		Player() {}
	 ~Player(){}

		 /**
		*	This function creates calls another function in it to determine whether  a player or mob can move or not.
		*	@param Four integers, initial x- and y-coordinate, and the x- and y-coordinate the player/mob wants to move to.
		*	@return A bool indicating whether the player/mob can move or not.
		*/
	 bool Move( int,int,int,int) {return false;}//O

		 /**
		*	This function calls another function to set a specific cell in the map
		*	@param Four integers, initial x- and y-coordinate, and the x- and y-coordinate the player/mob wants to move to, and a char to indicate what that cell should be set to.
		*	@return Nothing, the function is void.
		*/
	virtual void setCell(int,int,char){}
	// Abstract Factory Method and Prototype

		/**
		*	This pure virtual function creates a clone of a player of type Unit.//// how to state otherwise?
		*	@return A pointer to a player of type Unit.
		*/
	virtual Unit* clone(){return 0;}



};

#endif
