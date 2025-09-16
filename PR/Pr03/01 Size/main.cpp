#include <iostream>
#include "Size.h"
using namespace std;
// Check size for other aritmetic types
int main()
{
	short s(1); size(s);
	int i(1); size(i);
	long int li(1); size(li);
	long long int lli(1); size(lli);
	return 0;
}