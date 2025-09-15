#include <iostream>
using namespace std;
#include "Power.h"
#include "GCD.h"
#include "mod.h"

int main()
{
	double x = 2;
	int k = 10;
	// Two way of power
	cout << x << '^' << k << '=' << power(x, k) << endl;

	// gcd with an invariant function
	cout << gcd(125, 240) << endl;

	// Варто замінити assert  на try{} catch
	// m == n * q + r && r < n
	int n, m;
	try
	{
		cout << "Give your n, m:"; cin >> n >> m;
		if (n <= 0 || m < 0) throw 0;
		cout << "OK" << "\n";
	}
	catch (int)
	{
		cout << "Pls check n & m: "<<n<<',' << m << endl;
	}

	cout << m << '%' << n << "==" << mod(m, n) << endl;
}