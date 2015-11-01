#include "ogre.h"

Ogre::Ogre()
{
	Unit::setDamage(5);
	Unit::setHealth(120);
	Unit::setDescription('O');
}

Unit * Ogre::clone()
{
	return new Ogre (*this);
}

bool Ogre :: Move (int x, int y, int x2, int y2)
{
	return false;
}

void Ogre :: setCell(int x, int y, char ch)
{
}

void Ogre :: takeDamage(int damage)
{
	if (this->getHealth()-damage > 0)
		this->setHealth(this->getHealth()-damage);
	else{
		this->setHealth(0);
		cout << WHITE << "You have killed a Ogre! Remaining damage sent to next Ogre!" << endl;
		if (nextInChain != 0)
			nextInChain->takeDamage(damage-this->getHealth());
	}
}
