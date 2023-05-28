#pragma once
#include "SaveFormat.h"

class JsonFormat : public SaveFormat
{
public:
	void save(LinkedList* list, string filename) override {
		ofstream outfile(filename);
		if (!outfile) {
			cout << "Error creating file " << filename << endl;
			return;
		}
		outfile << "{" << endl;
		outfile << " \"bets\": [" << endl;
		Node* current = list->head;
		while (current != nullptr) {
			outfile << "    {" << endl;
			outfile << "        \"id\": " << current->data->getId() << "," << endl;
			outfile << "        \"p1\": " << current->data->getP1() << "," << endl;
			outfile << "        \"x\": " << current->data->getX() << "," << endl;
			outfile << "        \"p2\": " << current->data->getP2() << "," << endl;
			outfile << "        \"teamOne\": \"" << current->data->getT1() << "\"," << endl;
			outfile << "        \"teamTwo\": \"" << current->data->getT2() << "\"," << endl;
			outfile << "        \"sport\": \"" << current->data->getCategory() << "\"," << endl;
			outfile << "        \"date\": \"" << current->data->getDate() << "\"," << endl;
			outfile << "    }";
			current = current->next;
			if (current != nullptr) {
				outfile << ",";
			}
			outfile << endl;
		}
		outfile << "  }" << endl;
		outfile << "}" << endl;
		outfile.close();
	}
};
