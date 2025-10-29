#include "Parameters.h"
#include "Complex.h"
#include <complex>

// Develop a function resize() for increasing the space of an array
// Develop a function for dividing an array into two parts 
// Develop functions show_y, show4Change_y
// Combine both functions show_x and show_y in a single one
// Combine both functions show4Change_x and show4Change_y in one

int main()
{
	int x =1;
//1
	cout<<"by value\t"<<&x<<':'<<x<<endl;
	cout<<byvalue(x)<<':';
	cout<<x<<endl;
//2
	cout<<"by const value\t"<<&x<<':'<<x<<endl;
	cout<<byconstvalue(x)<<':';
	cout<<x<<endl;
//3
	cout<<"by reference\t"<<&x<<':'<<x<<endl;
	cout<<byreference(x)<<':';
	cout<<x<<endl;
//	Compare
	x=1;
	cout<<byreference(x)<<':'<<x<<endl;
//4
	cout<<"by const ref\t"<<&x<<':'<<x<<endl;
	x=1;
	cout<<byconstreference(x)<<':';
	cout<<x<<endl;
//5
	int * px = new int[2];
	px[0]=1;
	px[1]=100;
	cout<<"by pointer\t"<<px<<':'<<*px<<endl;
	cout<<byptr(px)<<':';
	cout<<px<<':'<<*px<<endl;
//6
	int *const pc= new int (1);
	*pc = 2;
	*pc=1;
	cout<<"by const ptr\t"<<pc<<':'<<*pc<<endl;
	cout<<byconstptr(pc)<<':';
	cout<<pc<<':'<<*pc<<endl;
//7
	px[0]=1;
	px[1]=100;
	cout<<"by handler\t"<<&px<<':'<<px<<':'<<*px<<endl;
	cout<<byhandler(&px)<<':'<<endl;
	cout<<"\t\t"<<&px<<'*'<<px<<':'<<*px<<endl;

	Point u ={1,2};

	cout<< show_x(u)<<endl;
	show4Change_x(u)=100;
	cout<< show_x(u) <<endl;
	cout<<transmit(u)._y<<endl;
	// What is wrong? Correct it
	// transmit(u)._y = 200;

	{
		int m = 1;
		int n = 2;
		swap(m, n);
		cout << m << ':' << n << endl;
		swap(&m, &n);
		cout << m << ':' << n << endl;
		double x = 1;
		double y = 2;
		swap(x, y);
		cout << x << ':' << y << endl;
		swap(&x, &y);
		cout << x << ':' << y << endl;
		// What is wrong? Can be corrected?
		/*double*p = nullptr;
		swap(p, &y);*/
	}

	Complex z1{ 1,2 };
	Complex z2{ 3,4 };
	f(z1, z2);
	g(z1, z2);
	h(&z1, &z2);
	{
		DComplex z1{ 1,2 };
		DComplex z2{ 3,4 };
		f(z1, z2);
		g(z1, z2);
		h(&z1, &z2);
	}

	return 0;
}