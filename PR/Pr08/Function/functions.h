#pragma once
int gcd(int m, int n);
int gcd1(int m, int n);
int gcd2(const int m, const int n);
int gcd4(const int& m, const int& n);

template <typename T>
auto cyclicShiftLeft = [](T x, int n)->T
	{
		return x << n | x >> (sizeof(T)*8 - n);
	};

