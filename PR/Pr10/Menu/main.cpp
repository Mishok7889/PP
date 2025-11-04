#include <iostream>
#include <complex>
using namespace std;
#include "Operator.h"
//Complete the set of operators with other operators,
//and the main function with a dialog for selecting
//the data type and operators over them
int main()
{
	Complex z1{ 1,2 };
	Complex z2{ 3,4 };

	cout << doOper(z1, z2, operator+)<<endl;

	complex<double> u1{ 5, 6 };
	complex<double> u2{ 7, 8 };

	cout << doOper(u1, u2, operator+)<<endl;

	Real<double> x{ 10 };
	Real<double> y{ 20 };
	cout << doOper(x, y, operator+)._x << endl;

	Oper<Complex> Menu[2] = { operator+, operator- };
	cout << "Your choice?";
	int k = 0;
	cin >> k;
	cout << doOper(z1, z2, Menu[k]) << endl;
	return 0;
}