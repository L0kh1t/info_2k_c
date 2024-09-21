#include <stdio.h>

int trib(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	else {
		int tribo_numb[40] = { 0, 0, 1 };
		n += 1;
		for (int i = 3; i < n; i++) {
			tribo_numb[i] = tribo_numb[i - 3] + tribo_numb[i - 2] + tribo_numb[i - 1];
		}
		return tribo_numb[n - 1];
	}
}

int main()
{
	int n;
	scanf("%i", &n);
	printf("%i", trib(n));
}
