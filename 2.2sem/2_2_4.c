#include <stdio.h>

int sum_of_digits(int x)
{
	if (x > 10)
	{
		return x % 10 + sum_of_digits(x / 10);
	}
	else
		return x;
}

int main()
{
	int x;
	scanf("%i", &x);
	printf("%i\n", sum_of_digits(x));
}
