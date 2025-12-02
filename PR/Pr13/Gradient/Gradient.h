#pragma once
#include <complex>
using namespace std;

double f(double x, double y);
double gx(double x, double y);
double gy(double x, double y);
// Built in functions
void gradient_descent_f(double* x, double* y, double s, double eps);
// Polysemy functions, pointer parameters
void gradient_descent(double* x, double* y, double s, double eps,
	double(*f)(double, double),
	double(*gx)(double, double),
	double(*gy)(double, double));
// Polysemy functions, reference parameters
void gradient_descent(double& x, double& y, double s, double eps,
	double(*f)(double, double),
	double(*gx)(double, double),
	double(*gy)(double, double));

// Universal solution
template <typename Value, typename T1, typename T2, typename F, typename G>
auto gradient_descent(Value u, T1 s, T2 eps, F f, G g)
{
	auto val = f(u), delta = val;
	do {
		u -= s * g(u);
		auto new_val = f(u);
		delta = abs(new_val - val);
		val = new_val;
	} while (delta > eps);
	return u;
}

struct R2 {
	double _x=0, _y=0;
public:
	R2(double x, double y) :_x(x), _y(y) {}
	double x() const
	{
		return _x;
	}
	double y() const
	{
		return _y;
	}
	double& x()
	{
		return _x;
	}
	double& y()
	{
		return _y;
	}
};

inline ostream& operator<<(ostream& os, const R2& u)
{
	return os << '(' << u.x() << ',' << u.y() << ')';
}

const R2 inline operator*(double s, const R2& u)
{
	return R2{ s * u.x(), s * u.y() };
}

inline R2&  operator-=(R2& u, const R2& v)
{
	u.x() -= v.x();
	u.y() -= v.y();
	return u;
}

struct R3 {
	double _x = 0, _y = 0, _z = 0;
public:
	R3(double x, double y, double z) :_x(x), _y(y) ,_z(z){}
	double x() const
	{
		return _x;
	}
	double y() const
	{
		return _y;
	}
	double z() const
	{
		return _z;
	}
	double& x()
	{
		return _x;
	}
	double& y()
	{
		return _y;
	}
	double& z()
	{
		return _z;
	}
};

inline ostream& operator<<(ostream& os, const R3& u)
{
	return os << '(' << u.x() << ',' << u.y()<<','<<u.z() << ')';
}

const R3 inline operator*(double s, const R3& u)
{
	return R3{ s * u.x(), s * u.y(), s*u.z() };
}

inline R3& operator-=(R3& u, const R3& v)
{
	u.x() -= v.x();
	u.y() -= v.y();
	u.z() -= v.z();
	return u;
}