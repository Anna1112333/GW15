#include<set>
#include<vector>
#include <iostream>
#include<deque>


int main()
{
    int a, b;
    std::set<int> c;
    std::deque <int> d;
    setlocale(LC_ALL, "RUS");
    std::cout << "Введите число элементов.\n";
    std::cin >> a;
    std::cout << "Вводите числа.\n";
    for (int i = 0; i < a; i++)
    {
        std::cin >> b;
        c.insert(b);
    }
    for (auto j : c) d.push_front(j);
    std::cout << "Ваши числа:" << std::endl;
    for (auto f : d) std::cout<<f<<std::endl;
}
