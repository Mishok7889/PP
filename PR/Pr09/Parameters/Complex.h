#pragma once
#include <complex>
struct Complex
{
    double _re;
    double _im;
};

inline void f(Complex z1, Complex z2)
{
    z1._re = z2._re;
    z1._im = z2._im;
    return;
}

inline void g(Complex& z1, Complex& z2)
{
    z1._re = z2._re;
    z1._im = z2._im;
    return;
}

inline void h(Complex* z1, Complex* z2)
{
    z1->_re = z2->_re;
    z1->_im = z2->_im;
    return;
}

using DComplex = std::complex< double > ;

inline void f(DComplex z1, DComplex z2)
{
    z1 = z2;
    return;
}

inline void g(DComplex& z1, DComplex& z2)
{
    z1 = z2;
    return;
}

inline void h(DComplex* z1, DComplex* z2)
{
    *z1 = *z2;
    return;
}
