#include <iostream>
#include <string>
#include <vector>
void print(const std::vector<int>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}
// Тут нужно написать функцию doubling
void doubling(std::vector<int>& vec) {
    size_t size = vec.size();
    for (size_t i = 0; i < size; ++i) {
        vec.push_back(vec[i]);
    }
}

int main()
{
    std::vector<int> v{ 10, 20, 30 };
    doubling(v);
    print(v);  // Должно напечатать 10 20 30 10 20 30
}