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
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= 0) {
			a[count] = a[i];
			count++;
		}
	}
	n -= count;
	//
	for (int i = 0; i < n; ++i)
		printf("%i ", a[i]);

	printf("\n");
}
