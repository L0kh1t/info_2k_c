#include <stdio.h>

int main()
{
	char a[10];
	char b[10];
	int i = 0;
	scanf("%s %s", a, b);
	while (a[i] != 0 && b[i] != 0) {
		printf("%c%c", a[i], b[i]);
		i++;
	}
	if (a[i] == 0) {
		while (b[i] != 0) {
			printf("%c", b[i]);
			i++;
		}
	}
	
	else {
		while (a[i] != 0) {
			printf("%c", a[i]);
			i++;
		}
	}	
}