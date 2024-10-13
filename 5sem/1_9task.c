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
	Book** p = (Book**)malloc(3*sizeof(Book));
	
	p[0] = (Book*)malloc(sizeof(Book));
	p[0]->title = (char*)malloc(12 * sizeof(char));
	strcpy(p[0]->title, "Don Quixote");
	p[0]->pages = 1000;
	p[0]->price = 750.0;
	
	p[1] = (Book*)malloc(sizeof(Book));
	p[1]->title = (char*)malloc(12 * sizeof(char));
	strcpy(p[1]->title, "Oblom");
	p[1]->pages = 400;
	p[1]->price = 250.0;

	p[2] = (Book*)malloc(sizeof(Book));
	p[2]->title = (char*)malloc(12 * sizeof(char));
	strcpy(p[2]->title, "The Odyssey");
	p[2]->pages = 500;
	p[2]->price = 500.0;

	printf("Book: %s\nPages: %i\nPrice: %f\n \n", p[0]->title, p[0]->pages, p[0]->price);
	printf("Book: %s\nPages: %i\nPrice: %f\n \n", p[1]->title, p[1]->pages, p[1]->price);
	printf("Book: %s\nPages: %i\nPrice: %f\n \n", p[2]->title, p[2]->pages, p[2]->price);
	
	for (int i = 0; i < 3; i++) {
		free(p[i]->title);
		free(p[i]);
	}
	free(p);
}
