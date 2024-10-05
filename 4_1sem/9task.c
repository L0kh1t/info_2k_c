#include <stdio.h>
#include <string.h>
// Тут нужно написать функцию strmax

char* strmax(char** strings, size_t n)
{
    for (int i = 0; i < -1; i++) {
        if (strcmp(*strings[i], *strings[i + 1]) > 0)
            *strings[i + 1] = *strings[i];
    }
    return strings[n - 1];
}

int main()
{
    char a[] = "Cat";
    char b[] = "Mouse";
    char c[] = "Wolf";
    char d[] = "Kangaroo";
    char e[] = "Elephant";

    char* animals[5] = { &a[0], &b[0], &c[0], &d[0], &e[0] };
    char* x = strmax(animals, 5);
    printf("%s\n", x);  // Напечатает Wolf
}
