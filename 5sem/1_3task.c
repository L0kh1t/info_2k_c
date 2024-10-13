#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char** p = (char**)malloc(sizeof(char*));
	*p = (char*)malloc(14 * sizeof(char));
	strcpy(*p, "Cats And Dogs");
	printf("%s\n", *p);
	free(p);
}

