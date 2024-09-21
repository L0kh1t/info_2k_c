#include <stdio.h>

void bob(int n);

void alice(int n)
{
	n = n * 3 + 1;
	printf("%i\n", n);
	bob(n);
}

void bob(int n)
{
	while (n % 2 == 0) {
		n /= 2;
		printf("%i\n", n);
	}
	if (n != 1) {	
		alice(n);
	}
}


int main()
{
	int n;
	scanf("%i", &n);
	alice(n);
}
