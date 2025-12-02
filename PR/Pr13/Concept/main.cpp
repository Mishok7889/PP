#include <iostream>
//#include <algorithm>
#include <vector>
#include <string>
#include <complex>
using namespace std;
#include "Sort.h"

template<typename T>
bool operator<(const complex<T>& a, const complex<T>& b)
{
	return a.real() < b.real();
}

int main() {
	vector<int> l { 2, 1, 3 };
	::sort(l.begin(), l.end());
	for (int a : l)
		cout << a << ' ';
	cout << endl;

	vector<string> s{ "d","a","e","c","f","b" };
	::sort(s.begin(), s.end());
	for (string a : s)
		cout << a << ' ';
	cout << endl;

	vector<complex<double>> c{ {1,2},{3,4},{0,1} };
	::sort(c.begin(), c.end());
	for (complex<double> a : c)
		cout << a << ' ';
	cout << endl;
}