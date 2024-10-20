#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Error checked malloc
void* ecmalloc(size_t n)
{
    void* p = malloc(n);
    if (p == NULL)
    {
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    return p;
}

struct dynarray
{
    int* data;
    size_t size;
    size_t capacity;
};
typedef struct dynarray Dynarray;


void clear(Dynarray* pd)
{
    for (size_t i = 0; i < pd->size; ++i)
        pd->data[i] = 0;
}

void init(Dynarray* pd, size_t initial_size)
{
    pd->size = initial_size;
    pd->capacity = initial_size;
    if (pd->size == 0)
        pd->data = NULL;
    else
        pd->data = (int*)ecmalloc(pd->capacity * sizeof(int));
    clear(pd);
}

void reserve(Dynarray* pd, size_t new_capacity)
{
    if (new_capacity <= pd->capacity)
        return;

    int* new_data = (int*)ecmalloc(new_capacity * sizeof(int));

    for (size_t i = 0; i < pd->size; ++i)
    {
        new_data[i] = pd->data[i];
    }

    free(pd->data);
    pd->data = new_data;
    pd->capacity = new_capacity;
}


void push_back(Dynarray* pd, int x)
{
    static const double growth_factor = 2;
    if (pd->size == pd->capacity)
    {
        size_t new_capacity = (size_t)(growth_factor * pd->capacity);

        if (new_capacity <= pd->size)
            new_capacity = pd->size + 1;

        reserve(pd, new_capacity);
    }
    pd->data[pd->size] = x;
    pd->size += 1;
}


int get(const Dynarray* pd, size_t index)
{
    assert(index >= 0 && index < pd->size);
    return pd->data[index];
}


void set(Dynarray* pd, size_t index, int value)
{
    assert(index >= 0 && index < pd->size);
    pd->data[index] = value;
}


void print(const Dynarray* pd)
{
    printf("dynarray: ");
    for (size_t i = 0; i < pd->size; ++i)
        printf("%i ", pd->data[i]);

    printf("\n");
}

//hometask
int pop_back(Dynarray* pd)
{
    pd->size -= 1;
    return pd->data[pd->size];
}

void resize(Dynarray* pd, size_t new_size)
{
    if (new_size > pd->capacity)
    {
        reserve(pd, new_size);
        for (int i = pd->size; i < pd->capacity + 1; i++)
            pd->data[i] = 0;
    }
    else {
        pd->size = new_size;
    }
}

Dynarray shallow_copy(Dynarray* pd)
{
    Dynarray a;
    a.capacity = pd->capacity;
    a.data = pd->data;
    a.size = pd->size;
    return a;
}

Dynarray deep_copy(const Dynarray* pd)
{
    Dynarray a;
    init(&a, pd->size);
    for (int i = 0; i < pd->size; i++)
        push_back(&a, pd->data[i]);
    return a;
}

void destroy(Dynarray* pd)
{
    free(pd->data);
    pd->data = NULL;
}