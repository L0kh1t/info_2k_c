#include <iostream>

namespace mipt
{
	namespace fefm
	{
		struct Point
		{
			int x, y;
		};
	}

	namespace frtk
	{
		void print(fefm::Point p)
		{
			std::cout << p.x << " " << p.y << std::endl;
		}
	}
}

int main()
{
	//1 solution
	//mipt::fefm::Point p = { 10, 20 };
	//mipt::frtk::print(p);

	//2 solution
	//using namespace mipt;
	//fefm::Point p = { 10, 20 };
	//frtk::print(p);

	//3 solution
	using mipt::fefm::Point, mipt::frtk::print;
	Point p = { 10, 20 };
	print(p);
}