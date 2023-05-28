#include "Bet.h"

bool Bet::isGreaterThen(Bet* t, string field)
{
	if (field == "id")
	{
		return this->getId() > t->getId();
	}
	else if (field == "p1")
	{
		return this->getP1() > t->getP1();
	}
	else if (field == "x")
	{
		return this->getX() > t->getX();
	}
	else if (field == "p2")
	{
		return this->getP2() > t->getP2();
	}
	else if (field == "sport")
	{
		return this->getCategory() > t->getCategory();
	}
	else
	{
		return false;
	}
}

bool Bet::isLessThen(Bet* t, string field)
{
	if (field == "id")
	{
		return this->getId() < t->getId();
	}
	else if (field == "p1")
	{
		return this->getP1() < t->getP1();
	}
	else if (field == "x")
	{
		return this->getX() < t->getX();
	}
	else if (field == "p2")
	{
		return this->getP2() < t->getP2();
	}
	else if (field == "sport")
	{
		return this->getCategory() < t->getCategory();
	}
	else
	{
		return false;
	}
}