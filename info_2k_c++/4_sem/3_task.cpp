#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

template<typename T>
std::pair<T, T> minmax(const std::vector<T>& v)
{
	auto mini = *std::min_element(v.begin(), v.end());
	auto maxi = *std::max_element(v.begin(), v.end());
	return {mini, maxi};
}

int main()
{
	std::vector<int> a{ 60, 10, 40, 80, 30 };
	auto am = minmax(a);
	std::cout << am.first << " " << am.second << std::endl;  // 10 80

	std::vector<std::string> b{ "Cat", "Dog", "Mouse", "Camel", "Wolf" };
	auto bm = minmax(b);
	std::cout << bm.first << " " << bm.second << std::endl;  // Camel Wolf

	std::vector<std::pair<int, int>> c{ {10, 90}, {30, 10}, {20, 40}, {10, 50} };
	auto cm = minmax(c);
	std::cout << cm.first.first << " " << cm.first.second << std::endl;    // 10 50
	std::cout << cm.second.first << " " << cm.second.second << std::endl;  // 30 10
}
