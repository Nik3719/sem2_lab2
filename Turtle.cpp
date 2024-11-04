#include"Turtle.h"

int TrustTurtle(int quantity, Pair<int,int>* statements)
{
	Set<Pair<int, int>> row;
	for (size_t i = 0; i < quantity; i++)
	{
		Pair<int, int> elem = statements[i];
		if (elem.first + elem.second + 1 == quantity)
		{
			row.SETADD(elem);
		}
	}
	return row.len;
}