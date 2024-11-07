#include"set.h"

static string HTID = "0";
Set::Set(int size)
{
	this->size = size;
	this->table = new SetNode[size];
}


Set::~Set()
{
	delete[]table;
}

void Set::resize(string key)
{
	int oldSize = size;
	if (size == 0)size++;
	size *= 2;
	SetNode* newTable = new SetNode[size];;
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
	delete []table;
	table = newTable;
	SETADD(key);
}
void Set::SETADD(string key)
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


int Set::hashFunc(string key)
{
	int k = ByteToInt(key);
	return (k % size);//+ i * (1 + (k % (size - 1)))) % size;
	// первая хэш-функция + i*втроая хэш фукнция
}

bool Set::SET_AT(string key)
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
		if (table[index].NoneDeletePresence == 1)
		{
			return false;
		}
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

void Set::SETDEL(string key)
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
			cout << "такого нет\n";
			return;
		}
	}
	cout << "такого нет\n";
	len--;
	return;
	
}

void Set::PRINT()
{
	int index = 0;
	while (index<size)
	{
		if (table[index].isOccupied)
		{
			cout << table[index].key << "\n";
		}
		index++;
	}

}
