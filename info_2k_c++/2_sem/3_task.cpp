//#pragma once

#include <iostream>
#include <iomanip>

class Number
{
private:
    static const int base = 100;

    char* data;
    std::size_t size;
    std::size_t capacity;

public:

    Number()
    {
        capacity = 1;
        data = new char[capacity];
        data[0] = 0;
        size = capacity;
    }
    Number(const Number& n)
    {
        capacity = n.capacity;
        size = n.size;
        data = new char[capacity];
        for (int i = 0; i < size; ++i)
            data[i] = n.data[i];

    }
    Number(const std::string& str)
    {
        std::string str1 = str;
        capacity = str1.size()/2 + str1.size()%2;
        data = new char[capacity];
        bool flag = false;
        if (str1.size() % 2 != 0)
            str1 = "0" + str1;

        for (int i = 0; i < capacity; ++i)
        {
            int num = (str1[2 * i] - '0') * 10 + (str1[2 * i + 1] - '0');
            data[capacity - i - 1] = num;
        }
        size = capacity;

    }
    Number(int a)
    {
        // Находим размер необходимой памяти под это число
        int temp = a;
        capacity = 0;
        while (temp != 0)
        {
            temp /= base;
            capacity += 1;
        }

        // Отдельно обрабатываем случай, когда число равно 0
        if (capacity == 0)
            capacity = 1;

        // Выделяем память в куче и записывем число a в массив data
        data = new char[capacity];

        for (int i = 0; i < capacity; ++i)
        {
            data[i] = a % base;
            a /= base;
        }

        // В данном случае размер будет равен вместимости
        size = capacity;
    }

    ~Number()
    {
        // Освобождаем память в куче
        delete[] data;
    }


    friend std::ostream& operator<<(std::ostream& stream, const Number& num);
    friend Number operator+(const Number& x, const Number& y);
};

std::ostream& operator<<(std::ostream& stream, const Number& num)
{
    // Печатаем самый большой разряд
    stream << static_cast<int>(num.data[num.size - 1]);

    // Печатаем остальные разряды с заполнением нулями до 2-х цифр
    // setfill и setw используются для того, чтобы замостить ноликом, элемент будет меньше чем 10.
    for (std::size_t i = 0; i < num.size - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << static_cast<int>(num.data[num.size - 2 - i]);

    return stream;
}

Number operator+(const Number& x, const Number& y)
{
    Number result;
    char* current_data = (x.size >= y.size) ? x.data : y.data;
    result.size = (x.size >= y.size) ? x.size : y.size;
    std::size_t min_size = (x.size >= y.size) ? y.size : x.size;
    result.capacity = result.size + 1;
    int memory = 0;
    result.data = new char[result.capacity];
    for (int i = 0; i < min_size; i++)
    {
        int numb = x.data[i] + y.data[i] + memory;
        result.data[i] = (numb+100)%100;
        memory = numb/100;
    }
    for (int i = min_size; i < result.size; i++)
    {
        int numb = current_data[i] + memory;
        result.data[i] = numb%100;
        memory = numb / 100;
    }
    if (memory)
    {
        result.size++;
        result.data[result.size - 1] = 1;
    }
    return result;
}



Number& operator+=(Number& x, const Number& y)
{
    x = x + y;
    return x;
}

int main()
{
    Number x = 124;
    Number y = 18632;
    std::cout << x << " " << y << std::endl;
    Number z = x + y;
    std::cout << z << '\n';
    x += y;
    std::cout << x;
}