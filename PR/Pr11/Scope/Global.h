#pragma once
#include <iostream>
int x = 1;

void f1() {
    int x = 2;
    {
        int x = 3;
        std::cout << x; // 3, не шукає зовнішні
    }
}

void f() 
{
    int count = 42;

    for (int count = 0; count < 3; ++count) // тіньова змінна!
        std::cout << count << '\n';
    std::cout << "count = " << count << '\n'; // 42, не 3
    int total = 100;

    for (int total = 0; total < 5; ++total)
        std::cout << total << " ";
    std::cout << total;

}

extern int conflict;
