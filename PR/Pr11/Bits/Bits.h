#pragma once
#include <iostream>
using std::cout;
using std::endl;

#include <bitset>
#include <numbers>

const std::bitset<64> bits(const double a)
{
    return std::bitset<64>(*reinterpret_cast<const long long int*>(&a));
}

const std::bitset<32> bits(const float a)
{
    return std::bitset<32>(*reinterpret_cast<const int*>(&a));
}

union Word
{
    unsigned int _k;
    float _x;
    unsigned __int8 _ch[4];
};

void show(const Word w)
{
	cout << std::hex << w._k << endl;
	//cout << std::bitset<32>(w._x) << endl;
	cout << std::bitset<32>(w._k) << endl;
	cout << bits(w._x) << endl;
	for (int i = 3; i >= 0; --i)
	{
		cout << (int)w._ch[i] << ':' << std::bitset<8>(w._ch[i]) << endl;
	};
	for (int i = 3; i >= 0; --i)
	{
		cout << [](unsigned int x, int k) {return x >> 8 * k & 0xFF; }(w._k, i)
			<< endl;
	};
}

