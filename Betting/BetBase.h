#pragma once
#include "SubMenu.h"
#include "MenuItem.h"
#include "LinkedList.h"
#include "Bet.h"
#include "SaveFormat.h"
#include "JsonFormat.h"
#include "XmlFormat.h"
#include <iostream>
#include <sstream>
#include <locale>
#include <regex>
#include <limits>
#include <codecvt>

class BetBase
{
public:
	BetBase();
	void run();
	~BetBase();
private:
	LinkedList* betList;
	void addBet();

	void findBetById();
	void findBetByP1();
	void findBetByX();
	void findBetByP2();
	void findBetBySport();
	void removeBetById();
	void removeBetByP1();
	void removeBetByX();
	void removeBetByP2();
	void removeBetBySport();
	void sortBetByIdAsc();
	void sortBetByIdDesc();
	void sortBetByP1Asc();
	void sortBetByP1Desc();
	void sortBetByXAsc();
	void sortBetByXDesc();
	void sortBetByP2Asc();
	void sortBetByP2Desc();
	void sortBetBySportAsc();
	void sortBetBySportDesc();

	void exportBetListToJson();
	void exportBetListToXML();
	void exportBetListToCSV();

	void importBet();
	void printResult(LinkedList* betList);
	void showBetList();
	const string betBaseFile = "bets.csv";
};