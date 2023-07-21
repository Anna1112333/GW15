#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
template<typename T>
void move_vectors(std::vector<T>& vk1, std::vector<T>& vk2)
{
    vk2=std::move(vk1);
}

int main()
{
    std::vector<std::string> a{ "rock","river","song" };
    std::vector<std::string> b{ "before","now","after" };
    move_vectors(a, b);
    std::cout << "a=";
    for (std::string i : a) std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "b=";
    for (std::string i : b) std::cout << i << " ";
    std::cout << std::endl;
}
