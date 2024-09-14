#include <stdio.h>
#include <limits.h>
int main()
	
{
	int n;
	scanf("%i", &n);
	int count = 0;
	int max = INT_MIN;
	while (n != 1)
	{
		if (n > max)
		{
			max = n;
		}
		printf("%i ", n);
		count++;
		if (n % 2 == 1) 
		{
			n = 3*n + 1;
		}
		else
		{
			n = n / 2;
		}
		
	}
	printf("%i\n", 1);
	printf("Length = %i, Max = %i", ++count, max);
}