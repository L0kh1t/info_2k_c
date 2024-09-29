#include <stdio.h>

unsigned long long placements(int n, int k)
{
	unsigned long long result = 1;
	for (int i = k-n+1; i <= k; i++)
		result *= i;
	return result;
}

int main()
{
	int n, k;
	scanf("%i %i", &k, &n);
	printf("%llu", placements(n, k));
}