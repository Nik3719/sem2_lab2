#pragma once
#include<iostream>
#include<string>
#include"Tools.h"

using namespace std;



struct SetNode
{
	string key;
	bool isOccupied;
	int NoneDeletePresence;
	struct SetNode () : key(""), isOccupied(false), NoneDeletePresence(1) {};
};

struct Set
{
	SetNode* table;
	int size = 0;
	int len = 0;
	Set(int=0);
	~Set();
	void SETADD(string key);
	int hashFunc(string key);
	bool SET_AT(string key);
	void SETDEL(string key);
	void resize(string key);
	void PRINT();
};

