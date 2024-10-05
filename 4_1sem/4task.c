#include <stdio.h>

void mult2a(int* p, size_t n)
{
	for (int i = 0; i < n; i++)
		*(p + i) = *(p + i) + *(p+i);
}

void mult2b(int* p, size_t n)
{
	for (int i = 0; i < n; i++)
		p[i] *= 2;
}

int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[5] = { 1, 2, 3, 4, 5 };
	mult2a(&a[0], 5);
	mult2b(&b[0], 5);
	for (int i = 0; i < 5; i++)
		printf("a = %i\n", a[i]);
	for (int i = 0; i < 5; i++)
		printf("b = %i\n", b[i]);
}