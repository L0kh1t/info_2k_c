#include <iostream>
#include <string>
#include <vector>
// Тут нужно написать функцию concatenate
std::string concatenate(std::vector<std::string> vec) {
    std::string result = "";
    for (int i = 0; i < vec.size(); i++) {
        result += vec[i];
    }
    return result;
}

int main()
{
	std::vector<std::string> v{ "Cat", "Dog", "Mouse", "Tiger", "Elk" };
    std::cout << concatenate(v); // Должно напечатать CatDogMouseTigerElk
}