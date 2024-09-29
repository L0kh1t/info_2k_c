#include <stdio.h>

void safe_strcpy(char a[], int size_t, const char b[])
{
	for (int i = 0; i < size_t - 1; i++) {
		a[i] = b[i];
	}
}

int main()
{
	char a[10] = "Mouse";
	char b[50] = "LargeElephant";
	int size_t = 10;
	safe_strcpy(a, size_t, b);
	printf("%s", a);
}