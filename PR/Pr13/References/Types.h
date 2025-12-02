#pragma once
#include <string>
#include <complex>
//#include <fstream>
using namespace std;

//extern ofstream out;

template <typename T>
std::string simple_info()
{
    return typeid(T).name();
}

template <typename T>
struct wrap {};

// wrap the type since typeid forgets all the qualifiers
template <typename T>
std::string my_info()
{
    return typeid(wrap<T>).name();
}

using namespace std;
using cdouble = complex<double>;


template <typename T1, typename F,
    typename T2, typename G >
    auto compose_norms(T1 a, F f, T2 b, G g)
    -> decltype(f(a) + g(b))
{
    return (f(a) + g(b));
}

inline double modulo(complex<double> z)
{
    return abs(z);
}

template <typename T>
T silly_abs_max(T x, T y)
{
    return abs(x) > abs(y) ? abs(x) : abs(y);
}

template <typename T>
auto abs_max(T x, T y)
{
    return abs(x) > abs(y) ? abs(x) : abs(y);
}

template <typename T1, typename T2>
auto compose(T1 a, T2 b) -> decltype(a + b)
{
    return a + b;
}

inline double foo(double x)
{
    return x;
}

inline auto foo1(double x) -> double
{
    return x;
}

inline double normal(double x)
{
    return exp(-x * x);
}