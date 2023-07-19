#include <iostream> // Программа ищет числа делящиеся на три и складывает их.
#include <vector>
#include <iterator>
#include  <algorithm>

class funkt {
public:
    funkt()  {}
        std::vector<int> arr;      
       
        int  count=0, sum=0; // Обращаемся к счётчику ct, t - значение элемента вектора
        int get_sum() {
            std::for_each(arr.begin(), arr.end(), [&](int t) {
                if (t % 3 == 0)  sum += t;
                return t;
                });
            return sum;
        }
            int get_count() {
                std::for_each(arr.begin(), arr.end(), [&](int t) {
                    if (t % 3 == 0)  count++;
                    return t; });
                return count;
            }
void operator ()(int a)
    {        
    arr.push_back(a);      
    }
};

int main()
{    
    std::vector<int> arr{ 1, 6, 8, 15, 18, 4, 7, 6};
    std::cout << "[IN]: ";
    for (int i : arr)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    funkt f;
    f = std::for_each(arr.begin(), arr.end(), f);   
    std::cout << "[OUT]: get_sum() = " << f.get_sum() << '\n';
    std::cout << "[OUT]: get_count() = " << f.get_count() << '\n';    
}
