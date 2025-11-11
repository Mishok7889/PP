#include <iostream>
#include <cassert>
using namespace std;
#include "Coding.h"

int main()
{
	char text[] = "What's a nice day today, isn't it?";
	//char text[] = "Tra-ta-ta";
	char* coded = nullptr;
	char* decoded = nullptr;
	char code[] = "code key";
	::code(text, code, coded);
	cout << coded << endl;
	::code(coded, code, decoded);
	cout << decoded << endl;
	assert(strcmp(text, decoded) != -1);
	delete[] coded;
	delete[] decoded;

	cout << "========== string version =============" << endl;
	string s(text);
	string key(code);
	string s_coded, s_decoded;
	::code(s, key, s_coded);
	::code(s_coded, key, s_decoded);
	cout << s_decoded << endl;
	assert(s == s_decoded);
	return 0;

};