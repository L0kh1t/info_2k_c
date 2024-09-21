#include <stdio.h>

int main()
{
	int a[20][20];
	int n; 
	int m;
	int c;
	int count = 0;
	scanf("%i %i", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%i", &a[i][j]);
		}
	}

	printf("\n");

	for (int j = 0; j < m; j++) {
		for (int d = 0; d < n; d++) {
			for (int i = 0; i < n - 1 - count; i++) {
				if (a[i][j] > a[i + 1][j]) {
					c = a[i + 1][j];
					a[i + 1][j] = a[i][j];
					a[i][j] = c;
				}
			}
			count++;
		}
		count = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%i ", a[i][j]);
		printf("\n");
	}
}