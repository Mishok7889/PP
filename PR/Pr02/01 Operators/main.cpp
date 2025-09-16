#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cassert>
#include <numbers>
using namespace std;
using namespace std::numbers;

//Home tasks
//Transfer while (F) do P into do...while ... and vice versa
//Exclude if (F) P; else Q;
//
int main(void)
{
	// generally speaking, const must have a value
	const int zero = 0;
	cout << "zero=" << zero << endl;
	double zx = zero;

	//const double pi = 3.1415926535897932;
	//comment next line
	//const double pi =  M_PI;
	// is precision enough?
	cout << "pi=" << pi << endl;
	zx = pi;
	//assert(zx < 0);
	//if (zx > 0) exit(10);
	// generally speaking, every variable should have an initial value
	// unless it obtains it immediately
	char c;
	cout << "give your char ";
	cin >> c;
	// always confirm the value you have inputted
	cout << "you gave " << c << endl;

	double x;
	cout << "give your real ";
	cin >> x;
	cout << "you gave " << x << endl;
	if (x > 0)
		cout << "you gave positive " << x << endl;
	else
		cout << "you gave negative " << x << endl;
	//	Trying uninitialized variable 
	/*double foo;
	cout << "not initialized " << foo << endl;*/

	// infinite loop
	while (true)
	{
		char reply;
		cout << "counter game: repeat(y/n)?";
		cin >> reply;
		//not structured operator: 
		if (reply != 'y') break;

		int n;
		cout << "how many repetition? ";
		cin >> n;

		// a loop with counter
		for (int i = 0; i < n; ++i)
			cout << i << ' ';
		cout << endl;

		// descending while loop
		int i = n;
		while (i > 0)
		{
			cout << i << ' ';
			--i;
		}
		cout << endl;

		// ascending while loop
		i = 0;
		while (i < n)
		{
			cout << i << ' ';
			++i;
		}
		cout << endl;


		// do while loop
		i = n;
		do
		{
			cout << i << ' ';
			--i;
		} while (i > 0);

		cout << endl;
	}

	return 0;
}