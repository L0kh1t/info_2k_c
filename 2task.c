#include <stdio.h>

int main()
{
	int a, b, c;
	
	scanf("%i %i %i", &a, &b, &c);

	if ((c == b + 1 && b == a + 1) || (c == b - 1 && b == a - 1))
	{
		printf("Consecutive ");
	}

	if (c > b && b > a)
	{
		printf("Increasing");
	}
	else if(a > b && b > c)
	{
		printf("Decreasing");
	}
	else if(a == b && b == c)
	{
		printf("Equal");
	}
	else 
		printf("None");
	
}