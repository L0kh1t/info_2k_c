#include <iostream>

struct Book
{
    std::string title;
    int pages;
    float price;
};

bool isExpensive(const Book& b)
{
    if (b.price > 1000)
        return true;
    else
        return false;
}

int main()
{
    Book b = { "Kolobok", 100, 99 };
    Book c = { "Harry Potter", 100, 20000 };
    std::cout << isExpensive(b) << '\n';
    std::cout << isExpensive(c) << '\n';
}