#include <stdio.h>

int* max(int* pa, int* pb)
{
	if (*pa < *pb)
		return pb;
	else
		return pa;
}

int main()
{
    int a = 10;
    int b = 30;
    int c = 20;
    *max(max(&a, &b), &c) += 1;
    printf("%i %i %i\n", a, b, c);  // ���������� 10 31 20
}