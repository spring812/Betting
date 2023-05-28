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
	cout << "Введите id блока: ";
	cin >> id;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Введите первую команду: ";
	getline(cin, teamOne);
	cout << "Введите вторую команду: ";
	getline(cin, teamTwo);
	cout << "Введите название спорта: ";
	getline(cin, sport);
	cout << "Введите дату матча: ";
	getline(cin, date);
	cout << "Введите коэффициент на победу первой команды: ";
	cin >> p1;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Введите коэффициент на ничью: ";
	cin >> x;
	cout << "Введите коэффициент на победу второй команды: ";
	cin >> p2;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	Bet* betItem = new Bet(id, p1, x, p2, teamOne, teamTwo, sport, date);
	betList->add(betItem);
}

void BetBase::importBet() {
	string filename;
	cout << "Введите путь к файлу: ";
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
			"Команда 1 - " << current->data->getT1() << ", Команда 2 - " << current->data->getT2() << endl << \
			"Спорт - " << current->data->getCategory() << ", " << \
			current->data->getDate() << endl << \
			"Коэффициент p1 - " << current->data->getP1() << \
			" Коэффициент x - " << current->data->getX() << \
			" Коэффициент p2 - " << current->data->getP2() << endl << endl;
		current = current->next;
	}
}

void BetBase::findBetById()
{
	string id;
	cout << "Введите id матча: ";
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
			cout << "Ничего не найдено" << endl;
			getchar();
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void BetBase::findBetByP1()
{
	string p1;
	cout << "Введите коэф. p1: ";
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
			cout << "Ничего не найдено" << endl;
			getchar();
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void BetBase::findBetByX()
{
	string x;
	cout << "Введите коэф. x: ";
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
			cout << "Ничего не найдено" << endl;
			getchar();
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void BetBase::findBetByP2()
{
	string p2;
	cout << "Введите коэф. p2: ";
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
			cout << "Ничего не найдено" << endl;
			getchar();
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void BetBase::findBetBySport()
{
	string sport;
	cout << "Введите название спорта: ";
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
			cout << "Ничего не найдено" << endl;
			getchar();
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}


void BetBase::removeBetById()
{
	string id;
	cout << "Введите id матча: ";
	cin >> id;
	try
	{
		cout << "Удалено " << betList->remove("id", id) << " записей" << endl;
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void BetBase::removeBetByP1()
{
	string p1;
	cout << "Введите место направления: ";
	getline(cin, p1);
	try
	{
		cout << "Удалено " << betList->remove("p1", p1) << " записей" << endl;
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void BetBase::removeBetByX()
{
	string x;
	cout << "Введите место отправления: ";
	cin >> x;
	try
	{
		cout << "Удалено " << betList->remove("x", x) << " записей" << endl;
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void BetBase::removeBetByP2()
{
	string p2;
	cout << "Введите коэф. p2: ";
	cin >> p2;
	try
	{
		cout << "Удалено " << betList->remove("p2", p2) << " записей" << endl;
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void BetBase::removeBetBySport()
{
	string sport;
	cout << "Введите количество человек в матче: ";
	cin >> sport;
	try
	{
		cout << "Удалено " << betList->remove("sport", sport) << " записей" << endl;
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
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
	SubMenu mainMenu("Каталог букмекерской конторы", false);
	SubMenu adminMenu("Администрирование каталога", true);
	SubMenu findMenu("Поиск", false);
	SubMenu removeMenu("Удаление", false);
	SubMenu userMenu("Просмотр каталога", false);
	SubMenu sortMenu("Сортировка", false);
	SubMenu sortByIdMenu("Сортировка по Id", false);
	SubMenu sortByP1Menu("Сортировка по p1", false);
	SubMenu sortByXMenu("Сортировка по x", false);
	SubMenu sortByP2Menu("Сортировка по p2", false);
	SubMenu sortBySportMenu("Сортировка по названию спорта", false);
	SubMenu exportMenu("Экспортировать список", false);

	MenuItem sortBetByIdAsc("По возрастанию", false, [this]() {this->sortBetByIdAsc(); });
	MenuItem sortBetByIdDesc("По убыванию", false, [this]() {this->sortBetByIdDesc(); });
	MenuItem sortBetByP1Asc("По возрастанию", false, [this]() {this->sortBetByP1Asc(); });
	MenuItem sortBetByP1Desc("По убыванию", false, [this]() {this->sortBetByP1Desc(); });
	MenuItem sortBetByXAsc("По возрастанию", false, [this]() {this->sortBetByXAsc(); });
	MenuItem sortBetByXDesc("По убыванию", false, [this]() {this->sortBetByXDesc(); });
	MenuItem sortBetByP2Asc("По возрастанию", false, [this]() {this->sortBetByP2Asc(); });
	MenuItem sortBetByP2Desc("По убыванию", false, [this]() {this->sortBetByP2Desc(); });
	MenuItem sortBetBySportAsc("По возрастанию", false, [this]() {this->sortBetBySportAsc(); });
	MenuItem sortBetBySportDesc("По убыванию", false, [this]() {this->sortBetBySportDesc(); });

	MenuItem addBetItem("Добавить новый матч", false, [this]() {this->addBet(); });
	MenuItem importFromCSV("Импорт из CSV", false, [this]() {this->importBet(); });
	MenuItem showBetList("Посмотреть список матчей", false, [this]() {this->showBetList(); });

	MenuItem findBetById("Найти матч по id", false, [this]() {this->findBetById(); });
	MenuItem findBetByP1("Найти матч по p1", false, [this]() {this->findBetByP1(); });
	MenuItem findBetByX("Найти матч по x", false, [this]() {this->findBetByX(); });
	MenuItem findBetByP2("Найти матч по p2", false, [this]() {this->findBetByP2(); });
	MenuItem findBetBySport("Найти матч названию спорта", false, [this]() {this->findBetBySport(); });
	MenuItem removeBetById("Удалить матч по id", false, [this]() {this->removeBetById(); });
	MenuItem removeBetByP1("Удалить матч p1", false, [this]() {this->removeBetByP1(); });
	MenuItem removeBetByX("Удалить матч по x", false, [this]() {this->removeBetByX(); });
	MenuItem removeBetByP2("Удалить матч по p2", false, [this]() {this->removeBetByP2(); });
	MenuItem removeBetBySport("Удалить матч по названию спорта", false, [this]() {this->removeBetBySport(); });

	MenuItem exportBetListToCSV("Экспортировать в CSV", false, [this]() {this->exportBetListToCSV(); });
	MenuItem exportBetListToJson("Экспортировать в Json", false, [this]() {this->exportBetListToJson(); });
	MenuItem exportBetListToXML("Экспортировать в Xml", false, [this]() {this->exportBetListToXML(); });

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