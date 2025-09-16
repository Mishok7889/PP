#pragma once
// size.h template for sizeof
#include <iostream>
using namespace std;
#include <typeinfo>

template<typename T>
void size(T x)
{
	cout << typeid(x).name() << ':'
		<< sizeof(x) << endl;
	return;
}
