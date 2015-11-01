#include "unit.h"
#include<iostream>
#include<string>
using namespace std;



void Unit::setHealth(int pHealth)
{
	health = pHealth;
}

void Unit::setDamage(int pDamage)
{
	damage = pDamage;
}

int Unit::getHealth()
{
	return health;
}

int Unit::getDamage()
{
	return damage;
}

void Unit::setDescription(char d)
{
	description = d;
}

char Unit :: getDescription()
{
	return description;
}


void Unit :: yourPosition(int x, int y)
{
	initX = x;
	initY = y;
}

bool Unit :: Move (int x, int y, int x2, int y2)
{
	return false;
}

void Unit :: setCell (int x , int y ,int x2 ,int y2, char)
{
}

char Unit :: getCell(int x, int y )
{
	return ' ';
}

char Unit :: testCell(int x, int y)
{
	return ' ';
}

void Unit :: setNextInChain(Unit* next)
{
	nextInChain = next;
}
