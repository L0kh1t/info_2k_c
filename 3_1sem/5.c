#include <stdio.h>
#include <math.h>
int main()
{
	int x1, x2, y1, y2, r1, r2;
	scanf("%i %i %i %i %i %i", &x1, &y1, &r1, &x2, &y2, &r2);
	float lens = sqrt((pow(x2 - x1, 2) + pow(y2 - y1, 2)));
	if (lens > r1 + r2)
		printf("Do not intersect");
	else if (fabs(lens - r1 - r2) < pow(10, -5))
		printf("Touch");
	else
		printf("Intersect");
}