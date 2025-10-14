#include <iostream>
#include <typeinfo>
#include <complex>
#include "Structure.h"
using namespace std;
using std::cout;
int main()
{
	// 1. Reorganize the Collection to minimise its size
	 
	cout << typeid(Collection).name() << endl;
		
	cout << "size of Collection " << sizeof(Collection) << endl;
	cout << "Size of components: " << endl;
	int counter = 0;
	Collection col = { 'a',"tratata",'b',2,4.f,'c',1. };

	cout << typeid(char).name() << "\t\t"<<(long) & col._chr1
		<< ':' << (counter += sizeof(char), sizeof(char)) << endl;
	cout << typeid(char*).name() << "\t\t" << (long)&col._pc
		<<':' << (counter += sizeof(char*), sizeof(char*)) << endl;
	cout << typeid(char).name() << "\t\t" << (long)&col._chr2
		<< ':' << (counter += sizeof(char), sizeof(char)) << endl;
	cout << typeid(short).name() << "\t\t" << (long)&col._si
		<<':'<<(counter += sizeof(short), sizeof(short)) << endl;
	cout << typeid(float).name() << "\t\t" << (long)&col._f
		<<':'<<(counter += sizeof(float), sizeof(float)) << endl;
	cout << typeid(char).name() << "\t\t" << (long)&col._chr3
		<< ':' << (counter += sizeof(char), sizeof(char)) << endl;
	cout << typeid(double).name() << "\t\t" << (long)&col._d
		<<':'<< (counter += sizeof(double), sizeof(double)) <<endl;

	cout << "Total " << counter << endl;

	// 2. Structure assignment

	Complex z1 = { 1,2 };
	Complex z2 = { 3,4 };
	z1 = z2;

	double z1x = z1._re;
	double z1y = z1._im;

	double z2x = z2._re;
	double z2y = z2._im;

	z1x = z2x;
	z1y = z2y;

	f(z1, z2);

	g(z1, z2);

	{
		complex<double> z1 = { 1,2 };
		complex<double> z2 = { 3, 4 };
		z1 = z2;
	}

	// 3. What is wrong with the following code

	BuiltInDoubleArray dba = { new double[100] {1} };
	BuiltInDoubleArray dbb = { new double[200] {2} };

	cout << "BuiltInDoubleArray:\t" << sizeof(BuiltInDoubleArray) << endl;
	cout << "BuiltInIntArray:\t" << sizeof(BuiltInIntArray) << endl;

	double* pa = dba._d;
	double* pb = dbb._d;

	dbb._d = dba._d;
	delete [] dbb._d;
	dbb._d = nullptr;

	delete[]dbb._d;
	dba._d = nullptr;
	
	cout << pa[0] << endl;
	cout << pb[0] << endl;

	// 4. Bit fields

	cout << "Week:\t" << sizeof(Week) << endl;
	cout << "DayStatusLong:\t" << sizeof(DayStatusLong) << endl;
	cout << "DayStatus:\t" << sizeof(DayStatus) << endl;
	cout << "DayStatusShort:\t" << sizeof(DayStatusShort) << endl;

	cout << "Status:\t" << sizeof(Status) << endl;
	cout << "StatusByte:\t" << sizeof(StatusByte) << endl;
	cout << "AnotherStatusByte:\t" << sizeof(AnotherStatusByte) << endl;

	DayStatusLong ex[2];
	cout << "DayStatusLong" << endl;
	cout << sizeof(Week) << ',' << sizeof(DayStatusLong) << ':'
		<< dec << (uint64_t)&ex << ',' << (uint64_t)&ex[1] << endl;
	DayStatus ex1[2];
	cout << "DayStatus" << endl;
	cout << sizeof(Week) << ',' << sizeof(DayStatus) << ':'
		<< dec << (uint64_t)&ex1 << ',' << (uint64_t)&ex1[1] << endl;
	DayStatusShort ex2[2];
	cout << "DayStatusShort" << endl;
	cout << sizeof(unsigned short) << ',' << sizeof(DayStatusShort) << ':'
		<< dec << (uint64_t)&ex2 << ',' << (uint64_t)&ex2[1] << endl;

	cout << "HalfWord:" << sizeof(HalfWord) << endl;

	// 5. Unions

	Word myWord;
	myWord._k = 0xDEADBEEF;

	cout << hex
		<< myWord._word._byte1 << ':'
		<< myWord._word._byte2 << ':'
		<< myWord._word._byte3 << ':'
		<< myWord._word._byte4
		<< endl;

	cout << hex
		<< myWord._word._byte4 << ':'
		<< myWord._word._byte3 << ':'
		<< myWord._word._byte2<< ':'
		<< myWord._word._byte1
		<< endl;

	Word w; w._x = 1;

	int n = 8;

	cout << "Word:" << sizeof(Word)<<endl;
	for (int i = 1; i <= n; i++)
	{
		cout << dec << w._x << ' ' << w._k << '(' << hex << w._k <<')'<< endl;
		cout << hex << w._word._byte4 << ':';
		cout << hex << w._word._byte3 << ':';
		cout << hex << w._word._byte2 << ':';
		cout << hex << w._word._byte1 << endl;

		for (int i = 3; i >= 0; --i)
		{
			cout << (short) w._w[i] << ':';
		}
		cout << endl;

		w._x *= 2;
		cout << "-----------------" << endl;
	}

}