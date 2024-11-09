#include <iostream>
#include <string>

// ��� ����� �������� ������� isDomainName
bool isDomainName(std::string str)
{
	std::size_t size = str.size();
	if (str[0] == 'w' && str[1] == 'w' && str[2] == 'w' && str[size - 4] == '.' && str[size - 3] == 'c' && str[size - 2] == 'o' && str[size - 1] == 'm')
	{
	return true;
}
	else
		return false;
}


int main()
{
	std::cout << isDomainName("www.google.com") << std::endl;         // ���������� 1
	std::cout << isDomainName("abc") << std::endl;                    // ���������� 0
	std::cout << isDomainName("hello.com") << std::endl;              // ���������� 0
}