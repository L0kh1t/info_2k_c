#include <stdio.h>
#include <string.h>

void encrypt(char a[], int k)
{
	int reminder;
	int i = 0;
	while (a[i] != 0) {
		if (65 <= a[i] && a[i] <= 90) {
			a[i] += k;
			if (a[i] > 90)
				a[i] -= 26;
		}
		else if (a[i] == 32)
			a[i] = a[i];
		else {
			a[i] += k;
			if (a[i] > 122)
				a[i] -= 26;
		}
		i++;
	}
}

int main()
{
	char str[30];
	int k;
	scanf("%[^\n] %i", str, &k);
	encrypt(str, k);
	printf("%s", str);
}