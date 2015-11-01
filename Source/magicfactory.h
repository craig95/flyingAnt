/**
*	@file magicfactory.h
*	@class MagicFactory
*	@author Craig van Heerden U15029779, Dedre Olwage U15015239
*	
*	@brief A class for  creating Magic units (players or mobs)
*
*	@section Description
* 	This class provides the functionality of creating a Magic player of type Unit and a Magic mob of type Unit.
*
*/

#ifndef MAGICFACTORY_H
#define MAGICFACTORY_H

#include "unitfactory.h"

class MagicFactory: public UnitFactory
{
public:

	//AbstractFactory and Prototype

		/**
		*	This function creates a Magic player of type Unit.
		*	@return A pointer to a Magic player of type Unit.
		*/
	Unit* createPlayer();

		/**
		*	This function creates a Magic mob of type Unit.
		*	@return A pointer to a Magic mob of type Unit.
		*/
	Unit* createMob();
};

#endif