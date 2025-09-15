int max_char()
{
	signed char c = 1;
	int k = 0;
	while (c > 0)
	{
		++k;
		c = c + 1;
	}
	return k;
}

int size_char()
{
	char c = 1;
	int k = 0;
	while (c)
	{
		++k;
		c = c<<1;
	}
	return k;
}

// x[0] = 1;
// d[0] = 1;
// 
//x[k]=x[0]+1./d[k];
// d[k]=d[k-1]/base;
//while (x[k]>x[0])

int prec(float base)
{
	float x0 = 1;
	float x= 1;
	float d = 1;
	
	int i = 0;
	do
	{
		d = d / base;	
		x = x0 + d;
		++i;
	} while (x>x0);
	return i-1;
}