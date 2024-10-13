#include <stdio.h>
#include <stdlib.h>

int main()
{
	//1
	int* p = (int*)malloc(10 * sizeof(int));
	*p = 123;
	printf("%i\n", *p);
	free(p);
}