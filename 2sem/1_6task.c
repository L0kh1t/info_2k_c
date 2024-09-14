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
	int even[1000];
	int uneven = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 1) {
			a[uneven] = a[i];
			uneven++;
		}
		else {
			even[i - uneven] = a[i];
		}
	}
	for (int i = uneven; i < n; i++) {
		a[i] = even[i - uneven];
	}
	//
	for (int i = 0; i < n; ++i)
		printf("%i ", a[i]);

	printf("\n");
}
