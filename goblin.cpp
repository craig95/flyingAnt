#include "goblin.h"

Goblin::Goblin()
{
	Unit::setDamage(12);
	Unit::setHealth(50);
	Unit::setDescription('G');
}

Unit* Goblin::clone()
{
	return new Goblin(*this);
}

bool Goblin :: Move (int x, int y, int x2, int y2)
{
	return false;
}

void Goblin :: setCell(int x, int y, char ch)
{
}

void Goblin :: takeDamage(int damage)
{
	if (this->getHealth()-damage > 0)
		this->setHealth(this->getHealth()-damage);
	else{
		this->setHealth(0);
		cout << "You have killed a Goblin! Remaining damage sent to next goblin!" << endl;
		if (nextInChain != 0)
			nextInChain->takeDamage(damage-this->getHealth());
	}
}
