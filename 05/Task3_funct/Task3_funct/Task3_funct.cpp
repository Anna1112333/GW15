#include <iostream> // Программа ищет числа делящиеся на три и складывает их.
#include <vector>
#include <iterator>
#include  <algorithm>

class funkt {
    int  count=0, sum=0; 
public:        
        int get_sum() {
           return sum;
        }
        int get_count() {
            return count;
            }
void operator ()(int a)
    {     
    if (a % 3 == 0)
    {
        sum = sum + a;
        count = count + 1;
    }}
};

int main()
{    
    std::vector<int> arr{ 1, 6, 8, 15, 18, 4, 7, 6};
    std::cout << "[IN]: ";
    for (int i : arr)    std::cout << i << " ";    
    std::cout << std::endl;
    funkt f;
    f = std::for_each(arr.begin(), arr.end(), f);   
    std::cout << "[OUT]: get_sum() = " << f.get_sum() << '\n';
    std::cout << "[OUT]: get_count() = " << f.get_count() << '\n';    
}
