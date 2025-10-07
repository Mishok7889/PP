#include "Array2.h"

void simpleArray()
{
	const int ncol = 4;
	int nrow = 5;
	int(*m)[ncol] = new int[nrow][ncol];
	for (int i = 0; i < nrow; i++)
		for (int j = 0; j < ncol; j++)
			*(*(m + i) + j) = 10 * i + j;
	for (int i = 0; i < nrow; i++)
	{
		for (int j = 0; j < ncol; j++)
			cout << m[i][j] << '\t';
		cout << endl;
	}
}
