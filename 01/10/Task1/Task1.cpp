#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{//С нечётными номерами умножаются на 3
    vector <int> arr{ 2,3,7,9,11 };
    vector <int>::iterator n;

    int  k = distance(arr.begin(), arr.end());
   
    n = arr.begin();
   
    for (int f : arr)
    {
        cout << f << " ";
    }
    cout << endl;
    int ct = 0; // Обращаемся к счётчику ct, t - значение элемента вектора
    transform(n, (n+k), n, [ct](int t)mutable {
        if (ct % 2 == 1) t = t * 3;
        ct++;
        return t;
        }
    );
    for (int f : arr)  cout << f << " ";
}
