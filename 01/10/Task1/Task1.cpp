#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{//С нечётными номерами умножаются на 3
    vector <int> arr;
    arr= { 2,3,7,9,11 };
    vector <int>::iterator n;
    //int n=0, k;
    n = arr.begin();
    transform(arr.begin(), arr.end(), arr.begin(),
        [n](vector <int> arr)mutable { advance(n, 3); return arr; });
    for (long int f : arr)
    {
        n++;
       // if ((n + 1) % 2) f *= 3;
        cout << f << " ";
        //cout << *(&f+sizeof(int)) << " ";
    }
}

