#include <stdio.h>

float yearfrac(int year, int day)
{
	if (year % 4 != 0)
		return (float)day / 365;
	else
		return (float)day / 366;
}

int main()
{
	int year, day;
	scanf("%i %i", &year, &day);
	printf("%f", yearfrac(year, day));
}
