#include <iostream> // Программа ищет числа делящиеся на три и складывает их.
#include <vector>
#include <iterator>
#include  <algorithm>

class funkt {
public:
    funkt(std::vector<int> h): arr(h)
    {}
    
        std::vector<int> arr;
   void operator ()()
    {
        std::vector <int>::iterator n;

        int  k = std::distance(arr.begin(), arr.end());

        n = arr.begin();
        std::cout << "[IN]: ";
        for (int f : arr)
        {
            std::cout << f << " ";
        }
        std::cout << std::endl;
        int ct = 0, count=0, sum=0; // Обращаемся к счётчику ct, t - значение элемента вектора
        std::transform(n, (n + k), n, [&ct, &count, &sum](int t)mutable {
            if (t % 3 == 0) {
                count++; sum += t;
            }          
            ct++;
            return t;
            }
        );
        std::cout << "[OUT]: get_sum() = " << sum<<std::endl;
        std::cout << "[OUT]: get_count() = " << count<<std::endl;
    }
};

int main()
{    
    std::vector<int> a{ 1, 6, 8, 15, 18, 4, 7, 6};
    funkt b(a);
    b();   
}
