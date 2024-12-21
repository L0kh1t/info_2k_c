#include <iostream>
#include <list>

int main()
{
	int n, m;
	std::cin >> n >> m;

	std::list<int> kniphs;
	for (int i = 1; i <= n; ++i)
		kniphs.push_back(i);

	auto current = kniphs.begin();

	while (kniphs.size() > 1) {
		for (int i = 1; i < m; ++i) {
			++current;
			if (current == kniphs.end())
				current = kniphs.begin();
		}
		
		std::cout << *current << " ";
		current = kniphs.erase(current);
		if (current == kniphs.end())
			current = kniphs.begin();
	}

	std::cout << '\n' << kniphs.front() << '\n';

}