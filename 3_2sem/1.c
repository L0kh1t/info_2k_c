#include <stdio.h>
#include <ctype.h>


void solution1(char a)
{
	if ((65 <= a && a <= 90) || (97 <= a && a <= 122))
		printf("Letter");
	else if (48 <= a && a <= 57)
		printf("Digit");
	else
		printf("Other");
}

void solution2(char a)
{
	if (('A' <= a && a <= 'Z') || ('a' <= a && a <= 'z'))
		printf("Letter");
	else if ('0' <= a && a <= '9')
		printf("Digit");
	else
		printf("Other");
}

void solution3(char a)
{
	if (isalpha(a) != 0)
		printf("Letter");
	else if (isdigit(a) != 0)
		printf("Digit");
	else
		printf("Other");
}

int main()
{
	char x;
	scanf("%c", &x);
	solution3(x);
}