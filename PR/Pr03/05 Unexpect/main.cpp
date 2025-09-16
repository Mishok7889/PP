#include <iostream>
#include <cmath>
using namespace std;
#include "exp.h"

int main()
{
	double x = -10;
	int n = 30;
	cout.precision(15);
	for (double t = -1; t >= x; t -= 1)
		cout << t<<':'<<exp(t, n) <<':'<<exp(t) << endl;
	cout<< endl;
	cout << std::exp(x) << endl;
	cout << exp(abs(x),n) << endl;
	cout << std::exp(abs(x)) << endl << endl;
	const double eps = 1.e-6;
	for (double x = 1; x <= 10; x += 1)
		cout << Gauss(x, eps) << endl;
}