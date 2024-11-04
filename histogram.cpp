#include"histogram.h"





Array GetHistogram(string str)
{
	Array hist(127);

	for (char sym : str)
	{
		int codeSym = sym;
		if (codeSym == 32) continue;
		hist[codeSym] += 1;
	}
	return hist;
}