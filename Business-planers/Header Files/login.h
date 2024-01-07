#pragma once
#include <iostream>
#include <string>
using namespace std;


static string username;
static string password;
static string passwordVer;
static char loginOrSignup;
static bool haveAcount = 1;


//void haveAnAcount(bool, char); 
void login(string, string, string, bool, char);