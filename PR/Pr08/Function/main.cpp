#include <iostream>
#include <complex>
#include "Complex.h"
using std::complex;
using std::cout;
using std::endl;
#include "functions.h"
int f(int x)
{
	return x;
}
// 1. C/C++>Optimization>Inline Function Expansion 	Only __inline (/ Ob1)
//                                                  Any Suitable (/Ob2)
//    General>Debug Information Format	Program Database(/ Zi)
// 2. Use Solution configuration Release

// 3. Calculate overhead of function call and compare costs of inline
// 4. Find out types of functions, lambda and built-in statics
// 5. Define templates
// 6. define cyclicshift for any integral type

int main()
{
	int x = 10;
	int y = 20;
	y = f(x);

	
	int m = 125;
	int n = 300;
	int res = gcd(m, n);

	[](int m, int n)
	{
		while (m != n)
			(m > n ? m -= n : n -= m);
		return m;
	}(225, 300);
	
	cout << ([](int a, int b) {return (a > b) ? a : b; }(1, 2) )<< endl;
	[](int a, int b) {return (a > b) ? a : b; }(1, 2);

	int (*p)(int, int) = &gcd;
	auto max = [](int a, int b) {return (a > b) ? a : b; };
	max(1, 2);

	struct Max
	{
		static int max(int a, int b) 
		{ 
			return (a > b) ? a : b; 
		}
	};

	cout << Max::max(1, 2) << endl;
	[](int m, int n)
		{
			while (m != n)
				(m > n ? m -= n : n -= m);
			return m;
		};

	struct GCD
	{
		static int gcd(int m, int n)
		{
			while (m != n)
				(m > n ? m -= n : n -= m);
			return m;
		}
	};

	Complex z1{ 1,2 };
	Complex z2{ 3,4 };
	Complex z3{ 7,8 };
	plus(z1, z2)=z3; //???

	auto cyclicShiftLeft = [](unsigned int x, int n)
		{
			return x << n | x >> (32 - n);
		};
	
	return 0;
}