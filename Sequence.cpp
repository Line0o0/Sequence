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


	/*if (fin.fail())
	{
	cout<< "No such file:" <<a<< endl;
	}*/

	fin.open(a);
	if (!fin)
	{
		cerr << "File could not be opened." << endl;
	}
	else cout << "get" << endl;
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
	char max = 'Q';
	char base = 'Q';
	long long slength = s.length();
	int count = 0;
	int mcount = 0;
	for (int i = 0; i < slength; ++i)
	{
		if (base == s[i])
			count++;
		else
		{
			if (count>mcount)
			{
				max = base;
				mcount = count;
			}
			base = s[i];
			count = 1;
		}
	}
	for (int i = 0; i < mcount; ++i)
	{
		longest = longest + max;
	}
	cout << mcount << endl;
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

//Variables used in the following function
char c[1500000];
char* cPtr[1500000];

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


