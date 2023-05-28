#include "BetBase.h"
#include "LinkedList.h"

BetBase::BetBase()
{
	betList = new LinkedList();
	try
	{
		betList->LoadFromFile(betBaseFile);
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}
BetBase::~BetBase()
{
	try
	{
		betList->SaveToFile(betBaseFile);
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}

	betList->clear();
	delete betList;
}

void BetBase::addBet() {
	int id;
	double p1, x, p2;
	string teamOne, teamTwo, sport, date;
	cout << "������� id �����: ";
	cin >> id;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "������� ������ �������: ";
	getline(cin, teamOne);
	cout << "������� ������ �������: ";
	getline(cin, teamTwo);
	cout << "������� �������� ������: ";
	getline(cin, sport);
	cout << "������� ���� �����: ";
	getline(cin, date);
	cout << "������� ����������� �� ������ ������ �������: ";
	cin >> p1;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "������� ����������� �� �����: ";
	cin >> x;
	cout << "������� ����������� �� ������ ������ �������: ";
	cin >> p2;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	Bet* betItem = new Bet(id, p1, x, p2, teamOne, teamTwo, sport, date);
	betList->add(betItem);
}

void BetBase::importBet() {
	string filename;
	cout << "������� ���� � �����: ";
	cin >> filename;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	try {
		betList->LoadFromFile(filename);
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		getchar();
	}
}

void BetBase::showBetList()
{
	this->printResult(betList);
	getchar();
}

void BetBase::printResult(LinkedList* betList)
{
	Node* current = betList->head;
	while (current != nullptr) {
		cout << current->data->getId() << ". " << \
			"������� 1 - " << current->data->getT1() << ", ������� 2 - " << current->data->getT2() << endl << \
			"����� - " << current->data->getCategory() << ", " << \
			current->data->getDate() << endl << \
			"����������� p1 - " << current->data->getP1() << \
			" ����������� x - " << current->data->getX() << \
			" ����������� p2 - " << current->data->getP2() << endl << endl;
		current = current->next;
	}
}

void BetBase::findBetById()
{
	string id;
	cout << "������� id �����: ";
	cin >> id;
	try
	{
		LinkedList* findList = betList->find("id", id);
		if (findList != nullptr)
		{
			printResult(findList);
			getchar();
			getchar();
			delete findList;
		}
		else
		{
			cout << "������ �� �������" << endl;
			getchar();
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void BetBase::findBetByP1()
{
	string p1;
	cout << "������� ����. p1: ";
	cin >> p1;
	try
	{
		LinkedList* findList = betList->find("p1", p1);
		if (findList != nullptr)
		{
			printResult(findList);
			getchar();
			getchar();
			delete findList;
		}
		else
		{
			cout << "������ �� �������" << endl;
			getchar();
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void BetBase::findBetByX()
{
	string x;
	cout << "������� ����. x: ";
	cin >> x;
	try
	{
		LinkedList* findList = betList->find("x", x);
		if (findList != nullptr)
		{
			printResult(findList);
			getchar();
			getchar();
			delete findList;
		}
		else
		{
			cout << "������ �� �������" << endl;
			getchar();
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void BetBase::findBetByP2()
{
	string p2;
	cout << "������� ����. p2: ";
	cin >> p2;
	try
	{
		LinkedList* findList = betList->find("p2", p2);
		if (findList != nullptr)
		{
			printResult(findList);
			getchar();
			getchar();
			delete findList;
		}
		else
		{
			cout << "������ �� �������" << endl;
			getchar();
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void BetBase::findBetBySport()
{
	string sport;
	cout << "������� �������� ������: ";
	cin >> sport;
	try
	{
		LinkedList* findList = betList->find("sport", sport);
		if (findList != nullptr)
		{
			printResult(findList);
			getchar();
			getchar();
			delete findList;
		}
		else
		{
			cout << "������ �� �������" << endl;
			getchar();
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}


void BetBase::removeBetById()
{
	string id;
	cout << "������� id �����: ";
	cin >> id;
	try
	{
		cout << "������� " << betList->remove("id", id) << " �������" << endl;
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void BetBase::removeBetByP1()
{
	string p1;
	cout << "������� ����� �����������: ";
	getline(cin, p1);
	try
	{
		cout << "������� " << betList->remove("p1", p1) << " �������" << endl;
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void BetBase::removeBetByX()
{
	string x;
	cout << "������� ����� �����������: ";
	cin >> x;
	try
	{
		cout << "������� " << betList->remove("x", x) << " �������" << endl;
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void BetBase::removeBetByP2()
{
	string p2;
	cout << "������� ����. p2: ";
	cin >> p2;
	try
	{
		cout << "������� " << betList->remove("p2", p2) << " �������" << endl;
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void BetBase::removeBetBySport()
{
	string sport;
	cout << "������� ���������� ������� � �����: ";
	cin >> sport;
	try
	{
		cout << "������� " << betList->remove("sport", sport) << " �������" << endl;
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void BetBase::sortBetByIdAsc()
{
	betList->sort("id", true);
	this->showBetList();
}

void BetBase::sortBetByIdDesc()
{
	betList->sort("id", false);
	this->showBetList();
}

void BetBase::sortBetByP1Asc()
{
	betList->sort("p1", true);
	this->showBetList();
}

void BetBase::sortBetByP1Desc()
{
	betList->sort("p1", false);
	this->showBetList();
}

void BetBase::sortBetByXAsc()
{
	betList->sort("x", true);
	this->showBetList();
}

void BetBase::sortBetByXDesc()
{
	betList->sort("x", false);
	this->showBetList();
}

void BetBase::sortBetByP2Asc()
{
	betList->sort("p2", true);
	this->showBetList();
}

void BetBase::sortBetByP2Desc()
{
	betList->sort("p2", false);
	this->showBetList();
}

void BetBase::sortBetBySportAsc()
{
	betList->sort("sport", true);
	this->showBetList();
}

void BetBase::sortBetBySportDesc()
{
	betList->sort("sport", false);
	this->showBetList();
}

void BetBase::exportBetListToJson()
{
	SaveFormat* format = new JsonFormat();
	format->save(betList, "bets.json");
	delete format;
}
void BetBase::exportBetListToXML()
{
	SaveFormat* format = new XmlFormat();
	format->save(betList, "bets.xml");
	delete format;
}
void BetBase::exportBetListToCSV()
{
	betList->SaveToFile("bets.csv");
}

void BetBase::run() {
	SubMenu mainMenu("������� ������������ �������", false);
	SubMenu adminMenu("����������������� ��������", true);
	SubMenu findMenu("�����", false);
	SubMenu removeMenu("��������", false);
	SubMenu userMenu("�������� ��������", false);
	SubMenu sortMenu("����������", false);
	SubMenu sortByIdMenu("���������� �� Id", false);
	SubMenu sortByP1Menu("���������� �� p1", false);
	SubMenu sortByXMenu("���������� �� x", false);
	SubMenu sortByP2Menu("���������� �� p2", false);
	SubMenu sortBySportMenu("���������� �� �������� ������", false);
	SubMenu exportMenu("�������������� ������", false);

	MenuItem sortBetByIdAsc("�� �����������", false, [this]() {this->sortBetByIdAsc(); });
	MenuItem sortBetByIdDesc("�� ��������", false, [this]() {this->sortBetByIdDesc(); });
	MenuItem sortBetByP1Asc("�� �����������", false, [this]() {this->sortBetByP1Asc(); });
	MenuItem sortBetByP1Desc("�� ��������", false, [this]() {this->sortBetByP1Desc(); });
	MenuItem sortBetByXAsc("�� �����������", false, [this]() {this->sortBetByXAsc(); });
	MenuItem sortBetByXDesc("�� ��������", false, [this]() {this->sortBetByXDesc(); });
	MenuItem sortBetByP2Asc("�� �����������", false, [this]() {this->sortBetByP2Asc(); });
	MenuItem sortBetByP2Desc("�� ��������", false, [this]() {this->sortBetByP2Desc(); });
	MenuItem sortBetBySportAsc("�� �����������", false, [this]() {this->sortBetBySportAsc(); });
	MenuItem sortBetBySportDesc("�� ��������", false, [this]() {this->sortBetBySportDesc(); });

	MenuItem addBetItem("�������� ����� ����", false, [this]() {this->addBet(); });
	MenuItem importFromCSV("������ �� CSV", false, [this]() {this->importBet(); });
	MenuItem showBetList("���������� ������ ������", false, [this]() {this->showBetList(); });

	MenuItem findBetById("����� ���� �� id", false, [this]() {this->findBetById(); });
	MenuItem findBetByP1("����� ���� �� p1", false, [this]() {this->findBetByP1(); });
	MenuItem findBetByX("����� ���� �� x", false, [this]() {this->findBetByX(); });
	MenuItem findBetByP2("����� ���� �� p2", false, [this]() {this->findBetByP2(); });
	MenuItem findBetBySport("����� ���� �������� ������", false, [this]() {this->findBetBySport(); });
	MenuItem removeBetById("������� ���� �� id", false, [this]() {this->removeBetById(); });
	MenuItem removeBetByP1("������� ���� p1", false, [this]() {this->removeBetByP1(); });
	MenuItem removeBetByX("������� ���� �� x", false, [this]() {this->removeBetByX(); });
	MenuItem removeBetByP2("������� ���� �� p2", false, [this]() {this->removeBetByP2(); });
	MenuItem removeBetBySport("������� ���� �� �������� ������", false, [this]() {this->removeBetBySport(); });

	MenuItem exportBetListToCSV("�������������� � CSV", false, [this]() {this->exportBetListToCSV(); });
	MenuItem exportBetListToJson("�������������� � Json", false, [this]() {this->exportBetListToJson(); });
	MenuItem exportBetListToXML("�������������� � Xml", false, [this]() {this->exportBetListToXML(); });

	exportMenu.add_item(&exportBetListToCSV);
	exportMenu.add_item(&exportBetListToJson);
	exportMenu.add_item(&exportBetListToXML);

	sortByIdMenu.add_item(&sortBetByIdAsc);
	sortByIdMenu.add_item(&sortBetByIdDesc);
	sortByP1Menu.add_item(&sortBetByP1Asc);
	sortByP1Menu.add_item(&sortBetByP1Desc);
	sortByXMenu.add_item(&sortBetByXAsc);
	sortByXMenu.add_item(&sortBetByXDesc);
	sortByP2Menu.add_item(&sortBetByP2Asc);
	sortByP2Menu.add_item(&sortBetByP2Desc);
	sortBySportMenu.add_item(&sortBetBySportAsc);
	sortBySportMenu.add_item(&sortBetBySportDesc);
	sortMenu.add_item(&sortByIdMenu);
	sortMenu.add_item(&sortByP1Menu);
	sortMenu.add_item(&sortByXMenu);
	sortMenu.add_item(&sortByP2Menu);
	sortMenu.add_item(&sortBySportMenu);
	findMenu.add_item(&findBetById);
	findMenu.add_item(&findBetByP1);
	findMenu.add_item(&findBetByX);
	findMenu.add_item(&findBetByP2);
	findMenu.add_item(&findBetBySport);
	removeMenu.add_item(&removeBetById);
	removeMenu.add_item(&removeBetByP1);
	removeMenu.add_item(&removeBetByX);
	removeMenu.add_item(&removeBetByP2);
	removeMenu.add_item(&removeBetBySport);

	adminMenu.add_item(&addBetItem);
	adminMenu.add_item(&importFromCSV);
	adminMenu.add_item(&findMenu);
	adminMenu.add_item(&sortMenu);
	adminMenu.add_item(&exportMenu);
	adminMenu.add_item(&removeMenu);
	adminMenu.add_item(&showBetList);

	userMenu.add_item(&findMenu);
	userMenu.add_item(&sortMenu);
	userMenu.add_item(&exportMenu);
	userMenu.add_item(&showBetList);

	mainMenu.add_item(&adminMenu);
	mainMenu.add_item(&userMenu);

	mainMenu.run();
}