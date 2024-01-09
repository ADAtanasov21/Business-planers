#include "Header Files/main.h"


int main()
{
	TRAN* head = nullptr;

	// Insert elements into the linked list
	insertNode(head, 10);
	insertNode(head, 20);
	insertNode(head, 30);

	login(username, password, passwordVer, haveAccount, loginOrSignup);
	makeTransaction(head, answer, typeOfTran, amount, makeATransaction);
	
	// Display the linked list
	std::cout << "Linked List: ";
	displayList(head);

	// Delete the linked list
	deleteList(head);


	return 0;
}