#include <iostream>
#include <string>

//1 способ
/*
template<typename T>
T triple(const T& x)
{
	return x + x + x;
}
*/

//2 способ
/*
std::string operator*(int n, std::string s)
{
	std::string str = "";
	for (int i = 0; i < n; i++)
	{
		str += s;
	}
	return str;
}

template<typename T>
T triple(const T& x)
{
	return x + x + x;
}
*/

//3 способ
std::string triple(std::string& str)
{
	return str + str + str;
}

template<typename T>
T triple(const T& x)
{
	return x + x + x;
}

int main()
{
	int a = 10;
	std::cout << triple(a) << std::endl;  // Сработает, напечатает 30

	std::string b = "Cat";
	std::cout << triple(b) << std::endl;  // Ошибка, нельзя число 3 умножать на std::string
	// Нужно чтобы напечаталось CatCatCat
}
