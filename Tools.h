#pragma once
#include<string>
#include<fstream>
#include"DL.h"



using namespace std;


int mod(int a, int b);
string PlusOne(string& num);
int ByteToInt(string str);
bool fileExists(const string& filename);
DL<string> split(string str);
int64_t dg(int64_t base, int64_t exponent);

template<typename T, typename T1>
struct Pair
{
	T first;
	T1 second;
	friend istream& operator>>(istream& in, Pair<T,T1>& pair)
	{
		in >> pair.first >> pair.second;
		return in;
	}
	friend ostream& operator<<(ostream& os, Pair<T, T1>& pair)
	{
		cout << pair.first << " " << pair.second;
		return os;
	}
	friend bool operator==(Pair<T, T1>& pair1, Pair<T, T1>& pair2)
	{
		if (pair1.first != pair2.first)
		{
			return false;
		}
		if (pair1.second != pair2.second)
		{
			return false;
		}
		return true;
	}
};
