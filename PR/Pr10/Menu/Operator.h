#pragma once
#include <iostream>
using namespace std;

template <typename T>
using Oper = T(*)(const T& x, const T& y);

template <typename T>
T doOper(const T& x, const T& y, Oper<T> f)
{
	return (*f)(x, y);
}
struct Complex
{
	double _re;
	double _im;
};
Complex operator+(const Complex& z1, const Complex& z2)
{
	return { z1._re + z2._re, z1._im + z2._im };
}
Complex operator-(const Complex& z1, const Complex& z2)
{
	return { z1._re - z2._re, z1._im - z2._im };
}

ostream& operator<<(ostream& os, const Complex& z)
{
	return os << z._re << '+' << z._im << 'i';
}

template <typename T>
struct Real
{
	T _x;
};
template <typename T>
Real<T> operator+(const Real<T>& x, const Real<T>& y)
{
	return { x._x + y._x };
}