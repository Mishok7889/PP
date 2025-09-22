#pragma once
#include <iostream>
#include <string>
//using namespace std;

template<typename T>
std::string type(T x)
{
	return typeid(x).name();
}

template <typename T>
struct wrap {};

template<typename T>
std::string my_type_info()
{
	return typeid(wrap<T>).name();
}
