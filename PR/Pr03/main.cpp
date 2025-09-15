#include <iostream>
using namespace std;
//Home task
//f[n]=f[n-1]+f[n-3]
int Fibonacci(int n)
{
	int f = 1;
	int a = 0;
	int b = 1;
	if (n < 0) throw n;
	if (n == 0) return 0;
	for (int k = 2; k <= n; k++)
	{
		f = a + b;
		a = b;
		b = f;
	}
	return f;
};

int main()
{
	int n;

	try
	{
		cout << "Give your n:";
		cin >> n;
		for (int k=0; k<=n; ++k)
			cout <<k<<':' << Fibonacci(k) << "\n";
	}
	catch (int n)
	{
		cout << "You gave negative " << n << endl;
	}
	return 0;
}