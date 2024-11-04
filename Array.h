#pragma once
#include<iostream>
#include"Tools.h"


using namespace std;


struct Array
{
    int capacity = 0;
    int currentLen = 0;
    int* arr = nullptr;
    Array(int capacity = 0);
    ~Array();
    Array(Array& other);
    Array& operator=(const Array& other);

    void MPUSH(int elem);
    void MINSERT(int elem, int index);
    int MGET(int index);
    int MLEN();
    void MDEL(int index);
    void PRINT();
    void MSET(int elem, int index);
    int& operator[](int index);
};


