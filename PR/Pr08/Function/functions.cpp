int gcd(int m, int n)
{
	while (m != n)
		(m > n ? m -= n : n -= m);
	return m;
}
int gcd1(int m, int n)
{
	while (m != n)
		if (m > n)
			m -= n;
		else
			n -= m;
	return m;
}
int gcd2(const int m0, const int n0)
{
	int m = m0;
	int n = n0;
	while (m != n)
		if (m > n)
			m -= n;
		else
			n -= m;
	return m;
}
int gcd4(const int& m0, const int& n0)
{
	int m = m0;
	int n = n0;
	while (m != n)
		if (m > n)
			m -= n;
		else
			n -= m;
	return m;
}

int max(int a, int b)
{ 
	return (a > b) ? a : b; 
}