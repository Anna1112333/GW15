#include <iostream>   //ищем максимальное нечётное число
#include <future>
#include <mutex>
#include <vector>
#include <iterator>
using It = std::vector<int>::iterator ;
int t = 0;
It f;
std::mutex n;

void find(It a, It b) {
    while (a < b) {
        std::lock_guard<std::mutex> lock(n);
        if (*a > t && *a % 2 == 1) t = *a;
        std::cout << *a << std::endl;
        a++;
    }
}
                            //указатель на функцию
void for_each( It a, It b, void(*find0)(It,It)) {
  auto s = distance(a, b);
  std::cout << "s=" << s << std::endl;;
    int v = s / 2;
    if(v >3){
    find0( a +  v, b);        
    std::async(for_each, a + v, b, find);
    find0(a, a + v - 1);
    }
}

#include <iostream>

int main()
{
    std::vector<int> arr = { 12,5,46,7,96,7,16,15 , 5, 1 , 9, 7, 11, 5, 6, 87, 21 };
    for_each( arr.begin(), arr.end(), find);
    std::cout <<"t=" << t;
}

