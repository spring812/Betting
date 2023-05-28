#include "LinkedList.h"

void LinkedList::clear()
{
	Node* current = head;
	while (current != nullptr)
	{
		Node* temp = current;
		current = current->next;
		delete temp;
	}
	head = nullptr;
}

void LinkedList::add(Bet* p) {
	Node* new_node = new Node(p);
	if (head == nullptr) {
		head = new_node;
		return;
	}
	Node* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}
	current->next = new_node;
}

void LinkedList::LoadFromFile(string filename) {
	ifstream infile(filename);
	if (!infile) {
		throw runtime_error("Файл с данными не найден");
	}
	clear();
	string line;
	while (getline(infile, line)) {
		stringstream ss(line);
		string id, p1, x, p2, teamOne, teamTwo, sport, date;
		getline(ss, id, ';');
		getline(ss, p1, ';');
		getline(ss, x, ';');
		getline(ss, p2, ';');
		getline(ss, teamOne, ';');
		getline(ss, teamTwo, ';');
		getline(ss, sport, ';');
		getline(ss, date);
		int Id = stoi(id);
		double p11 = stoi(p1);
		double xx = stoi(x);
		double p22 = stoi(p2);
		Bet* product = new Bet(Id, p11, xx, p22, teamOne, teamTwo, sport, date);
		add(product);
	}
	infile.close();
}

void LinkedList::SaveToFile(string filename) {
	ofstream outfile(filename);
	if (!outfile) {
		throw runtime_error("Ошибка создания файла");
	}
	Node* current = head;

	while (current != nullptr) {
		outfile << current->data->getId() << ";"
			<< current->data->getP1() << ";"
			<< current->data->getX() << ";"
			<< current->data->getP2() << ";"
			<< current->data->getT1() << ";"
			<< current->data->getT2() << ";"
			<< current->data->getCategory() << ";"
			<< current->data->getDate() << endl;
		current = current->next;
	}
	outfile.close();
}

LinkedList* LinkedList::find(string field, string value) {
	LinkedList* result = new LinkedList();
	Node* current = head;
	while (current != nullptr)
	{
		if (field == "id" && current->data->getId() == stoi(value))
		{
			result->add(current->data);
		}
		else if (field == "p1" && current->data->getP1() == stod(value))
		{
			result->add(current->data);
		}
		else if (field == "x" && current->data->getX() == stod(value))
		{
			result->add(current->data);
		}
		else if (field == "p2" && current->data->getP2() == stod(value))
		{
			result->add(current->data);
		}
		else if (field == "sport" && current->data->getCategory() == value)
		{
			result->add(current->data);
		}
		current = current->next;
	}
	if (result->isEmpty())
	{
		delete result;
		return nullptr;
	}
	return result;
}

int LinkedList::remove(string field, string value)
{
	int counter = 0;
	Node* to_delete = nullptr;
	if (field == "id")
	{
		while ((to_delete = findById(stoi(value))) != nullptr)
		{
			removeNode(to_delete);
			counter++;
		}
		return counter;
	}
	else if (field == "p1")
	{
		while ((to_delete = findByP1(stod(value))) != nullptr)
		{
			removeNode(to_delete);
			counter++;
		}
		return counter;
	}
	else if (field == "x")
	{
		while ((to_delete = findByX(stod(value))) != nullptr)
		{
			removeNode(to_delete);
			counter++;
		}
		return counter;
	}
	else if (field == "p2")
	{
		while ((to_delete = findByP2(stod(value))) != nullptr)
		{
			removeNode(to_delete);
			counter++;
		}
		return counter;
	}
	else if (field == "sport")
	{
		while ((to_delete = findByCategory(value)) != nullptr)
		{
			removeNode(to_delete);
			counter++;
		}
		return counter;
	}
	else {
		cout << "Неверное поле: " << field << endl;
		return counter;
	}
}

void LinkedList::removeNode(Node* to_delete)
{
	if (head == to_delete)
	{
		head = head->next;
		delete to_delete;
		return;
	}
	Node* current = head;
	while (current->next != nullptr)
	{
		if (current->next == to_delete)
		{
			current->next = current->next->next;
			delete to_delete;
			return;
		}
		current = current->next;
	}
}

Node* LinkedList::findById(int id)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data->getId() == id)
			return current;
		current = current->next;
	}
	return nullptr;
}

Node* LinkedList::findByP1(double p1)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data->getP1() == p1)
			return current;
		current = current->next;
	}
	return nullptr;
}

Node* LinkedList::findByX(double x)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data->getX() == x)
			return current;
		current = current->next;
	}
	return nullptr;
}

Node* LinkedList::findByP2(double p2)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data->getP2() == p2)
			return current;
		current = current->next;
	}
	return nullptr;
}

Node* LinkedList::findByCategory(string sport)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data->getCategory() == sport)
			return current;
		current = current->next;
	}
	return nullptr;
}

int LinkedList::getSize() const
{
	Node* current = head;
	int result = 0;
	while (current != nullptr)
	{
		++result;
		current = current->next;
	}
	return result;
}

void LinkedList::sort(string field, bool ascending)
{
	int size = getSize();
	for (int i = 0; i < size - 1; ++i)
	{
		Node* current = head;
		for (int j = 0; j < size - 1 - i; ++j)
		{
			Node* next = current->next;
			if ((ascending && current->data->isGreaterThen(next->data, field)) || \
				(!ascending && current->data->isLessThen(next->data, field)))
			{
				Bet* temp = current->data;
				current->data = next->data;
				next->data = temp;
			}
			current = next;
		}
	}
}
