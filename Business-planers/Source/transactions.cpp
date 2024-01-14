#include "../Header Files/transactions.h"
#include <string>
#include <cstdlib>


void addTran(TRAN*& head, string type, double& value)
{
	TRAN* newTran = new TRAN(type, value);
	newTran->next = head;
	head = newTran;
}


void displayBtc(TRAN* head)
{
	TRAN* current = head;
	while (current != nullptr)
	{
		std::cout << "You now have " << btc << " in " << current->type << endl;
		current = current->next;
	}
}

void displayEth(TRAN* head)
{
	TRAN* current = head;
	while (current != nullptr)
	{
		std::cout << "You now have " << eth << " in " << current->type << endl;
		current = current->next;
	}
}

void displayRights(TRAN* head)
{
	TRAN* current = head;
	while (current != nullptr)
	{
		std::cout << "You now have " << rights << " in " << current->type << endl;
		current = current->next;
	}
}

void displayStocks(TRAN* head)
{
	TRAN* current = head;
	while (current != nullptr)
	{
		std::cout << "You now have " << stocks << " in " << current->type << endl;
		current = current->next;
	}
}

void assets(bool& makeATransaction, string& answer, string& typeOfTran, double& btcAdd, double& ethAdd, double& rightsAdd, double& stocksAdd)
{
	TRAN* head = nullptr;

	std::cout << "Do you want to make a new transaction? It could be outgoing or incoming." << endl << "Use a negative number for an outgoing and a positive one for an incoming transaction" << endl;
	while (makeATransaction)
	{
		std::cin >> answer;
		if (answer == "Yes" || answer == "yes" || answer == "YES" || answer == "Y" || answer == "y")
		{
			std::cout << "Our bank supports these types of assets Bitcoin(1), Ethereum(2), Rights(3), Stocks(4)" << endl;
			std::cout << "In which of these do you want to operate with? Choose the corresponding number." << endl;
			std::cin >> typeOfTran;

			if (typeOfTran == "1")
			{
				std::cout << "How much would you like to add to this asset?" << endl;
				std::cin >> btcAdd;
				btc += btcAdd;
				addTran(head, "Bitcoin", btcAdd);
				system("cls");
				displayBtc(head);
			}
			else if (typeOfTran == "2")
			{
				std::cout << "How much would you like to add to this asset?" << endl;
				std::cin >> ethAdd;
				eth += ethAdd;
				addTran(head, "Ethereum", ethAdd);
				system("cls");
				displayEth(head);
			}
			else if (typeOfTran == "3")
			{
				std::cout << "How much would you like to add to this asset?" << endl;
				std::cin >> rightsAdd;
				rights += rightsAdd;
				addTran(head, "Rights", rightsAdd);
				system("cls");
				displayRights(head);
			}
			else if (typeOfTran == "4")
			{
				std::cout << "How much would you like to add to this asset?" << endl;
				std::cin >> stocksAdd;
				stocks += stocksAdd;
				addTran(head, "Stocks", stocksAdd);
				system("cls");
				displayStocks(head);
			}
			else
			{
				std::cout << "Our bank doesn't support this type of asset" << endl;
			}
			assets(makeATransaction, answer, typeOfTran, btcAdd, ethAdd, rightsAdd, stocksAdd);
			std::cout << endl;
		}
		else if (answer == "N" || answer == "NO" || answer == "no" || answer == "No" || answer == "n")
		{
			cout << "You have: " << endl << btc << " in Bitcoin" << endl;
			cout << eth << " in Ethereum" << endl;
			cout << rights << " in Rights" << endl;
			cout << stocks << " in Stocks" << endl;
			break;
		}
	}
}