#include <stdio.h>
#include <math.h>
int main() 
{
	int n;
	scanf("%i", &n);
	for(int i = 1; i <= n; i++)
	{
		printf("%3i -> %3i -> %3i\n", i, i*i, i*i*i);
	}
}