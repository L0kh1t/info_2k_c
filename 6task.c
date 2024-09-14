#include <stdio.h>

int main()
{
	int size = 0;
	int n;
	int a, b;
	scanf("%i %i", &a, &b);
	int max;
	int min;
	if (a > b)
	{
		max = a;
		min = b;
	}
	else 
	{
		max = b;
		min = a;
	}
	for (int i = min; i <= max; i++) 
	{
		int c = i;
		int count = 0;
		while (c != 1)
		{
			count++;
			if (c % 2 == 1)
			{
				c = 3 * c + 1;
			}
			else
			{
				c = c / 2;
			}
		}
		if (count > size)
		{
			size = count;
			n = i;
		}
	}
	printf("%i %i", n, ++size);
}