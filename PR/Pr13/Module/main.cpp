#include <iostream>

import math;
import Class;

using namespace std;
using namespace Class;

int main()
{
    using namespace math;
    long n = 982'451'653;
    cout << n << " is " << (is_prime(n) ? "" : "not ") << "a prime number" << endl;
    
    // Error: max_check not exported
    // cout << "max_check(982'451'653) is " << max_check(982'451'653) << "\n";


    /*Class::*/Foo<int> foo(1);
    cout << foo<<endl;
    /*Class::*/Foo<int> foo1(foo);
    cout << foo1 << endl;

    return 0;
}