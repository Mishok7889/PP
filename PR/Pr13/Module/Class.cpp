// Module Class C++20
// Realization

module;
#include <iostream>
using namespace std;

module Class;

namespace Class
{
	template<class T>
	bool Foo<T>::check() const
	{
		return _pk == &_k;
	}
	/*export template<class T>
	ostream& operator<<(ostream& os, const Foo<T>& foo)
	{
		return os<<'(' << foo.k() <<", &_k "<<foo.addr() << ':' << foo.pk() << ')';
	}*/
}
