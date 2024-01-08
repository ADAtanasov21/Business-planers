#include "../Header Files/transactions.h"

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











void makeTransaction(TRAN* head, string answer, string typeOfTran, double amount, bool makeATransaction)
{
    string transactions[4] = {"Bitcoin", "Etherium", "Rights", "Stocks"};
    cout << "Do you want to make a new transaction? (Y/N)" << endl;
    getline(cin, answer);

    if (answer == "Y" || answer == "YES" || answer == "Yes" || answer == "yes")
    {
        makeATransaction = true;
    }
    else if ((answer == "N" || answer == "NO" || answer == "No" || answer == "no"))
    {
        makeATransaction = false;
        cout << "If you have lost your password or if you want to give a will to somebody please let me know?" << endl;
    }
    if (makeATransaction)
    {
        cout << "What type of transaction do you want to make? Our bank supports there four types: Bitcoin, Etherium, Rights and Stocks" << endl;
        getline(cin, typeOfTran);

        if (typeOfTran == "Bitcoin" || typeOfTran == "BTC" || typeOfTran == "bitcoin" || typeOfTran == "BITCOIN" || typeOfTran == "btc")
        {
            cout << "How big would you like the transaction to be?" << endl;
            cin >> amount;
            TRAN* a = new TRAN{ typeOfTran, amount, nullptr };
            head = a;
            cout << "Type of transaction: " << a->type << " amount of transaction: " << a->value << endl;
        }
        else if (typeOfTran == "Etherium" || typeOfTran == "ETH" || typeOfTran == "etherium" || typeOfTran == "ETHERIUM" || typeOfTran == "eth")
        {
            cout << "How big would you like the transaction to be?" << endl;
            cin >> amount;
            TRAN* a = new TRAN{ typeOfTran, amount, nullptr };
            head = a;
            cout << "Type of transaction: " << a->type << " amount of transaction: " << a->value << endl;
        }
        else if (typeOfTran == "Rights" || typeOfTran == "rights" || typeOfTran == "RIGHTS")
        {
            cout << "How big would you like the transaction to be?" << endl;
            cin >> amount;
            TRAN* a = new TRAN{ typeOfTran, amount, nullptr };
            head = a;
            cout << "Type of transaction: " << a->type << " amount of transaction: " << a->value << endl;
        }
        else if (typeOfTran == "Stocks" || typeOfTran == "stocks" || typeOfTran == "STOCKS")
        {
            cout << "How big would you like the transaction to be?" << endl;
            cin >> amount;
            TRAN* a = new TRAN{ typeOfTran, amount, nullptr };
            head = a;
            cout << "Type of transaction: " << a->type << " amount of transaction: " << a->value << endl;
        }
        else
        {
            cout << "Our bank doesn't support this type of transaction" << endl;
        }

        
        
    }
}

//void makeTransaction()
