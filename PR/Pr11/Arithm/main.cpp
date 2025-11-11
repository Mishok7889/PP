#include <iostream>
#include <limits>
#include "Precision.h"
#include "series.h"
#include "Mult.h"
using namespace std;

int main()
{
	//1. Practise makes perfect
	{
		std::string s;

		cout << hex << max<unsigned short int>(s) << '(' << s << ')' << endl;
		cout << dec << size<unsigned short int>(s) << '(' << s << ')' << endl;

		cout << hex << max<unsigned int>(s) << '(' << s << ')' << endl;
		cout << dec << size<unsigned int>(s) << '(' << s << ')' << endl;
		
		cout << hex << max<long long int>(s) << '(' << s << ')' << endl;
		cout << dec << size<long long int>(s) << '(' << s << ')' << endl;

		cout << static_cast<unsigned int>(max<unsigned char>(s)) << '(' << s << ')' << endl;
		cout << (int) size<unsigned char>(s) << '(' << s << ')' << endl;

		
		// Develop templates for signed integral types
	}
	{
		//2.
		//Niklaus Wirth, Systematic Programming, 8.3
		// Compute the sum
		// 1-1/2+1/3-1/4+ � +1/9999 � 1/10000
		//in the following ways :
		//(a)addition of terms from left to right,
		//(b)addition of terms from right to left,
		//(c)separate addition of positiveand negative terms, each from left to right,
		//(d)separate addition of positiveand negative terms, each from right to left.

		//The sum with 30-digit accuracy is 
		//0.693097183059945296917232371458
		cout << "\n==========================" << endl;
		double value = 0.693097183059945296917232371458;
		int n = 10000;

		cout.precision(numeric_limits<float>::digits10);
		cout << value << endl;

		cout << lft2rght<float>(n) << endl;
		cout << rght2lft<float>(n) << endl;
		cout << lft<float>(n) << endl;
		cout << rght<float>(n) << endl;
		cout<<"\n--------------------"<<endl;
		cout.precision(numeric_limits<double>::digits10);
		cout << value << endl;
		cout << lft2rght<double>(n) << endl;
		cout << rght2lft<double>(n) << endl;
		cout << lft<double>(n) << endl;
		cout << rght<double>(n) << endl;
	}
	//3.
	//A measure of the precision of a given floating-point arithmetic is found 
	//in the quantity eps, which is defined as follows :
	//eps = min(x | (1 + x) != 1)
	// Find the measure of precision for float and double
	{
		
	}
	//4. 
	//Niklaus Wirth, Systematic Programming, 8.4
	// Design a program that repeatedly multiplies the complex variable z
	//by the complex constant c = 0.6 + 0.8i

	
	cout << "\nThe measure of precision" << endl;
	{
		cout.precision(numeric_limits<float>::digits10);
		float x = 0.8f;
		float y = 0.6f;
		int n(5000);
		mult(x, y, n);
		float res = abs(x, y);
		cout << res << ':'<<1-res<<endl;
	}
	{
		float x(0.8f);
		int n(5000);
		complex<float> z(one(x));
		float res = norm(power(z, n));
		cout<<res <<':'<< 1 - res << endl;
	}
	
	{
		cout.precision(numeric_limits<double>::digits10);
		double x = 0.8;
		double y = 0.6;
		int n(50000);
		mult(x, y, n);
		double res = abs(x, y);
		cout << res << ':'<<1 - res<<endl;
	}
	
	{
		double x(0.8);
		int n(50000);
		complex<double> z(one(x));
		double res = norm(power(z, n));
		cout << res << ':'<<1 - res<<endl;
	}
	
	
	
	return 0;
}
