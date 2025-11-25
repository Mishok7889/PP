#pragma once
#include <array>
#include <vector>

void fill(int a[]) {
    for (int i = 0; i < 5; ++i) a[i] = i * i;
}
// Suggest realization
void fill(std::array<int, 5>& a);
void fill(std::vector<int>& v);

void f(int a[]) {
	std::cout << sizeof(a) << std::endl;
}

std::vector<int> v{ 1,2,3 };
	decltype(v[0]) x = v[0];

