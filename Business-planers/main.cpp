#include "Header Files/main.h"
#include "Header Files/user_id.h"
#include "Header Files/assets.h"

int id;
int main()
{


	cout << " ____            _                            _                                 ";
	cout << "| __ ) _   _ ___(_)_ __   ___ ___ ___   _ __ | | __ _ _ __  _ __   ___ _ __ ___ ";
	cout << "|  _ \| | | / __| | '_ \ / _ / __/ __| | '_ \| |/ _` | '_ \| '_ \ / _ | '__/ __|";
	cout << "| |_) | |_| \__ | | | | |  __\__ \__ \ | |_) | | (_| | | | | | | |  __| |  \__ \"";
	cout << "|____/ \__,_|___|_|_| |_|\___|___|___/ | .__/|_|\__,_|_| |_|_| |_|\___|_|  |___/";
	cout << "                                       |_|                                      ";


	cout << " ____            _                       ";
	cout << "| __ ) _   _ ___(_)_ __   ___  ___ ___   ";
	cout << "|  _ \| | | / __| | '_ \ / _ \/ __/ __|  ";
	cout << "| |_) | |_| \__ \ | | | |  __/\__ \__ \  ";
	cout << "|____/ \__,_|___/_|_| |_|\___||___/___/  ";
	cout << "|  _ \| | __ _ _ __  _ __   ___ _ __ ___ ";
	cout << "| |_) | |/ _` | '_ \| '_ \ / _ \ '__/ __|";
	cout << "|  __/| | (_| | | | | | | |  __/ |  \__ \"";
	cout << "|_|   |_|\__,_|_| |_|_| |_|\___|_|  |___/";


	pqxx::connection* conn = new pqxx::connection("dbname=postgres user=Kaloyan password=Zow14194 host=database-business-planers.postgres.database.azure.com port=5432 sslmode=require");

	login(username, password, passwordVer, haveAccount, loginOrSignup, conn);
	assets(answer, typeOfTran, btcAdd, ethAdd, rightsAdd, stocksAdd, conn, btc, eth, rights, stocks);
	free(conn);
}
