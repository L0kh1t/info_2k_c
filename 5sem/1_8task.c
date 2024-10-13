#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book
{
	char* title;
	int pages;
	float price;
};

typedef struct book Book;

int main()
{
	Book* p = (Book*)malloc(sizeof(Book));
	p->title = (char*)malloc(12 * sizeof(char));
	strcpy(p->title, "Don Quixote");
	p->pages = 1000;
	p->price = 750.0;
	printf("Book: %s\nPages: %i\nPrice: %f\n", p->title, p->pages, p->price);
	free(p->title);
	free(p);
}
