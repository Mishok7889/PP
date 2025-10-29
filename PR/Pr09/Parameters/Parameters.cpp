#include "Parameters.h"

int byvalue(int a)
{
	a++;
	cout<<"\t\t"<<&a<<':'<<a<<'/';
	return a;
}
int byconstvalue(const int a)
{
	cout<<"\t\t"<<&a<<':'<<a<<'/';
//	a++;
	return a;
}
int byreference(int & a)
{
	a++;
	cout<<"\t\t"<<&a<<':'<<a<<'/';
	return a;
}
int byconstreference(const int & a)
{
	cout<<"\t\t"<<&a<<':'<<a<<'/';
//	a++;
	return a;
}
int byptr(int * a)
{
	(*a)++;
	cout<<"\t\t"<<a<<':'<<*a<<'/';
	return * a;
}
int byconstptr(int * const a)
{
	cout<<"\t\t"<<&a<<':'<<a<<':'<<*a<<'/';
//	*a++;
//	a++;
	return * a;
}
int* byhandler(int ** a)
{
	cout<<"\t\t"<<&a<<':'<<a<<':'<<*a<<'>'<<endl;
//	(*a)++;
	a++;
	cout<<"\t\t"<<&a<<':'<<a<<':'<<*a<<'>';
	return * a;
}

double show_x(const Point& v)
{
	return v._x;
}
double& show4Change_x(Point & v)
{
	return v._x;
}
const Point& transmit(const Point& v)
{
	return v;
}

void swap(int& x, int& y)
{
	int z=x; x=y; y=z;
	return;
}
void swap(int* x, int* y)
{
	int z=*x; *x=*y; *y=z;
	return;
}
