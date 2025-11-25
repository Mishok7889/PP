#pragma once
#include <iostream>
struct A {
    A() { std::cout << "def\n"; }
    A(const A&) { std::cout << "copy\n"; }
};

void foo(A a) {}          // copy
void bar(const A& a) {}   // no copy

const int& f() {
    int x = 10;
    return x;  // explain
}

void fr(int&& x)
{
    return;
}

namespace lib {

    namespace v1 {
        void hello() { std::cout << "Hello v1\n"; }
    }

    inline namespace v2 {
        void hello() { std::cout << "Hello v2\n"; }
    }

} // namespace lib
