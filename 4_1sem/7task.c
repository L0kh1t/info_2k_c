#include <stdio.h>

int exchange(int* pa, int b)
{
	int c = *pa;
	*pa = b;
	return c;
}

int main()
{
	int a = 10;
	printf("%i\n", exchange(&a, 20));
	printf("%i\n", a);
}