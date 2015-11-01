/**
*	@file unitfactory.h
*	@class UnitFactory
*	@author Craig van Heerden U15029779, Dedre Olwage U15015239
*	
*	@brief An abstract class for  creating players/mobs of type Unit.
*
*	@section Description
* 	This class provides the functionality of creating players/mobs of type Unit .
*/

#ifndef UNITFACTORY_H
#define UNITFACTORY_H

#include "unit.h"

class UnitFactory
{
public:
	//AbstractFactory and Prototype

		/**
		*	This function creates a  player of type Unit.
		*	@return A pointer to a  player of type Unit.
		*/
	virtual Unit* createPlayer()=0;

		/**
		*	This function creates a  mob of type Unit.
		*	@return A pointer to a  mob of type Unit.
		*/
	virtual Unit* createMob()=0;

	
};


#endif