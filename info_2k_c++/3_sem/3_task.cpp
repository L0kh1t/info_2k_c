#include <iostream>
#include <string>
#include <vector>

int main()
{
	int* intmal = new int(123);
	std::cout << *intmal << '\n';
	delete intmal;

	std::string* strmal = new std::string("Cats and Dogs");
	std::cout << *strmal << '\n';
	delete strmal;

	int* intarr = new int[5] {10, 20, 30, 40, 50};
	for (int i = 0; i < 5; ++i) {
		std::cout << intarr[i] << ", ";
	}
	std::cout << std::endl;
	delete[] intarr;

	std::vector<int>* vectormal = new std::vector<int>{ 10, 20, 30, 40, 50 };
	for (const int& val : *vectormal) {
		std::cout << val << ", ";
	}
	std::cout << std::endl;
	delete vectormal;

	std::string* strarray = new std::string[3]{ "Cat", "Dog", "Mouse" };
	for (int i = 0; i < 3; ++i) {
		std::cout << strarray[i] << ", ";
	}
	std::cout << std::endl;
	delete[] strarray;
}