#include "../Header Files/transactions.h"
#include "../Header Files/user_id.h"
#include <string>


void addTran(TRAN*& head, string type, double& value)
{
	TRAN* newTran = new TRAN(type, value);
	newTran->next = head;
	head = newTran;
}


void displayBtc(TRAN* head, double& btc)
{
	TRAN* current = head;
	while (current != nullptr)
	{
		std::cout << "You now have " << btc << " in " << current->type << endl;
		current = current->next;
	}
}

void displayEth(TRAN* head, double& eth)
{
	TRAN* current = head;
	while (current != nullptr)
	{
		std::cout << "You now have " << eth << " in " << current->type << endl;
		current = current->next;
	}
}

void displayRights(TRAN* head, double& rights)
{
	TRAN* current = head;
	while (current != nullptr)
	{
		std::cout << "You now have " << rights << " in " << current->type << endl;
		current = current->next;
	}
}

void displayStocks(TRAN* head, double& stocks)
{
	TRAN* current = head;
	while (current != nullptr)
	{
		std::cout << "You now have " << stocks << " in " << current->type << endl;
		current = current->next;
	}
}

void assets( string& answer, string& typeOfTran, double& btcAdd, double& ethAdd, double& rightsAdd, double& stocksAdd, pqxx::connection* conn, double& btc, double& eth, double& rights, double& stocks)
{
	TRAN* head = nullptr;

	std::cout << "Do you want to make a new transaction? It could be outgoing or incoming." << endl << "Use a negative number for an outgoing and a positive one for an incoming transaction" << endl;
	
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
				displayBtc(head, btc);
			}
			else if (typeOfTran == "2")
			{
				std::cout << "How much would you like to add to this asset?" << endl;
				std::cin >> ethAdd;
				eth += ethAdd;
				addTran(head, "Ethereum", ethAdd);
				system("cls");
				displayEth(head, eth);
			}
			else if (typeOfTran == "3")
			{
				std::cout << "How much would you like to add to this asset?" << endl;
				std::cin >> rightsAdd;
				rights += rightsAdd;
				addTran(head, "Rights", rightsAdd);
				system("cls");
				displayRights(head, rights);
			}
			else if (typeOfTran == "4")
			{
				std::cout << "How much would you like to add to this asset?" << endl;
				std::cin >> stocksAdd;
				stocks += stocksAdd;
				addTran(head, "Stocks", stocksAdd);
				system("cls");
				displayStocks(head, stocks);
			}
			else
			{
				std::cout << "Our bank doesn't support this type of asset" << endl;
			}

			return assets(answer, typeOfTran, btcAdd, ethAdd, rightsAdd, stocksAdd, conn, btc, eth, rights, stocks);
			std::cout << endl;
		}
		else if (answer == "N" || answer == "NO" || answer == "no" || answer == "No" || answer == "n")
		{
			cout << "You have: " << endl << btc << " in Bitcoin" << endl;
			cout << eth << " in Ethereum" << endl;
			cout << rights << " in Rights" << endl;
			cout << stocks << " in Stocks" << endl;


			pqxx::work worker(*conn);
			pqxx::result res = worker.exec("SELECT btc, eth, stocks, rights FROM assets WHERE user_id = " + to_string(id));
			
			if (!res.empty())
			{
				pqxx::result::const_iterator row = res.begin();
				btc += row["btc"].as<double>();
				eth += row["eth"].as<double>();
				stocks += row["stocks"].as<double>();
				rights += row["rights"].as<double>();
				res = worker.exec("UPDATE assets SET btc = " + to_string(btc) + ", eth = " + to_string(eth) + ", stocks = " + to_string(stocks) + ", rights = " + to_string(rights) + " WHERE user_id = " + to_string(id));
			}
			else
			{
				res = worker.exec("INSERT INTO assets(btc, eth, stocks, rights, user_id) VALUES('" + to_string(btc) + "','" + to_string(eth) + "','" + to_string(stocks) + "','" + to_string(rights) + "','" + to_string(id) + "')");
			}
			worker.commit();
			return;
		}
		else
		{
			cout << "You should type yes or no" << endl;
			assets(answer, typeOfTran, btcAdd, ethAdd, rightsAdd, stocksAdd, conn, btc, eth, rights, stocks);

		}
		//cout << endl << "At our bank, your heirs inherit your will, distributing it in percentages determined by you" << endl << endl;
}



void will(int sumToHundred, int heirsCounter, pqxx::connection* conn)
{
	double percentages[20];
	
	cout << "How many heirs will you have" << endl;
	cin >> heirsCounter;
	for (int i = 0; i < heirsCounter; i++)
	{
		cout << "What percentage of your will will be received by heir " << i + 1 << "?" << endl;
		cin >> percentages[i];
		sumToHundred += percentages[i];
	}
	if (sumToHundred != 100)
	{
		cout << "You didn't distribute your will among your heirs. The sum of the percentages must be exactly 100! Try enterin them again." << endl;
		sumToHundred = 0;
		will(sumToHundred, heirsCounter, conn);
	}
	else
	{
		pqxx::work worker(*conn);
		pqxx::result res = worker.exec("SELECT btc, eth, stocks, rights FROM assets WHERE user_id = " + to_string(id));

		pqxx::result::const_iterator row = res.begin();
		double btc = row["btc"].as<double>();
		double eth = row["eth"].as<double>();
		double stocks = row["stocks"].as<double>();
		double rights = row["rights"].as<double>();

		for (int i = 0; i < heirsCounter; i++)
		{
			cout << "Heir " << i + 1 << " is going to receive " << float((percentages[i] / sumToHundred)) * (btc + eth + rights + stocks) << endl;

		}
	}
}