#include <cstring>
#include <iostream>
using namespace std;
#include "Coding.h"

void modifyKey(const char* code, char*& modified)
{
	modified = new char[strlen(code) + 1];
	modified[strlen(code)] = 0;
	for (unsigned int i = 0; i < strlen(code); ++i)
	{
		modified[i] = code[i] | 0x80;
	}
}
void code(const char* what, const char* how, char*& res)
{
	res = new char[strlen(what) + 1];
	res[strlen(what)] = 0;
	char* modified = nullptr;
	modifyKey(how, modified);
	for (unsigned int i = 0; i < strlen(what); ++i)
	{
		res[i] = what[i] ^ modified[i % strlen(modified)];
	}
	delete[] modified;
}

void code(const string& what, const string& how, string& res)
{
	res = what;
	string key;
	modifyKey(how, key);
	for (unsigned int i = 0; i < what.length(); ++i)
	{
		res[i] = what[i] ^ key[i % key.length()];
	}
}
void modifyKey(const string& key, string& modified)
{
	modified = key;
	for (unsigned int i = 0; i < key.length(); ++i)
	{
		modified[i] = key[i] | 0x80;
	}
}