#include <iostream>
#include "shift.h"
using namespace std;
// Transform DEADBEEF into BEEFDEAD
int main()
{
	cout << hex<<shift2right(0xDEADBEEF, 16) << endl;
}