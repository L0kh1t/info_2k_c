#include <iostream>
#include <map>

int main()
{
	std::map<int, int> numbers;

	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		int m;
		std::cin >> m;
		numbers[m] += 1;
	}
	
	for (auto pair : numbers) {
		std::cout << pair.first << " " << pair.second << std::endl;
	}
}