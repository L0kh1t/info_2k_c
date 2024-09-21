#include <stdio.h>

void print_binary(int x)
{
	if (x > 1) {
		print_binary(x / 2);
		printf("%i", x % 2);
	}
	else
		printf("%i", x);
}

int main()
{
	int x;
	scanf("%i", &x);
	print_binary(x);
}
