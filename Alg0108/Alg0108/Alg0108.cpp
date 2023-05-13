#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    int n;

    ifstream gh("Matr.txt");
    if (gh.is_open())
    {
        gh >> n; // читаем из файла
    }
    else
    {
        std::cout << "Не получилось открыть файл!" << std::endl;
    }
    int** a = new int* [n];
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            gh >> a[i][j];           
        }
    }
    for (int i = 0; i < n; i++)
    {
        int k=0;
        cout << i+1 << "  ";
        for (int j = 0; j < n; j++)
            if (a[i][j]) {
                k++;
                cout << j + 1 << " ";
            }
        if (k == 0) cout << "нет";
        cout<<"\n"; 
    }
    gh.close();
    for (int i = 0; i < n; i++)
    {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}