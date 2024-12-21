#include <iostream>
#include <set>

int main()
{
	int n;
	std::cin >> n;
	std::multiset<int> a;
	for (int i = 0; i < n; ++i) {
		int m;
		std::cin >> m;
		a.insert(m);
	}

	for (auto it = a.begin(); it != a.end(); ++it)
		std::cout << *it << " ";
}