#include <stdio.h>

void set_characters(const char* begin, const char* end, char c)
{
	///int i = 0;
	//char** curent = &begin;
	//while (**curent != *end) {
	//	**curent = c;
	//	i++;
	//	**curent = *(begin + i);
	//}
	int i = 0;
	while (*(begin + i) != *end) {
		*(begin + i) = c;
		i++;
	}
	
}

int main()
{
	char s[] = "Sapere Aude";
	set_characters(&s[2], &s[8], 'b');
	printf('%s\n', s);
	set_characters(&s, &s[4], 'a');
	printf('%s\n', s);
}