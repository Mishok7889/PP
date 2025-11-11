#pragma once

int count = 0;
int compute()
{
	if (count++ % 2)
		return 1;
	else
		return -1;
 }

void f(int x, int y) {
	std::cout << x + y<<std::endl; 
}

int conflict = 1;