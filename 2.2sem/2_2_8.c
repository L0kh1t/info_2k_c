#include <stdio.h>

void reverse(int x[], int size)
{
	int c = size / 2 - 1;
	for (int i = 0; i <= c; i++) {
		int d = x[i];
		x[i] = x[size - 1 - i];
		x[size - 1 - i] = d;
	}

}


int main()
{
	int size;
	int array[10];
	scanf("%i", &size);
	for (int i = 0; i < size; i++)
		scanf("%i", &array[i]);
	reverse(array, size);
	for (int i = 0; i < size; i++)
		printf("%i ", array[i]);
}

