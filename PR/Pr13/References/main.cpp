#include "Types.h"
#include <iostream>
int main()
{
    {
        cdouble z(-6, 1);
        cdouble z1(1, 2);
        cout << simple_info<double>() << endl;
        auto x = compose(1.2, true);
        cout << simple_info<decltype(x)>() << ':' << x << endl;
        auto y = compose(1.2, cdouble(1, 2));
        cout << simple_info<decltype(y)>() << ':' << y << endl;
        auto s = compose(string("abc"), '?');
        cout << simple_info<decltype(s)>() << ':' << s << endl;
        auto abs = compose_norms(z, modulo, z1, modulo);
        cout << simple_info<decltype(abs)>() << ':' << abs << endl;
    }
    {
        int k = 10;
        auto r = (k);
        int& rk = k;
        decltype(auto) s = (k);
        cout << &k << ':' << &r << ':' << &s << endl;
        cout << simple_info<decltype(r)>() << endl;
        cout << simple_info<decltype(k)>() << endl;
        cout << simple_info<decltype(s)>() << endl;
        cout << simple_info<decltype(rk)>() << endl;

        cout << my_info<decltype(k)>() << endl;
        cout << my_info<decltype(s)>() << endl;
        cout << my_info<decltype(rk)>() << endl;
        cout << my_info<decltype(r)>() << endl;
        cout << my_info<decltype((k))>() << endl;
        cout << my_info<decltype((rk))>() << endl;
    }
    {
        cout << boolalpha;

        cout << "float to string: "
            << is_convertible< float, string>::value
            << endl;

        cout << "int to <complex<double>: "
            << is_convertible<int, complex<double>>::value
            << endl;

        cout << "complex<double> to int: "
            << is_convertible<complex<double>, int>::value
            << endl;
        double x = 10;
        auto var = foo(x);
        auto var1 = foo1(x);
        //decltype(var)
        // the type of a lambda function is unique and unnamed
        auto f = [](double x)->double {return x; };
        cout << my_info< decltype(f)>() << endl;
        //struct wrap<class <lambda_0131a55b6b924850ac1a04b6ccb2dfa0> >
        decltype(f) g = f;
        cout << my_info< decltype(g)>() << endl;
        //struct wrap<class <lambda_0131a55b6b924850ac1a04b6ccb2dfa0> >
        cout << boolalpha;
        cout << (f(10) == g(10)) << endl;
        cout << (my_info< decltype(f)>() == my_info< decltype(g)>()) << endl;
    }

    {
        int a = 10;
        auto c0 = a;             // type of c0 is int, holding a copy of a
        decltype(auto) c1 = a;   // type of c1 is int, holding a copy of a
        decltype(auto) c2 = (a); // type of c2 is int&, an alias of a

        complex<double> z{ 1,2 };
        decltype(auto) z1 = z;
        cout << my_info<decltype(z1)>() << endl;
        //struct wrap<class std::complex<double> >
        decltype(auto) z2 = (z);
        cout << my_info<decltype(z2)>() << endl;
        //struct wrap<class std::complex<double>&>
    }
    return 0;
}