#include"Tools.h"

int mod(int a, int b)
{
    if (a < 0)
    {
        a = b - (-a);
    }
    return a % b;
}


string PlusOne(string& num)
{
    int len = num.size();
    int countLoop = 0;
    for (size_t i = len - 1; i >= 0; i--)
    {
        if (num[i] < '9')
        {
            num = num.substr(0, i) + char(num[i] + 1);
            string countNull = "";
            for (int j = 0; j < countLoop; j++)
            {
                countNull += '0';
            }
            num = num + countNull;
            return num;
        }
        countLoop++;
    }
}


int ByteToInt(string str)
{
    int res = 0;
    for (unsigned char b : str)
    {
        res = (res << 8) + (b & 0xFF);
    }
    return res;
}




bool fileExists(const string& filename) 
{
    ifstream file(filename);
    bool res = file.good(); // ���������, ������� �� ������ ����
    if (res)
    {
        file.close();
    }
    return res;
}


DL<string> split(string str)
{
    DL<string> res;
    size_t length = str.size();
    string buf = "";
    for (size_t i = 0; i < length; i++)
    {
        if (str[i] == ' ')
        {
            res.LDPUSHT(buf);
            buf.clear();
        }
        else
        {
            buf += str[i];
        }
    }
    res.LDPUSHT(buf);
    return res;
}

int64_t dg(int64_t base, int64_t exponent) 
{
    long long result = 1;
    while (exponent > 0) {
        // ���� exponent ��������, �������� ��������� �� base
        if (exponent % 2 == 1) {
            result *= base;
        }
        // �������� base �� ����
        base *= base;
        // ����� exponent �� 2
        exponent /= 2;
    }
    return result;
}

void Sort(DL<int> list, int listLength)
{
    while(listLength--)
	{
		bool swapped = false;
		
		for(int i = 0; i < listLength; i++)
		{
			if(list[i] > list[i + 1])
			{
                int buf = list[i];
                list[i] = list[i+1];
                list[i+1] = buf;
				swapped = true;
			}
		}
		
		if(swapped == false)
			break;
	}
}