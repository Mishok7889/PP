#pragma once
#include <string>
using namespace std;

void code(const char* what, const char* how, char*& res);
void modifyKey(const char* code, char*& mofifed);

void code(const string& what, const string& how, string& res);
void modifyKey(const string& key, string& modified);