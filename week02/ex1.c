#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	int a;
	float b;
	double c;
	a = INT_MAX;
	b = FLT_MAX;
	c = DBL_MAX;
	
	printf("Size of int \t%lu and maximum value is \t%d\n", sizeof(a), a);
	printf("Size of float \t%lu and maximum value is \t%f\n", sizeof(b), b);
	printf("Size of double \t%lu and maximum value is \t%f\n", sizeof(c), c);

	return 0;
}