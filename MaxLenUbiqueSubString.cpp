#include"MaxLenUbiqueSubString.h"

Pair<string,int> MaxLenUbiqueSubString(string str)
{
	Set<char> uniqueSubString;
	dict<int> uniqueSubStrings;
	for (char sym : str)
	{
		if (uniqueSubString.SET_AT(sym))
		{
			string buf;
			int index = 0;
			while (index < uniqueSubString.size)
			{
				if (uniqueSubString.table[index].isOccupied)
				{
					buf += uniqueSubString.table[index].key;
					uniqueSubString.SETDEL(uniqueSubString.table[index].key);
				}
				index++;
			}
			uniqueSubStrings.HSET(buf, buf.size());
		}
		else
		{
			uniqueSubString.SETADD(sym);
		}
	}
	int index = 0;
	int max = 0;
	Pair<string,int> res;
	while (index < uniqueSubStrings.size)
	{
		if (uniqueSubStrings.table[index].isOccupied)
		{
			string k = uniqueSubStrings.table[index].key;
			int len = uniqueSubStrings.table[index].value;
			if (len > max)
			{
				max = len;
				res.first = k;
				res.second = len;
			}
		}
		index++;
	}
	return res;
}