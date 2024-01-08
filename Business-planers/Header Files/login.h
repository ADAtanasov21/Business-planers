#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


static string username = "Kaloyan";
static string password = "Zow14194";
static string passwordVer;
static char loginOrSignup;
static bool haveAcount = 1;


//void haveAnAcount(bool, char); 
void login(string, string, string, bool, char);
void sendToEcxcel(string, string);