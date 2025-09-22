#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;
// Only in C++20
#include <numbers>
using namespace std::numbers;
#include <complex>
#include <string>
#include <fstream>
#include "Literals.h"
// Home task
// Define type Month as an enumeration
// Function show print the name of an month by its number

void f()
{
	double* p = new double(9);
}

int main(void)
{
	// generally speaking, const must have a value
	const int zero = 0;
	cout << "zero=" << zero << endl;
	double zx = zero;
	//nullptr + 4;
	cout<<NULL + 6<<endl;
	char str2[] = "Literal, too";
	str2[0] = 'l';
	cout << str2 << endl;
	//char* str = "Literal";
	/*for(int i=0; i<100'000'000; ++i)
	{ 
		double* p = new double(9);
	}*/
	double* p = new double(1);
	double* q = new double(1);
	cout << p << endl;
	cout << q << endl;
	cout << (nullptr==0) << endl;
	/*try
	{
		double *p = new double(9);
		throw bad_alloc();
	}
	catch (const bad_alloc& ba)
	{
		cout << ba.what() << endl;
	}*/
		

	{
		//const double pi = 3.1415926535897932;
		const double pi = M_PI;
		// is precision enough?
		cout << "pi=" << pi << endl;
		zx = pi;
		zx = M_PI;
	}
	{
		const long double pi
			= 3.141'592'653'589'793'238'462l;
		ofstream out("out.txt");
		out.precision(22);
		out << pi << endl;
	}

	// What ia the better way to define pi?
	cout << "pi=" << pi << endl;
	zx = pi;
	// generally speaking, every variable should have an initial value
	// unless it obtains it immediately
	char c;
	//cout << "Undefined value " << c << endl;
	cout << "give your char ";
	cin >> c;
	// always confirm the value you have inputted
	cout << "you gave " << c << endl;

	double x;
	//cout << "Undefined value " << x << endl;
	double* px = &x;
	cout << *px << endl; 
	cout << (hex)<<(unsigned long long int)(*px) << endl;
	cout << "give your real ";
	cin >> x;
	cout << "you gave " << x << endl;
	
	{
		// Literal tzpes
		cout << type(1) <<endl;
		cout << type(1u) << endl;
		cout << type(1l) << endl; 
		cout << type(1ul) << endl;
		cout << type(1.0) << endl;
		cout << type(1.0f) << endl;
		cout << type(1.0l) << endl;

		// Add qualifier for any known type
		int n(100);
		cout << type(n) << endl;
		const int k(1u);
		cout << type(k) << endl;
		cout << my_type_info<decltype(k)>() << endl;
		int& r(n);
		cout << type(r) << endl;
		cout << my_type_info<decltype(r)>() << endl;
		const int& cr(n);
		cout << type(cr) << endl;
		cout << my_type_info<decltype(cr)>() << endl;
	}
	// Type consistency
	complex<float> z1;
	const complex<float> z2;
	complex<float> z3;
	/*z1 = 1 + z2;
	z1 = 1.0 + z2;*/
	z1 = 1.0f + z2;

	// Brace initialisation

	int k1 = 3.14;
	//int k2 = { 3.14 };

	unsigned int u1 = -3;
	//unsigned int u2 = { -3 };

	unsigned u3 = { 3 };
	int i1 = { 2 };
	//unsigned u4 = { i1 };
	//int i2 = { u3 };

	// Compare initialisation with assignment
	string s("tratata");
	string ss(s);
	string sss = s;
	ss = s;
	ss += s;
	ss = ss + s;

	s = ss = sss;
	ss = sss;
	s = ss;

	z1 += z2;
	z1 = z1 + z2;

	z1 = z3 = z2;
	z3 = z2;
	z1 = z3;
	{
		complex<double> z1, z2, z3;
		z1 = z3 = z2;
		z3 = z2;
		z1 = z3;
	}
	// Examine types string and complex
	return 0;
}