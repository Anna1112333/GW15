#include <iostream>
using namespace std;

int main()
{//С нечётными номерами умножаются на 3
    int arr[] = { 2,3,7,9,11 };
    int n, k;
    for (int f : arr)
    {
        f = 3*f; 
        cout << *(&f+sizeof(int)) << " ";
    }
}

