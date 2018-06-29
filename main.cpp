#include<iostream>
#include"Sequence.h"
#include<string>
#include<fstream>
#include <ctime>
using namespace std;

int main()
{

	Sequence test("dna.txt");
	clock_t a, b, c, d;
        cout<<"*********************************************************"<<endl<<endl;
        cout<<"                 Testing program.                   "<<endl<<endl;
        cout<<"*********************************************************"<<endl<<endl;
	cout << "Testing function length():" << endl<<endl;
	cout << "The length of the file is " << test.getlength() << endl << endl;
        cout<<"*********************************************************"<<endl<<endl;
	cout << "Testing function numberOF():" << endl << endl;
	cout << "Number of A: " << test.numberOf('A') << endl;
	cout << "Number of T: " << test.numberOf('T') << endl;
	cout << "Number of G: " << test.numberOf('G') << endl;
	cout << "Number of C: " << test.numberOf('C') << endl << endl;
        cout<<"*********************************************************"<<endl<<endl;
	cout << "Testing function longestConsecutive()" << endl << endl;
        a = clock();
	cout << test.longestConsecutive() << endl<<endl;
	b = clock();
	cout << "Time used: " << (double)(b-a) / (double)CLOCKS_PER_SEC << endl << endl;
        cout<<"********************************************************"<<endl<<endl;
	cout << "Testing function longestRepeated()" << endl << endl;
	c = clock();
	cout << test.longestRepeated() << endl;
	d = clock();
	cout << "Time used: " << (double)(d - c) / (double)CLOCKS_PER_SEC << endl << endl;
        cout<<"*********************Thank you*************************"<<endl<<endl;
	return 0;
}
