#include <iostream>
using namespace std;
// Compare with floating point
int main()
{
	{
		char ch(0);
		while (++ch > 0)
		{
			// cout << (int)ch << endl;
		}
		cout << (int)ch << endl;

		int k(0);
		while (++k > 0) {};
		cout << k << endl;
	}
	{
		unsigned char ch(0);
		while (++ch > 0)
		{
			// cout << (int)ch << endl;
		}
		cout << (int)ch << endl;

		unsigned int k(0);
		while (++k > 0) {};
		cout << k << endl;
	}
}