#define _CRT_SECURE_NO_WARNINGS 1
#include "Data.h"
int main()
{
	Date d1;
	d1.Print();
	Date d2(d1);
	d2.Print();
	Date d3 = d1;
	d3.Print();
	d3 += 10;
	d3.Print();
	d3 += 30;
	d3.Print();
	return 0;
}

