/**
*	@file subject.h
*	@class Subject
*	@author Craig van Heerden U15029779, Dedre Olwage U15015239
*
*	@brief A class serving as the communicator between objects.
*
*	@section Description
* 	This class provides the functionality of attaching or  detaching objects to this Subject, as well as notify all objects attached to this Subject on any changes this Subject might imply, so that the attached objects can respond accordingly.
*/

#ifndef SUBJECT_H
#define SUBJECT_H

#include<iostream>
#include <vector>
#include <time.h>
#include "unit.h"


using namespace std;

class Subject
{
	//Observer and Mediator

	private:
			/**
			*	@brief A vector holding all of the objects that attach themselves to a specific Subject.
			*/
		vector<Unit *> mObservers;//O

	public:

			/**
			* 	This function allows objects to attach themselves to the Subject as observers (via adding the to the 'mObservers' vector).
			*	@param A pointer of type Unit to the object that needs to be attached (added to the 'mObservers' vector).
			*	@return Nothing is returned (function is void).
			*/
		virtual void attach (Unit * observer);//O

			/**
			* 	This function allows objects to detach themselves from the Subject as observers (via removing them from the 'mObservers' vector).
			*	@param A pointer of type Unit to the object that needs to be detached (removed from the 'mObservers' vector).
			*	@return Nothing is returned (function is void).
			*/
		virtual void detach (Unit * observer);//O

			/**
			* 	This function informs all of the objects attached to the Subject  (all the objects in the 'mObservers' vector) about a change the Subject underwent, so they can react accordingly.
			*	@return Nothing is returned (function is void).
			*/
		void notify(Subject*);//O

			/**
			*	This pure virtual function needs to be imlemented to call another function in it to determine whether  a player or mob can move or not.
			*	@param Four integers, initial x- and y-coordinate, and the x- and y-coordinate the player/mob wants to move to.
			*	@return A bool indicating whether the player/mob can move or not.
			*/
		virtual bool Move ( int, int, int , int) =0;

			/**
			*	This pure virtual function needs to be implemented to call another function to set a specific cell in the map
			*	@param Four integers, initial x- and y-coordinate, and the x- and y-coordinate the player/mob wants to move to, and a char to indicate what that cell should be set to.
			*	@return Nothing, the function is void.
			*/
		virtual void setCell(int,int ,int,int,char)=0;

			/**
			*	This pure virtual function creates needs to be implemented to call another function in it to return a certian cell's contents.
			*	@param Two integers, the x- and y-coordinate of the cell which the contents of has to be returned.
			*	@return A char conteaining the contents of a specific cell.
			*/
		virtual char getCell(int,int) = 0;

			/**
			*	This pure virtual function creates needs to be impemented to call another function in it to determine whether if there is a character above,below,left or right from the player/mob.
			*	@param Two integers, initial x- and y-coordinate used to calculate cells around it.
			*	@return A string indicating if there is something above,below, left or right from the player/mob.
			*/
		virtual char testCell(int,int) = 0;

			/**
			*	This pure virtual function creates needs to be implemented to return the length of the map (the total rows in the 2D dynamic array).
			*	@return A integer containing the length of the map.
			*/
		virtual int getXLength() = 0;

			/**
			*	This pure virtual function creates needs to be implemented to return the width of the map (the total columns in the 2D dynamic array).
			*	@return A integer containing the width of the map.
			*/
		virtual int getYLength()= 0;

};

#endif
