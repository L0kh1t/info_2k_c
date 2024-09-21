#include <stdio.h>

int main()
{
	int a[20][20];
	int b[20][20];
	int c[20][20] = {0};
	int n;
	scanf("%i", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%i", &a[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%i", &b[i][j]);
		}
	}
	
	printf("\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%i ", c[i][j]);
		}
		printf("\n");
	}
}