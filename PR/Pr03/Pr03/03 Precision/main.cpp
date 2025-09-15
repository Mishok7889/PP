#include <iostream>
#include "Precision.h"
using namespace std;

// Calculate size and maximum of int, long int, long long int
// Calculate precision of double

int main()
{
	cout << "max_char "<<max_char() << endl;
	cout <<  "size_char "<<size_char() << endl;
	float x = 1;
	float d = 1e-8f;
	int n = 100000000;
	for (int k = 0; k < n; ++k)
		x = x + d;
	cout << "for loop " << x << endl;
	cout << "mult " << x + n * d << endl;
	cout << "float 10:" << prec(10) << endl;
	cout << "float 16:" << prec(16) << endl;
	
	__int8 c = -1;
	cout << int(c) << ':' << c << ':' << char(c) << endl;
	for (__int8 c = 0; c > 0; ++c)
	{
	};
	cout << char(c) << ':' << c << ':' << int(c) << endl;

	unsigned __int8 uc = -1;
	cout << int(uc) << ':' << uc << ':' << char(uc) << endl;
	for (__int8 uc = 0; uc > 0; ++uc)
	{
	};
	cout << char(uc) << ':' << uc << ':' << int(uc) << endl;

	return 0;
}
