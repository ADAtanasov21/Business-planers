#pragma once
#include <iostream>
#include <string>

using namespace std;




#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Define the structure for a node in the linked list
struct TRAN 
{
    string type;
    double value;
    TRAN* next;

    TRAN(string t, double v) : type(t), value(v), next(nullptr) {}
};

static string answer;
static string typeOfTran;
static double amount;
static double btcAdd;
static double ethAdd;
static double rightsAdd;
static double stocksAdd;
static double btc = 0;
static double eth = 0;
static double rights = 0;
static double stocks = 0;
static int numOfPeople;

static bool makeATransaction = true;


void addTran(TRAN*&, string, double&);
void displayBtc(TRAN*);
void displayEth(TRAN*);
void displayRights(TRAN*);
void displayStocks(TRAN*);
void assets(bool&, string&, string&, double&, double&, double&, double&);


#endif