#include <stdio.h>
#include <string.h>


int is_palindrom(char a[])
{
	int size = strlen(a);
	for (int i = 0; i <= size / 2; i++) {
		printf("%c %c\n", a[i], a[size - i-1]);
		if (a[i] != a[size - i-1])
			return 0;
	}
	return 1;
	
}

int main()
{
	char a[10];
	scanf("%s", a);
	int palindrom = is_palindrom(a);
	if (palindrom == 1)
		printf("Yes");
	else
		printf("No");
}