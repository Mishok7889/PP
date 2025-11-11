#pragma once
#include <cassert>
#include <complex>

template<typename T>
void mult(T& x, T& y, int n)
{
	const T cx = 0.6;
	const T cy = 0.8;
	for (int i = 0; i < n; ++i)
	{
		T sx = x;
		T sy = y;
		x = sx * cx - sy * cy;
		y = sx * cy + sy * cx;
	}
}

template <typename T>
T abs(T x, T y)
{
	return sqrt(x * x + y * y);
}

template<typename T>
complex<T> power(complex<T> z, int n)
{
	complex<T> c(0.6, 0.8);
	assert(norm(c) == 1);
	for (int i = 0; i < n; ++i)
		c*= z;
	return norm(c);
}

template<typename T>
complex<T> one(T x)
{
	T y = sqrt(1 - x * x);
	assert(norm(complex<T>(x, y)) == 1);
	return complex<T>(x, y);
}