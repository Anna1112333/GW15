#include <iostream> // Программа возводит в квадрат число или координаты вектора.
#include <vector>
#include <iterator>
#include <algorithm>
//using namespace std;
template<typename T>

void sqw(T a)
{
    a = a * a;
    std::cout << a<<std::endl;

}
template<> void sqw<std::vector<int>> (std::vector<int> arr)
{
    std::vector <int>::iterator n;

    int  k = distance(arr.begin(), arr.end());

    n = arr.begin();

    for (int f : arr)
    {
        std::cout << f << " ";
    }
    std::cout << std::endl;
    int ct = 0; // Обращаемся к счётчику ct, t - значение элемента вектора
    std::transform(n, (n + k), n, [&ct](int t)mutable {
         t = t * t;
        ct++;
        return t;
        }
    );
    for (int f : arr)  std::cout << f << " ";
    std::cout << std::endl;
}
int main()
{
    int g = 1000;
    sqw(g);
    std::vector<int> a{ 1,6,8 };
    sqw(a);    
}
