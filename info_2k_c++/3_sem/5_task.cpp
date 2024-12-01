#include <iostream>
#include <string>

int sumstr(const std::string& str1) {
	std::string str = str1.substr(1, str1.length() - 2);

	if (str.empty())
		return 0;

	int result = 0;

	std::size_t index = 0;

	while (index < str.length()) {
		std::string strnum = "";
		while (index < str.length() && str[index] != ',') {
			strnum += str[index];
			index++;
		}
		result += std::stoi(strnum);
		index++;
	}
	return result;
}

int main()
{
	std::string str1 = "[10, 20, 30, 40, 50]";
	std::cout << sumstr(str1) << '\n';
	std::string str2 = "[20]";
	std::cout << sumstr(str2) << '\n';
	std::string str3 = "[]";
	std::cout << sumstr(str3) << '\n';
}