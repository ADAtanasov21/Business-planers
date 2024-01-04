#include <iostream>
#include <string>
using namespace std;


#ifndef STRUCT_DEFINITION_H
#define STRUCT_DEFINITION_H

struct TRAN;


struct TRAN 
{
    string type;
    double amount;

    
    TRAN(string str, double d) : type(str), amount(d) {}

    void display();
};

#endif 