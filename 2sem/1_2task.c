#include <stdio.h>

int main()
{
	int a[1000];
	int n;
	scanf("%i", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%i", &a[i]);
	}

	int index;
	int number;
	scanf("%i %i", &number, &index);
	index++;


	for (int i = n; i > index; i--) {
		a[i] = a[i - 1];
	}
	a[index] = number;
	n++;


	for (int i = 0; i < n; ++i)
		printf("%i ", a[i]);

	printf("\n");
}
