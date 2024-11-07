#include"MaxLenUbiqueSubString.h"

bool search(string str, char sym)
{
	if (str.empty())
	{
		return false;
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i]==sym)
		{
			return true;
		}
	}
	return false;
	
} 

Pair<string,int> MaxLenUbiqueSubString(string str)
{
	dict<int> indexSym;
	string buf;

	for (char sym:str)
	{
		if (search(buf,sym))
		{
			int len = buf.size();
			indexSym.HSET(buf,len);
			buf.clear();
			buf += sym;
		}
		else
		{
			buf+=sym;
		}
	}
	int len = buf.size();
	indexSym.HSET(buf, len);
	string MaxLenString;
	int index = 0;
	while (index<indexSym.size)
	{
		if (indexSym.table[index].isOccupied)
		{
			if (indexSym.table[index].key.size()>MaxLenString.size())
			{
				MaxLenString=indexSym.table[index].key;
			}
		}
		index++;
	}
	return {MaxLenString,indexSym[MaxLenString]};
}