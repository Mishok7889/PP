#include <iostream>
#include "Local.h"
#include "Global.h"
#include "Static.h"
#include "Optional.h"

namespace util {
    int value = 7;
}

int value = 42;

int main()
{
    inc();
    inc();

    if (auto x = compute(); x > 0)
        std::cout << "Positive: " << x << '\n';
    else
        std::cout << "Non-positive: " << x << '\n';
    if (auto x = compute(); x > 0)
        std::cout << "Positive: " << x << '\n';
    else
        std::cout << "Non-positive: " << x << '\n';
    // x;

    switch (auto code = compute(); code) {
    case 0: std::cout << "OK\n"; break;
    case 1: std::cout << "Error\n"; break;
    }

    int x = 10;
    int y = 20;
    f(x, y);

    {
        int a = 5;
        auto f = [a]() { std::cout << a << '\n'; };
        a = 10;
        f();
    }

    {
        int x = 1;
        auto f = [x]() {
            int x = 2;
            std::cout << "x = " << x << '\n';
            };
        f();
        std::cout << "x = " << x << '\n';
    }
    int a = 10;
    if (auto a = 5; a < 7)
        std::cout << "a = " << a << '\n';
    std::cout << "external a = " << a << '\n';


    auto counter = []() {
        static int c = 0;
        return ++c;
        };

    std::cout << counter() << '\n';
    std::cout << counter() << '\n';

    int n = 5;
    auto f = [&n]() { n += 10; };
    f();
    std::cout << n << '\n';

    /*{
        int n = 5;
        auto f = [n]() { n += 10; };
        f();
        std::cout << n << '\n';
    }*/

    int value = 100;
    std::cout << value << '\n';
    std::cout << ::value << '\n';
    std::cout << util::value << '\n';

    int* p = nullptr;
    {
        int local = 123;
        p = &local;
    }
    std::cout << *p << '\n'; // ??

    {
        if (auto r = get(true); r)
            std::cout << "Result: " << *r << '\n';
        else
            std::cout << "No result\n";

        // std::cout << *r; // ??
    }
}