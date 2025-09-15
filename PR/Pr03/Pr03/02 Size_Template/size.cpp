#include <iostream>
using namespace std;

template <class T> int sizeT(T x)
{
	return sizeof(T);
}

int main()
{
	long l;
	int i;
	cout<<sizeT(l)<<endl;
	cout<<sizeT(i)<<endl;
	return 0;
}
