#include <stdio.h>
#include <limits.h>

int main() 
{
	//блок "инициализации"
	
	int n;
	int count;
	scanf("%i", &n);

	int min = INT_MAX;
	int max = INT_MIN;
	int min_even = INT_MAX;
	int max_uneven = INT_MIN;
	int typestr = 0;
	int last_numb;
	int flag = 1;

	//основной блок условий

	for(int i = 0; i < n; i++)
	{	
		int a;
		scanf("%i", &a);
		
		if (a < min) {
			min = a;
		}

		if (a > max) {
			count = 0;
			max = a;
		}
		if (a == max) {
			count++;
		}

		if (a % 2 == 0 && a < min_even)
		{
			min_even = a;
		}

		if (a % 2 == 1 && a > max_uneven)
		{
			max_uneven = a;
		}
		if (i != 0) {
			if (a > last_numb)
			{
				typestr++;
			}
			if (a < last_numb)
			{
				typestr--;
			}
			if (a != last_numb)
			{
				flag = 0;
			}
		}
		last_numb = a;
	}
	
	//блок выводов
	
	printf("Min = %i\n", min);

	printf("Max = %i, count = %i\n", max, count);
	
	if (min_even == INT_MAX)
	{
		printf("None ");
	}
	else 
	{
		printf("%i ", min_even);
	}

	if (max_uneven == INT_MIN)
	{
		printf("None\n");
	}
	else
	{
		printf("%i\n", max_uneven);
	}
	if (typestr == n - 1)
	{
		printf("Increasing");
	}
	else if (typestr == -n + 1)
	{
		printf("Decreasing");
	}
	else if (flag == 1)
	{
		printf("Equal");
	}
	else
	{
		printf("None");
	}

}