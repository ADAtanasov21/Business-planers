#include "../Header Files/transactions.h"
#include <string>
#include <cstdlib>

TRAN* createNode(double value) {
	TRAN* newNode = new TRAN;
	newNode->value = value;
	newNode->next = nullptr;
	return newNode;
}

// Insert a new node with the given value at the end of the linked list
void insertNode(TRAN*& head, double value) {
	TRAN* newNode = createNode(value);

	if (head == nullptr) {
		head = newNode;
	}
	else {
		TRAN* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

// Display the elements of the linked list
void displayList(TRAN* head) {
	TRAN* temp = head;
	while (temp != nullptr) {
		cout << "Transaction Type: " << temp->type << ", Value: " << temp->value << endl;
		temp = temp->next;
	}
}


// Delete the entire linked list
void deleteList(TRAN*& head) {
	while (head != nullptr) {
		TRAN* temp = head;
		head = head->next;
		delete temp;
	}
}











void assets(TRAN* btc, TRAN* eth, TRAN* rights, TRAN* stocks, bool makeATransaction, string answer, string typeOfTran)
{
	double btcAdd = 0;
	double ethAdd = 0;
	double rightsAdd = 0;
	double stocksAdd = 0;
	cout << "Do you want to make a transaction? It could be outgoing or incoming." << endl << "Use a negative number for an outgoing and a positive one for an incoming transaction" << endl;
	while (makeATransaction == true)
	{

		cin >> answer;
		if (answer == "Yes" || answer == "yes" || answer == "YES" || answer == "Y")
		{
			cout << "Our bank supports these types of assets Bitcoint(1), Ethereum(2), Rights(3), Stocks(4)" << endl;
			cout << "In which of these do you want add funds to? Choose the coresponding number." << endl;
			cin >> typeOfTran;
			if (typeOfTran == "1")
			{
				cout << "How much would you like to add to this asset?" << endl;
				cin >> btcAdd;
				btc->value += btcAdd;
				cout << "You now have " << btc->value << " in " << btc->type << endl;
			}
			else if (typeOfTran == "2")
			{
				cout << "How much would you like to add to this asset?" << endl;
				cin >> ethAdd;
				eth->value += ethAdd;
				cout << "You now have " << eth->value << " in " << eth->type << endl;
			}
			else if (typeOfTran == "3")
			{
				cout << "How much would you like to add to this asset?" << endl;
				cin >> rightsAdd;
				rights->value += rightsAdd;
				cout << "You now have " << rights->value << " in " << rights->type << endl;
			}
			else if (typeOfTran == "4")
			{
				cout << "How much would you like to add to this asset?" << endl;
				cin >> stocksAdd;
				stocks->value += stocksAdd;
				cout << "You now have " << stocks->value << " in " << stocks->type << endl;
			}
			else
			{
				cout << "Our bank doesn't support this type of asset" << endl;
			}
			assets(btc, eth, rights, stocks, makeATransaction, answer, typeOfTran);
		}
		else if (answer == "N" || answer == "NO" || answer == "no" || answer == "No")
		{
			makeATransaction = false; break;
		}
	}
}

