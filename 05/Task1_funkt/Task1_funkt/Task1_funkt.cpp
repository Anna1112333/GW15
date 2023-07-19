#include <iostream> // Программа возводит в квадрат число или координаты вектора.
#include <vector>
#include <iterator>
#include <algorithm>

template<typename T>

void sqw(T& a)
{
    a = a * a; 
}
void sqw(std::vector<int>& arr)
{  
    std::vector<int>::iterator n;
    int  k = distance(arr.begin(), arr.end());
     n = arr.begin();  
    std::transform(n, (n + k), n, [](int t)mutable {
         t = t * t;        
        return t;
        }
    );  
}
int main()
{
    int g = 10;
    std::cout<<g<< std::endl;
    sqw(g);
    std::cout << g << std::endl;
    sqw(g);
    std::cout << g << std::endl;
    std::cout << std::endl;

    std::vector<int> a{ 1,6,8 };
    for (int f : a) { std::cout << f << " "; }
    std::cout << std::endl;
    sqw(a); 
    for (int f : a) { std::cout << f << " "; }
    std::cout << std::endl;
    sqw(a);
    for (int f : a) { std::cout << f << " "; }
    std::cout << std::endl;
}
