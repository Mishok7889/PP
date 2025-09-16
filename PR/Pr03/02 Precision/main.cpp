#include <iostream>
#include <limits>
#include "Precision.h"
using namespace std;

// Home task
// 1. Calculate size and maximum of int, long int, long long int
// 2. Calculate precision of double

int main()
{
	{
		const int n = 10;
		const char* hello[] = "Hellow, world!";
		std::array<double,n> ar;
		cout << hello<<endl;
		std::string s;
	}
	cout << "max_char "<<max_char() << endl;
	cout <<  "size_char "<<size_char() << endl;
	float x = 1;
	float d = 1e-8f;
	int n = 100'000'000;
	cout << "before loop " << x << endl;
	for (int k = 0; k < n; ++k)
		x = x + d;
	cout << "after loop  " << x << endl;
	cout << "sum  " << x + n * d << endl;
	// Calculate precision of float
	cout << "float 10:" << prec(10) << endl;
	cout << "float 16:" << prec(16) << endl;
	// Compare with standard tools
	// Size of mantissa in bits
	cout << numeric_limits<float>::digits << endl;
	// Size of mantissa in digits
	cout << numeric_limits<float>::digits10 << endl;
	// Size of mantissa double in bits
	cout << numeric_limits<double>::digits << endl;
	// Size of mantissa double in digits
	cout << numeric_limits<double>::digits10 << endl;
	return 0;
}
