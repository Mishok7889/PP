#pragma once
void swap_p(int* a, int* b) { int t = *a; *a = *b; *b = t; }
void swap_r(int& a, int& b) { int t = a; a = b; b = t; }

template<typename T> void swap(T& a, T& b) {
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}
