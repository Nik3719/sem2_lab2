#pragma once
#include<string>

using namespace std;

struct DNode
{
    char data;
    DNode* next;
    DNode* prev;
    DNode(char value) : data(value), next(nullptr), prev(nullptr) {};
};