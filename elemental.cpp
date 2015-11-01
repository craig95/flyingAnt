#include "elemental.h"

Elemental::Elemental()
{
	Unit::setDamage(4);
	Unit::setHealth(85);
	Unit::setDescription('E');
}

Unit* Elemental::clone()
{
	return new Elemental (*this);

}

bool Elemental :: Move (int x, int y, int x2, int y2)
{
	return false;
}

void Elemental :: setCell(int x, int y, char ch)
{
}

void Elemental :: takeDamage(int damage)
{
	if (this->getHealth()-damage > 0)
		this->setHealth(this->getHealth()-damage);
	else{
		this->setHealth(0);
		cout << "You have killed a Elemental! Remaining damage sent to next elemental!" << endl;
		if (nextInChain != 0)
			nextInChain->takeDamage(damage-this->getHealth());
	}
}
