#pragma once
#include <iostream>
using namespace std;

template<typename T>
T lft2rght(int n)
{
	T s= 1;
	T sign = 1;
	for (int k = 2; k <= n; ++k)
	{
		s += -sign / k;
		sign = -sign;
	}
	return s;
}

template<typename T>
T lft(int n)
{
	T s1 = 1;
	T s2 = 0;

	for (int k = 3; k <= n; k += 2)
	{
		s1 += 1.0 / k;
	}

	for (int k = 2; k <= n; k+=2)
	{
		s2 += 1.0/ k;
	}
#ifdef NDEBUG
	cout << s1 << ':' << s2 << endl;
#endif
	return s1-s2;
}

template<typename T>
T rght2lft(int n)
{
	T s = 0;
	T sign = 1;
	for (int k = n; k >=1; --k)
	{
		s+= -sign / k;
		sign = -sign;
	}
	return s;
}
template<typename T>
T rght(int n)
{
	T s1 =0;
	T s2 = 0;

	for (int k = n-1; k >=1 ; k -= 2)
	{
		s1+= 1.0 / k;
	}

	for (int k = n; k >=2 ; k -= 2)
	{
		s2 += 1.0 / k;
	}
#ifdef NDEBUG
	cout << s1 << ':' << s2 << endl;
#endif
	return s1 - s2;
}