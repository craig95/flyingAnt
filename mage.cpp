#include "mage.h"

Mage::Mage()
{
	Unit::setDamage(5);
	Unit::setHealth(80);
	Unit::setDescription('M');
}

Unit* Mage::clone()
{
	return new Mage (*this);
}

bool Mage :: Move (int x, int y, int x2, int y2)
{
	return false;
}

void Mage :: setCell(int x, int y, char ch)
{
}

void Mage :: takeDamage(int damage)
{
	if (this->getHealth()-damage > 0)
		this->setHealth(this->getHealth()-damage);
	else{
		this->setHealth(0);
		if (nextInChain != 0)
			nextInChain->takeDamage(damage-this->getHealth());
	}
}
