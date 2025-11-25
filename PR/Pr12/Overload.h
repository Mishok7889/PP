#pragma once
#include <iostream>

void f(int) {
	std::cout << "int" << std::endl;
}
void f(double) {
	std::cout << "double" << std::endl;
}
//
//void f(long long) {
//	std::cout << "long long" << std::endl;
//}

template<class T>
auto print(T x, int) -> decltype(std::cout << x, void()) {
	std::cout << "Printable: " << x << "\n";
}

template<class T>
void print(T, ...) {
	std::cout << "Not printable\n";
}

#include <iostream>
#include <vector>
#include <type_traits>

// --- SFINAE detector ---
template<class T>
auto has_value_type(int) -> typename T::value_type;

template<class>
auto has_value_type(...) -> void;

// --- Helper to detect presence ---
template<class T>
using has_value_type_t = decltype(has_value_type<T>(0));

template<class T>
constexpr bool has_value_type_v =
!std::is_same_v<has_value_type_t<T>, void>;

template<class T> std::enable_if_t<std::is_class_v<T>> h(T) {
	std::cout << "class\n";
}
template<class T> void h(...) {
	std::cout << "non class\n";
}
