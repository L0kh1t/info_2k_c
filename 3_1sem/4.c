#include <stdio.h>

int main()
{
	float pi = 0;
	for (int i = 1; i <= 1000000; i++) {
		if (i % 2 == 1)
			pi += 4 / (2 * (float)i - 1);
		else
			pi -= 4 / (2 * (float)i - 1);
	}
	printf("%f", pi);
}