#include <cmath>

double exp(double x, int n)
{
	double a = 1;
	double s = a;
	for (int k = 1; k <= n; ++k)
	{
		a *= x / k;
		s += a;
	}
	return s;
}

double Gauss(double x, double eps)
{
	double a = x;
	int k = 1;
	double s = a;
	while (abs(a) > eps)
	{
		// a_(k) = a_(k-1) * ( -x^2 / k )
		a *= -x * x / k;
		s += a / (2 * k + 1);
		k += 1;
	}
	return s;
}
