#pragma once
#include <string>

using namespace std;

class Bet
{
public:
	Bet(int Id, double P1, double X, double P2, string TeamOne, string TeamTwo, string Sport, string Date) \
		: id(Id), p1(P1), x(X), p2(P2), teamOne(TeamOne), teamTwo(TeamTwo), sport(Sport), date(Date) {};
	int getId() const { return id; }
	double getP1() const { return p1; }
	double getX() const { return x; }
	double getP2() const { return p2; }
	string getT1() const { return teamOne; }
	string getT2() const { return teamTwo; }
	string getCategory() const { return sport; }
	string getDate() const { return date; };
	bool isGreaterThen(Bet* b, string field);
	bool isLessThen(Bet* b, string field);
private:
	int id;
	double p1;
	double x;
	double p2;
	string teamOne;
	string teamTwo;
	string sport;
	string date;
};
