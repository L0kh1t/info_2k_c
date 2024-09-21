#include <stdio.h>

void print_even(int a, int b)
{
	if ((a % 2)*(a % 2) == 1) {
		for (int i = a + 1; i < b; i += 2) {
			printf("%i ", i);
		}
	}
	else {
		for (int i = a; i < b; i += 2) {
			printf("%i ", i);
		}
	}
}


int main()
{
	int a;
	int b;
	scanf("%i %i", &a, &b);
	print_even(a, b);
}
