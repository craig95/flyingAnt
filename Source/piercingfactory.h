/**
*	@file piercingfactory.h
*	@class PiercingFactory
*	@author Craig van Heerden U15029779, Dedre Olwage U15015239
*	
*	@brief A class for  creating Piercing units (players or mobs)
*
*	@section Description
* 	This class provides the functionality of creating a Piercing player of type Unit and a Piercing mob of type Unit.
*
*/

#ifndef PIERCINGFACTORY_H
#define PIERCINGFACTORY_H

#include "unitfactory.h"

class PiercingFactory: public UnitFactory
{
public:

	//AbstractFactory and Prototype
	
		/**
		*	This function creates a Piercing player of type Unit.
		*	@return A pointer to a Piercing player of type Unit.
		*/
	Unit* createPlayer();

		/**
		*	This function creates a Piercing mob of type Unit.
		*	@return A pointer to a Piercing mob of type Unit.
		*/
	Unit* createMob();
};

#endif