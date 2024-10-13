#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	//1
	char* p = (char*)malloc(10 * sizeof(char));
	strcpy(p, "Elephant");
	printf("%s\n", p);
	free(p);
}

