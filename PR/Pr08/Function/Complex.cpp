#include "Complex.h"

Complex plus(const Complex z1, const Complex z2)
{
	return { z1._re + z2._re, z1._im + z2._im };
}