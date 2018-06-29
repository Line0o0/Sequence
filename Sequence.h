#pragma once
#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<string>
#include <cmath>
#include<iostream>
#include<fstream>
#include <iomanip>
using namespace std;


class Sequence
{
public:
	Sequence(const char* a);
	~Sequence();
	string longestConsecutive();
	int numberOf(char base);
	string longestRepeated();
	//int LengthOfCommon(const char *p1, const char *p2);
	//int Suffix(int);
	//bool StringCompare(const char *pa, const char *pb);
	int getlength();
	//vector<const char*> pStr;

private:
	ifstream fin;
	string s;
	void getstr();
};
#endif // SEQUENCE_H
