#include <iostream>
#include <string>

std::string repeat(int n)
{
	std::string p = "";
	if (n < 1)
		return p;
	std::string str = std::to_string(n);
	std::string result = str;
	for (int i = 1; i < n; i++)
		result += str;
	return result;
}

int main()
{
	std::cout << repeat(5) << std::endl;  // Должно напечатать 55555
	std::cout << repeat(10) << std::endl;  // Должно напечатать 10101010101010101010
	std::cout << repeat(-1) << std::endl;  // Не должно ничего печатать
}
