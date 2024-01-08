#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include<Windows.h>
using namespace std;


static string username = "Kaloyan";
static string password = "Zow14194";
static string passwordVer;
static char loginOrSignup;
static bool haveAccount = 1;


//void haveAnAccount(bool, char); 
void login(string, string, string, bool, char);
void sendToEcxcel(string, string);