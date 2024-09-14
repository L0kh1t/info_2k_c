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
	//
	int index1;
	int index2;
	scanf("%i %i", &index1, &index2);
	for (int i = 0; i < index2 - index1; i++) {
		a[index1 + i] = a[index2 + i];
	}
	n = n - (index2 - index1);
	//
	for (int i = 0; i < n; ++i)
		printf("%i ", a[i]);

	printf("\n");
}
