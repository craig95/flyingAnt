/**
*	@file UnitImp.h
*	@class UnitImp
*	@author Craig van Heerden U15029779, Dedre Olwage U15015239
*
*	@brief The implementation of unit. The implementation participant of bridge.
*/

#ifndef UNITIMP_H
#define UNITIMP_H

#include "unit.h"

class UnitImp
{
public:
  UnitImp(){}
  virtual ~UnitImp(){}

   /**
   *	This function gets the health of the current Unit.
   *	@return The value the 'health' attribute holds.
   */
 int getHealth();

   /**
   *	This function gets the damage of the current Unit.
   *	@return The value the 'damage' attribute holds.
   */
 int getDamage();

   /**
   *	This function returns the description of the current Unit.
   *	@return A string containing the value of the 'description' attribute.
   */
 char getDescription();

   /**
   *	This function creates calls another function in it to determine whether  a player or mob can move or not.
   *	@param Four integers, initial x- and y-coordinate, and the x- and y-coordinate the player/mob wants to move to.
   *	@return A bool indicating whether the player/mob can move or not.
   */
 virtual bool Move( int,int,int,int) ;//O

   /**
   *	This function calls another function to set a specific cell in the map
   *	@param Four integers, initial x- and y-coordinate, and the x- and y-coordinate the player/mob wants to move to, and a char to indicate what that cell should be set to.
   *	@return Nothing, the function is void.
   */
 virtual void setCell(int,int,int,int,char);

   /**
   *	This function creates calls another function in it to return a certian cell's contents.
   *	@param Two integers, the x- and y-coordinate of the cell which the contents of has to be returned.
   *	@return A char conteaining the contents of a specific cell.
   */
 virtual char getCell(int,int);

   /**
   *	This function creates calls another function in it to determine whether if there is a character above,below,left or right from the player/mob.
   *	@param Two integers, initial x- and y-coordinate used to calculate cells around it.
   *	@return A string indicating if there is something above,below, left or right from the player/mob.
   */
 virtual char testCell(int,int);

   /**
   *	This function sets a player/mobs  x- and y-coordinate (indicating their current position in the map/ 2D dynamic array), in other words it sets the values of the attributes initX and initY.
   *	@param Two integers, which the attributes 'initX 'and 'initY 'should be set to.
   */
 void yourPosition(int x, int y);//M

   /**
   *	This function returns the value of the attribute 'initY'.
   *	@return An integer holding the value of the attribute  'initY'.
   */
 int getY() {return initY;}

   /**
   *	This function returns the value of the attribute 'initX'.
   *	@return An integer holding the value of the attribute  'initX'.
   */
 int getX() {return initX;}

 /**
   *	This function sets the value of the attribute 'health'.
   *	@param An integer indicating what the value of the attribute 'health' should be set to.
   * 	@return Nothing is returned (function is void).
   */
 void setHealth(int pHealth);

private:
		//AbstractFactory and Prototype

		/**
			@brief The integer holding the value of what a specific Units' damage should be.
		*/
	int damage;

		/**
			@brief The integer holding the value of what a specific Units' health should be.
		*/
	int health;

		/**
			@brief The integer holding the value of what a specific Units' description should be.
		*/
	char description;

		/**
			@brief The integer holding the value of  a specific Units' position at the x-coordinate.
		*/
	int initX; ///Your army x position

		/**
			@brief The integer holding the value of  a specific Units' position at the y-coordinate.
		*/
	int initY; ///Your army y position

};

#endif
