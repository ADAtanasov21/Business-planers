#include <iostream>
#include <string>
using namespace std;




#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Define the structure for a node in the linked list
struct TRAN {
    string type;
    double value;
    TRAN* next;
};

static TRAN* head = new TRAN;
static string answer;
static string typeOfTran;
static double amount;
static bool makeATransaction = true;

// Function declarations
TRAN* createNode(double value);
void insertNode(TRAN*& head, double value);
void displayList(TRAN* head);
void deleteList(TRAN*& head);
void makeTransaction(TRAN* , string , string , double , bool);



#endif