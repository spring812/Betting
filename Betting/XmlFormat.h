#pragma once
#include "SaveFormat.h"

class XmlFormat : public SaveFormat
{
public:
	void save(LinkedList* list, string filename) override {
		ofstream outfile(filename);
		if (!outfile) {
			cout << "Error creating file " << filename << endl;
			return;
		}
		outfile << "<?xml version=\"1.0\" encoding = \"UTF-8\"?>" << endl;
		outfile << "<bets>" << endl;
		Node* current = list->head;
		while (current != nullptr) {
			outfile << "  <bet>" << endl;
			outfile << "    <id>" << current->data->getId() << "</id>" << endl;
			outfile << "    <p1>" << current->data->getP1() << "</p1>" << endl;
			outfile << "    <x>" << current->data->getX() << "</x>" << endl;
			outfile << "    <p2>" << current->data->getP2() << "</p2>" << endl;
			outfile << "    <teamOne>" << current->data->getT1() << "</teamOne>" << endl;
			outfile << "    <teamTwo>" << current->data->getT2() << "</teamTwo>" << endl;
			outfile << "    <sport>" << current->data->getCategory() << "</sport>" << endl;
			outfile << "    <date>" << current->data->getDate() << "</date>" << endl;
			outfile << "  </bet>";
			current = current->next;
			if (current != nullptr) {
				outfile << ",";
			}
			outfile << endl;
		}
		outfile << "</bets>" << endl;
		outfile.close();
	}
};
