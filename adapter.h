/**
*	@file adapter.h
*	@class Adapter
*	@author Craig van Heerden U15029779, Dedre Olwage U15015239
*
*	@brief To convert the interface of class Map into a compatible interface for class Unit to work with.
*
*	@section Description
* 	This class provides the functionality of testing if a Unit object can move on the map, it gets a certain cell from the map, and it tests a cell if it contains a certain character.
*
*/

#ifndef ADAPTER_H
#define ADAPTER_H

#include "unit.h"
#include "subject.h"
class Adapter : public Unit
{
private:
		/**
		@brief The unit(Target)
		*/
	Unit * A;
		/**
		@brief The Map(Adaptee)
		*/
	Subject * T;

	public:
	 Unit * clone() {return 0;}

		 /**
		*	This constructor assignd values to the attributes 'A' and 'T'
		*	@param The two values that will be used to set the attributes 'A' and 'T'
		*/
	Adapter(Subject * TT, Unit *army) : Unit(){ T = TT;
						           A = army; }


		/**
		*	This function calls another function in it to determine whether  a player or mob can move or not.
		*	@param Four integers, initial x- and y-coordinate, and the x- and y-coordinate the player/mob wants to move to.
		*	@return A bool indicating whether the player/mob can move or not.
		*/
	bool Move(int x, int y, int x2, int y2)
	{
		return T->Move(x,y,x2,y2);
	}

		/**
		*	This function calls another function to set a specific cell in the map
		*	@param Four integers, initial x- and y-coordinate, and the x- and y-coordinate the player/mob wants to move to, and a char to indicate what that cell should be set to.
		*	@return Nothing, the function is void.
		*/
	void setCell(int x, int y,int x2 , int y2, char ch)
	{
		T->setCell(x,y,x2,y2,ch);

		//T->notify(T->getXLength(),T->getYLength());
	}

		/**
		*	This function creates calls another function in it to return a certian cell's contents.
		*	@param Two integers, the x- and y-coordinate of the cell which the contents of has to be returned.
		*	@return A char conteaining the contents of a specific cell.
		*/
	char getCell (int x, int y)
	{
		return T-> getCell(x,y);
	}

		/**
		*	This function creates calls another function in it to determine whether if there is a character above,below,left or right from the player/mob.
		*	@param Two integers, initial x- and y-coordinate used to calculate cells around it.
		*	@return A string indicating if there is something above,below, left or right from the player/mob.
		*/
	char testCell(int x,int y)
	{
		return T->testCell(x,y);
	}

	/**
	*	This function lets a player/mob of type Unit take damage to itself.
	*	@param An integer indicating how much damage should be taken by the  player /mob (how much the attribute Health will be decremented by).
	*	@return Nothing is returned (function is void).
	*/
void takeDamage(int damage){};

};

#endif
