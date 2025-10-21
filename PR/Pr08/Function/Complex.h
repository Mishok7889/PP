#pragma once

struct Complex
{
	double _re;
	double _im;
};

Complex plus(const Complex z1, const Complex z2);
Complex operator+(const Complex z1, const Complex z2);
