#pragma once
#include <iostream>
using std::cout;
using std::endl;


int byvalue(int a);
int byconstvalue(const int a);
int byreference(int & a);
int byconstreference(const int & a);
int byptr(int * a);
int byconstptr(int * const a);
int* byhandler(int ** a);

struct Point
{
	double _x, _y;
};

double show_x(const Point&);
double& show4Change_x(Point &);
const Point& transmit(const Point&);

void swap(int& x, int& y);
void swap(int* x, int* y);

template<typename T>
void swap(T& x, T& y)
{
	T z = x; x = y; y = z;
}
template<typename T>
void swap(T* x, T* y)
{
	T z = *x; *x = *y; *y = z;
}
