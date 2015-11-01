#include "thief.h"

Thief::Thief()
{
	Unit::setDamage(10);
	Unit::setHealth(60);
	Unit::setDescription('T');
}

Unit* Thief::clone()
{
	return new Thief(*this);
}

bool Thief :: Move (int x, int y, int x2, int y2)
{
	return false;
}

void Thief :: setCell(int x, int y, char ch)
{
}

void Thief :: takeDamage(int damage)
{
	if (this->getHealth()-damage > 0)
		this->setHealth(this->getHealth()-damage);
	else{
		this->setHealth(0);
		if (nextInChain != 0)
			Unit::nextInChain->takeDamage(damage-this->getHealth());
	}
}
