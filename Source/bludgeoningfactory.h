/**
*	@file bludgeoningfactory.h
*	@class BludgeoningFactory
*	@author Craig van Heerden U15029779, Dedre Olwage U15015239
*	
*	@brief A class for  creating Bludgeoning units (players or mobs).
*
*	@section Description
* 	This class provides the functionality of creating a Bludgeoning player of type Unit and a Bludgeoning mob of type Unit.
*
*/

#ifndef BLUDGEONINGFACTORY_H
#define BLUDGEONINGFACTORY_H

#include "unitfactory.h"

class BludgeoningFactory: public UnitFactory
{
public:

	//AbstractFactory and Prototype

		/**
		*	This function creates a Bludgeoning player of type Unit.
		*	@return A pointer to a Bludgeoning player of type Unit.
		*/
	Unit* createPlayer();

		/**
		*	This function creates a Bludgeoning mob of type Unit.
		*	@return A pointer to a Bludgeoning mob of type Unit.
		*/
	Unit* createMob();
};

#endif