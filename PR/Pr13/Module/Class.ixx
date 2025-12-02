// Module Class C++20
// Definition
module;
#include <iostream>

export module Class;
using namespace std;


namespace Class {
	export template <class T>
	class Foo
	{
	private:
		T _k;
		bool check() const;
		T* _pk;
	public:
		Foo(T k = 0) :_k(k), _pk(&_k) {}
		T& k() { return _k; }
		const T& k() const { return _k; }
		const T* addr() const { return &_k; }
		T* pk() const { return _pk; }
		~Foo() {}
	};
	
	export template<class T>
		ostream& operator<<(ostream& os, const Foo<T>& foo)
	{
		return os << '(' << foo.k() << ", &_k " << foo.addr() << ':' << foo.pk() << ')';
	}
};
