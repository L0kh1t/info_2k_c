#include <stdio.h>

int main()
{
	int a[1000];
	int n, m;
	int result = 0;
	scanf("%i %i", &n, &m);
	for (int i = 0; i < n * m; i++) {
		scanf("%i", &a[i]);
	}
	for (int j = 0; j < m; j++)
	{
		for (int i = j; i < m * n; i += m) {
			result += a[i];
		}
		printf("%i ", result);
		result = 0;
	}
}