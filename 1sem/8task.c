#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("%i %i %i", &a, &b, &c);
	int remain;
	remain = (a+c) % c;
	if (remain == 0) {
		printf("%i ", a);
	}
	for (int i = a + c - remain; i <= b; i += c)
	{
		printf("%i ", i);
	}
}