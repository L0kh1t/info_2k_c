#pragma once

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node* next;
	struct node* prev;
};

typedef struct node Node;

struct list
{
	Node* head;
	Node* tail;
	size_t size;
};

typedef struct list List;

List init(size_t n)
{
	List a;
	a.size = n;
	if (n == 0) {
		a.head = NULL;
		a.tail = NULL;
		return a;
	}
	
	a.head = (Node*)malloc(n * sizeof(Node));
	a.head->prev = NULL;
	a.head->next = a.head + 1;
	a.head->value = 0;

	for (int i = 1; i < a.size-1; i++) {
		a.head[i].value = i;
		a.head[i].prev = a.head + i - 1;
		a.head[i].next = a.head + i + 1;
	}

	a.tail = a.head+a.size - 1;
	a.tail->next = NULL;
	if (a.size != 1)
		a.tail->prev = a.head+a.size - 2;
	a.tail->value = 0;
	
	return a;
}

void print(const List* pl)
{
	if (pl->size != 0) {
		printf("List: ");
		Node* a = pl->head;
		while (a != pl->tail) {
			printf("%i ", a->value);
			a = a->next;
		}
		printf("%i \n", pl->tail->value);
	}
}

void push_back(List* pl, int value)
{
	Node* a = (Node*)malloc((pl->size+1)*sizeof(Node));
	Node* current = pl->head;
	for (int i = 0; i < pl->size; i++) {
		a[i].value = current->value;
		a[i].prev = a +i-1;
		a[i].next = a+i + 1;
		current = current->next;
	}
	free(pl->head);
	pl->head = a;
	pl->size += 1;
	(pl->head + pl->size - 2)->next = pl->head + pl->size-1;
	(pl->head + pl->size - 1)->next = NULL;
	(pl->head + pl->size - 1)->value = value;
	(pl->head + pl->size - 1)->prev = (pl->head + pl->size - 2);

	pl->tail = pl->head + pl->size - 1;
}

int pop_back(List* pl)
{
	int a = pl->tail->value;
	pl->size -= 1;
	(pl->head + pl->size - 1)->next = NULL;
	pl->tail = pl->head + pl->size - 1;
	return a;
}

void push_front(List* pl, int value)
{
	Node* a = (Node*)malloc((pl->size + 1) * sizeof(Node));
	Node* current = pl->head;
	for (int i = 1; i < pl->size; i++) {
		a[i].value = current->value;
		a[i].prev = a + i-1;
		a[i].next = a + i + 1;
		current = current->next;
	}
	a[pl->size].next = NULL;
	a[pl->size].prev = a + pl->size - 1;
	a[pl->size].value = pl->tail->value;
	free(pl->head);

	a->value = value;
	a->next = a + 1;
	a->prev = NULL;
	pl->head = a;
	pl->size++;
	pl->tail = a + pl->size - 1;
}

int pop_front(List* pl)
{
	int a = pl->head->value;
	pl->head = pl->head + 1;
	pl->head->prev = NULL;
	pl->size--;
	return a;
}

Node* erase(List* pl, Node* p)
{
	Node* a = pl->head;
	while (a->next != p) {
		a = a->next;
	}
	if (a->next == pl->tail) {
		pop_back(pl);
		return NULL;
	}
	else {
		a->next = a->next->next;
		a->next->prev = a;
		return a->next;
	}
	pl->size--;
}

void splice(List* plist, Node* p, List* pother)
{
	Node* a = plist->head;
	while (a->next != p)
		a = a->next;
	while (pother->size != 0) {
		Node b;
		b.value= pop_front(pother);
		a->next = b;
		b->next = p;
		b->prev = a;
		p->prev = b;
		a = a->next;
	}
}