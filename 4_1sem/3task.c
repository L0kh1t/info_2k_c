#include <stdio.h>

void cube(float* px) 
{
	*px = *px * *px * *px;
}


int main()
{
	float a;
	scanf("%f", &a);
	cube(&a);
	printf("%f", a);
}