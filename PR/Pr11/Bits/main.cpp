#include <iostream>
#include "Bits.h"
using std:: cout;
using std::endl;
// Define template show() for word and double word
int main()
{
	cout << bits(std::numbers::pi) << endl;
	//cout << std::bitset<64>(std::numbers::pi) << endl;
	cout << "   " << bits(3.14159f) << endl;
	Word floatpi;
	floatpi._x = 3.14159f;
	/*cout << "   " << std::bitset<32>(floatpi._k) << endl;
	cout << "   " << bits(floatpi._x) << endl;*/
	show(floatpi);
	
	cout << "==============" << endl;
	Word w{ 0xDEADBEAF };
	show(w);
	return 0;
}
