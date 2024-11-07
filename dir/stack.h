#pragma once
#include<string>
#include<iostream>
#include"DNode.h"



using namespace std;

struct Stack
{
	DNode* spointer;
	string fileName;
	int len = 0;
	Stack();
	bool isEmpty() { return len == 0; }
	~Stack();
	void SPUSH(char elem);
	char SPOP();
	char SGET(int index);
	void PRINT();
};