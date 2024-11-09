#include <iostream>
#include <cctype>

void countLetters(const std::string& str, int& numLetters, int& numDigits)
{
	int a = str.size();
	numLetters = a;
	int count = 0;
	for (std::size_t i = 0; i < numLetters; i++) {
		if (std::isupper(str[i]))
			count++;
	}
	numDigits = count;
}

int main()
{
	std::string str = "Hello";
	int numLetters = 0;
	int numDigits = 0;
	countLetters(str, numLetters, numDigits);
	std::cout << numLetters << ' ' << numDigits;
}