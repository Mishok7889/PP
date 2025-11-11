#pragma once
#include <string>
#include <typeinfo>

template <typename T>
T max(std::string& s)
{
	T x = 1;
	s = typeid(x).name();
	while (x)
	{	
		x<<=1;
	}
	return x-1;
}

template <typename T>
T size(std::string& s)
{
	T x = 1;
	s = typeid(x).name();
	int k = 0;
	while (x)
	{
		++k;
		x <<= 1;
	}
	return k;
}

