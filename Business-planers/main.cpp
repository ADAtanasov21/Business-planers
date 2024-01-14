#include "Header Files/main.h"



int main()
{
	pqxx::connection* conn = new pqxx::connection("dbname=postgres user=Kaloyan password=Zow14194 host=database-business-planers.postgres.database.azure.com port=5432 sslmode=require");

	login(username, password, passwordVer, haveAccount, loginOrSignup, conn);
	assets(makeATransaction, answer, typeOfTran, btcAdd, ethAdd, rightsAdd, stocksAdd);

	free(conn);
}