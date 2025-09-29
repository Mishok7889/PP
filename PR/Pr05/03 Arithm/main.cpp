#include <iostream>
using namespace std;

int main()
{
	// Specifying formats with manipulators:
	cout << "a number in decimal: "
		<< dec << 15 << endl;
	cout << "in octal: " << oct << 15 << endl;
	cout << "in hex: " << hex << 15 << endl;
	cout << "a floating-point number: "
		<< 3.14159 << endl;
	cout << "non-printing char (escape): "
		<< char(27) << endl;

	for (int k = 0; k < 256; k++)
	{
		char i = char(k);
		cout <<':'<< dec << k << ':' << oct << k << ':' << hex << k << '|' << i << dec << ':' << (short)i << endl;

	}

	cout << "============ Increments ===================" << endl;
	char i = char(100);
	int m = i;
	cout << "cout<<i++" << endl;
	cout << m << ':' << i++ << "+1=" << i << endl;
	char ii = char(100);
	cout << "i++;cout<<i;" << endl;
	m = ii;
	cout << m << ':' << ii++ << "+1=";
	cout << ii << endl;

	cout << "dec:";
	cout << dec << (int)ii << endl;

	m = 2;
	cout << "m=2; m++*m++=";
	cout << m++ * m++ << endl;
	cout << "m=" << m << endl;
	m = 2;
	cout << "m=2; (++m)*(++m)=";
	cout << (++m) * (++m) << endl;
	cout << "m=" << m << endl;

	signed char a = 0, b = 1, c = -1;
	bool t = true, f = false;
	cout << "true=" << t << ';' << " false=" << f << endl;

	cout << hex << "a= " << int(a) << " , b=" << int(b) << " , c=" << int(c) << endl;
	cout << "Negation:" << endl;
	cout << "a=" << (a ? true : false) << ":!a=" << (!a ? true : false) << ':';
	cout << hex << "!" << (int)a << "=" << !a << dec << '/' << (int)!a << endl;
	cout << "b=" << (b ? true : false) << ":!b=" << (!b ? true : false) << ':';
	cout << hex << "!" << (int)b << "=" << !b << endl;
	cout << "c=" << (c ? true : false) << ":!c=" << (!c ? true : false) << ':';
	cout << hex << "!" << (int)c << '/' << dec << (int)c << '=' << !c << endl;


	cout << "Konjunction: " << (a && b) << ',' << (b && c) << ',' << (a && c) << endl;
	cout << "Disjunction: " << (a || b) << ',' << (b || c) << ',' << (a || c) << endl;

	cout << "Bit-wise operations" << endl;
	cout << "Negation:" << endl;
	cout << hex << "~" << (int)a << "=" << ~a << dec << '/' << (int)~a << endl;
	cout << hex << "~" << (int)b << "=" << ~b << endl;
	cout << hex << "~" << (int)c << '/' << dec << (int)c << '=' << ~c << endl;

	cout << hex;
	cout << "Konjunction: " << (a & b) << ',' << (b & c) << ',' << (a & c) << endl;
	cout << "Disjunction: " << (a | b) << ',' << (b | c) << ',' << (a | c) << endl;

	unsigned int aa = 0xfbfcfdfe; //0xfafbfcfd;
	cout << dec;
	cout << aa << endl;
	cout << 0xffffffff << endl;
	cout << 0x7fffffff << endl;
	int minus = 0xffffffff;//0x80000000;
	cout << "minus=" << minus << endl;
	cout << 0x80000000 << endl;
	cout << hex;
	cout << aa << endl;
	for (int kk = 0; kk < 32; kk += 8)
	{
		unsigned int t = (aa >> kk) & 0xff;
		cout << t << endl;
	}
	return 0;
}