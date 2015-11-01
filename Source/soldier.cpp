#include "soldier.h"

Soldier::Soldier()
{
	Unit::setDamage(8);
	Unit::setHealth(100);
	Unit::setDescription('S');
}

Unit* Soldier::clone()
{
	return new Soldier(*this);
}

bool Soldier :: Move (int x, int y, int x2, int y2)
{
	return false;
}

void Soldier :: setCell(int x, int y, char ch)
{
}

void Soldier :: takeDamage(int damage)
{
	if (this->getHealth()-damage > 0)
		this->setHealth(this->getHealth()-damage);
	else{
		this->setHealth(0);
		if (nextInChain != 0)
			nextInChain->takeDamage(damage-this->getHealth());
	}
}
