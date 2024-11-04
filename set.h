#pragma once
#include<iostream>
#include <typeinfo>
#include <type_traits>
#include<string>
#include"Tools.h"

using namespace std;


template <typename T>
struct SetNode
{
	T key;
	bool isOccupied;
	int NoneDeletePresence;
	SetNode(): key(T()), isOccupied(false), NoneDeletePresence(1) {};
};

template <typename T>
struct Set
{
	SetNode<T>* table;
	int size = 0;
	int len = 0;
	Set(int=0);
	~Set();
	void SETADD(T key);
	int hashFunc(T key);
	bool SET_AT(T key);
	void SETDEL(T key);
	void resize(T key);
	void PRINT();
};



template <typename T>
Set<T>::Set(int size)
{
	this->size = size;
	this->table = new SetNode<T>[size];
}

template <typename T>
Set<T>::~Set()
{
	delete[]table;
}

template <typename T>
void Set<T>::resize(T key)
{
	int oldSize = size;
	if (size == 0)size++;
	size *= 2;
	SetNode<T>* newTable = new SetNode<T>[size];;
	for (int j = 0; j < oldSize; j++)
	{
		if (table[j].isOccupied)
		{
			int index = hashFunc(table[j].key);
			while (newTable[index].isOccupied)
			{
				index = (index + 1) % size;
			}
			newTable[index].key = table[j].key;
			newTable[index].isOccupied = true;
			newTable[index].NoneDeletePresence = 3;
		}
	}
	delete[]table;
	table = newTable;
	SETADD(key);
}
template <typename T>
void Set<T>::SETADD(T key)
{
	if (size == 0)
	{
		resize(key);
	}
	int i = 0;
	int index = hashFunc(key);
	int oldIndex = index;
	while (table[index].isOccupied)
	{
		if (table[index].key == key)
		{
			return;
		}
		index = (index + 1) % size;
		if (oldIndex == index)
		{
			resize(key);
			return;
		}
	}
	table[index].key = key;
	table[index].isOccupied = true;
	table[index].NoneDeletePresence = 3;
	len++;
}

template <typename T>
int Set<T>::hashFunc(T value)
{
	int k;
	if constexpr (is_same<T,int>::value)
	{
		k = value;
	}
	else if constexpr (is_same<T, string>::value)
	{
		k = ByteToInt(value);
	}
	else if constexpr (is_same<T, char>::value)
	{
		k = value;
	}
	else if constexpr (is_same<T, Pair<int,int>>::value)
	{
		k = value.first + value.second;
	}
	else if constexpr (is_same<T, Pair<string, int>>::value)
	{
		k = value.second;
	}
	return (k % size);//+ i * (1 + (k % (size - 1)))) % size;
	// ������ ���-������� + i*������ ��� �������
}

template <typename T>
bool Set<T>::SET_AT(T key)
{
	if (size == 0)
	{
		return false;
	}
	int i = 0;
	int index = hashFunc(key);
	int oldIndex = index;
	while (table[index].isOccupied)
	{
	/*	if (table[index].NoneDeletePresence == 1)
		{
			return false;
		}*/
		if (table[index].key == key)
		{
			return true;
		}

		index = (index + 1) % size;
		if (oldIndex == index)
		{
			break;
		}
	}
	return false;
}

template <typename T>
void Set<T>::SETDEL(T key)
{
	if (size == 0)
	{
		return;
	}
	int i = 0;
	int index = hashFunc(key);
	int oldIndex = index;
	while (table[index].isOccupied)
	{
		if (table[index].key == key)
		{
			table[index].isOccupied = false;
			table[index].NoneDeletePresence = 2;
			return;
		}
		index = (index + 1) % size;
		if (oldIndex == index)
		{
			//cout << "������ ���\n";
			return;
		}
	}
	//cout << "������ ���\n";
	len--;
	return;

}

template <typename T>
void Set<T>::PRINT()
{
	int index = 0;
	while (index < size)
	{
		if (table[index].isOccupied)
		{
			cout << table[index].key << "\n";
		}
		index++;
	}

}
