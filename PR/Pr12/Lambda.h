#pragma once
#include <functional>
#include <iostream>

std::function<void(void)> closureWrapper()
{
	int x = 10;
	return [&x]() {
		std::cout << "Value in the closure: " << x++ << std::endl; };
}
// https://leimao.github.io/blog/CPP-Closure/
std::function<void(void)> closureWrapper1()
{
	int x = 10;
	return [x]() {std::cout << "Value in the closure: " << x << std::endl; };
}

std::function<void(void)> closureWrapper2()
{
	int x = 10;
	return [&x]() {x += 1; std::cout << "Value in the closure: " << x << std::endl; };
}

double pi = 3.1415926;

class CircleArea
{
public:
	CircleArea()
	{
	}
	double operator() (double r) const
	{
		return pi * r * r;
	}
};
