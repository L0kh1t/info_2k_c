#include <stdio.h>

void trim_after_first_space(char str[])
{
	int size = 0;
	while (str[size] != 32)
		size++;
	str[size] = 0;
}

int main()
{
	char a[] = "Cats and Dogs";
	printf("%s\n", a);
	trim_after_first_space(a);
	printf("%s\n", a);
}
