#include <cassert>
int gcd_rec(int m, int n)
{
	if (m == n)
		return m;
	if (m > n)
		return gcd_rec(m - n, n);
	return gcd_rec(m, n - m);
}

int gcd(int m, int n)
{	
	while (m != n)
		if (m > n)
		{
			assert(gcd_rec(m, n) == gcd_rec(m - n, n));
			m -= n;
		}
		else
		{
			assert(gcd_rec(m, n) == gcd_rec(m, n - m));
			n -= m;
		}
	return m;
}
