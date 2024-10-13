#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book
{
	char title[50];
	int pages;
	float price;
};

typedef struct book Book;

int main()
{
	Book book1 = { "Don Quixote" , 1000, 750.0 };
	Book** p = (Book**)malloc(sizeof(Book*));
	*p = &book1;	
	printf("Book: %s\nPages: %i\nPrice: %f\n", (*p)->title, (*p)->pages, (*p)->price);
	free(p);
}

