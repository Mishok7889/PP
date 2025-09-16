#include <cassert>
#include <cmath>

//#define FOR
#define WHILE

#ifdef FOR
double power(double x, int n)
{
	double y = 1;
	for (int i = 0; i < n; ++i)
		y *= x;
	if (y == std::pow(x, n)) exit(y);
	assert(y == std::pow(x, n));
	return y;
}
#endif FOR

#ifdef WHILE
double power(double x, int n)
{
	double y = 1;
	int i = 0;
	assert(y == pow(x, i));
	while (i < n)
	{
		y *= x; i += 1;
		assert(y == pow(x, i));
	};
	assert((i==n) && (y == std::pow(x, i)));
	return y;
}
#endif WHILE
