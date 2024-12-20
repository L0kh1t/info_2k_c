#include <iostream>
#include <vector>
#include <string>
#include <array>

template <typename T1, typename T2>
int hasMoreElements(const T1& cont1, const T2& cont2)
{
	if (cont1.size() > cont2.size())
		return 1;
	else
		return 0;
}

int main()
{
	std::vector<int> a{ 10, 20, 30, 40, 50 };
	std::string b = "Cat";
	std::string c = "Elephant";
	std::array<int, 3> d{ 10, 20, 30 };

	std::cout << hasMoreElements(a, b) << std::endl;  // Должно напечатать 1
	std::cout << hasMoreElements(a, c) << std::endl;  // Должно напечатать 0
	std::cout << hasMoreElements(a, d) << std::endl;  // Должно напечатать 1
}
