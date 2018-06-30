#include"Sequence.h"
#include<iomanip>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

Sequence::Sequence(const char* a)
{
	fin.open(a);
        if(fin.fail())
        {
          cout<<"No Such File!"<<a<<endl;
        }  
	getstr();
}

Sequence::~Sequence()
{
	fin.close();

}

void Sequence::getstr()
{
	char * str = new char[1000];
	while (!fin.eof())
	{
		fin.getline(str, 1000);
		s = s + str;

	}

}

int Sequence::getlength()
{
	return  s.length();
}

int Sequence::numberOf(char base)
{
	int counter = 0;
	for (unsigned int i = 0; i<s.length(); i++)
	{
		if (s[i] == base)
			counter++;
	}
	return counter;

}


string Sequence::longestConsecutive()
{
	string longest;
	longest.clear();
	int mcounter = 0;
	int counter = 0;
	char base;
	char cha;
	long long slength = s.length();
	base = s[0];
	for (unsigned int i = 0; i < slength; ++i)
		{
			if (base == s[i])
				counter++;
			else
			{
				if (counter > mcounter)
				{
					mcounter = counter;
					cha = base;
				}
				base = s[i];
				counter = 1;
			
			}
		}

	longest = cha;
	for (int i = 0; i < mcounter; i++)
	{
		longest = longest + cha;
	}
	cout << mcounter << endl;
	return longest;
}


int pstrcmp(const void* p1, const void* p2)
{
	return strcmp(*(const char**)p1, *(const char**)p2);
}

int commonLength(char*p, char*q)
{
	int i = 0;
	while (p[i] == q[i++]);
	return --i;
}

char c[1200000];
char* cPtr[1200000];

string Sequence::longestRepeated()
{
	int slength = s.length();
	int max = 0;
	int point = 0;
	for (int i = 0; i<slength; ++i)
	{
		cPtr[i] = &c[i];
		c[i] = s[i];
	}
	c[slength] = 0;
	qsort(cPtr, slength, sizeof(char*), pstrcmp);
	for (int i = 0; i<slength - 1; ++i)
	{
		if (commonLength(cPtr[i], cPtr[i + 1]) > max)
		{
			max = commonLength(cPtr[i], cPtr[i + 1]);
			point = i;
		}
	}
	string out;
	out.assign(cPtr[point], max);
	return out;
}


