#include <iostream>
#include <set>

int main()
{
	int n, k;
	
	std::cin >> n >> k;
	
	std::set<int> a{ 0, n };
	std::multiset<int> b{n};

	for (int i = 0; i < k; ++i)
	{
		int m;
		std::cin >> m;

		auto it = a.lower_bound(m);
		int right_end = *it;
		int left_end = *(--it);

		a.insert(m);
		b.erase(right_end - left_end);
		b.insert(right_end - m);
		b.insert(m - left_end);
		

		std::cout << *(b.rbegin()) << " ";
	}
}