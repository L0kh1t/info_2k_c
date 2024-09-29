#include <stdio.h>
#include <string.h>


int main()
{
	int n;
	int x = 0;
	int y = 0;
	char a[6];
	int step;
	scanf("%i", &n);
	int t = 0;
	while (t != n){
		scanf("%s %i", a, &step);
		if (strcmp("North", a) == 0)
			y += step;
		else if (strcmp("East", a) == 0)
			x += step;
		else if (strcmp("South", a) == 0)
			y -= step;
		else if (strcmp("West", a) == 0)
			x -= step;
		t++;
	}
	printf("%i, %i", x, y);
}
