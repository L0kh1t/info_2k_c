#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct book
{
	char* title;
	int pages;
	float price;
};

typedef struct book Book;

void print_book(const Book* book)
{
	printf("Book: %s\nPages: %i\nPrice: %f\n \n", book->title, book->pages, book->price);
}

struct library
{
	Book** books;
	int number_of_books;
};

typedef struct library Library;


void library_create(Library* library, int number_of_books)
{
	library->books = (Book**)malloc(number_of_books * sizeof(Book*));
	library->number_of_books = number_of_books;
}

void library_set(Library library, int pose, char title[], int pages, float price)
{
	library.books[pose] = (Book*)malloc(sizeof(Book));
	library.books[pose]->title = (char*)malloc(12 * sizeof(char));
	library.books[pose]->title = title;
	library.books[pose]->pages = pages;
	library.books[pose]->price = price;
}

const Book* library_get(Library library, int pose)
{
	const Book* p = library.books[pose];
	return p;
}

void library_print(Library library)
{
	for (int i = 0; i < library.number_of_books; i++)
		printf("Book %i: %s\nPages: %i\nPrice: %f\n \n", i+1, library.books[i]->title, library.books[i]->pages, library.books[i]->price);

}

void library_destroy(Library* library)
{
	for (int i = 0; i < library->number_of_books; i++) {
		free(library->books[i]->title);
		free(library->books[i]);
	}
	free(library->books);
	library->number_of_books = 0;
}


int main()
{
	Library a;
	library_create(&a, 3);
	library_set(a, 0, "Don Quixote", 1000, 750.0);
	library_set(a, 1, "Oblomov", 400, 250.0);
	library_set(a, 2, "The Odyssey", 500, 500.0);
	library_print(a);
	print_book(library_get(a, 1));
	library_destroy(&a);
}