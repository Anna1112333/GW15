#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> end_top(int v, int** arr, int n)
{
    vector<int> temp;
    temp.push_back(v);
    int i = 0, m=-1;
    for (; i < n; ++i)
        if (arr[v][i] == 1) { v = i; i = 0;  temp.push_back(v);
    }
      //  else { m = v; i = n; }
    return temp;
}



int main()
{
    int n, first;
    setlocale(LC_ALL, "Rus");
    ifstream GR("Graph.txt");
    if (GR.is_open()) { GR >> n; }
    else throw "File is not open!";
     cout << "Введите номер вершины с которй нухно начать от 1 до "<<n<<": \n";
     cin>>first;
     int* used_top = new int[n] {};
     int** arr = new int*[n];
     for(int i=0; i<n;++i)
     {
         arr[i] = new int[n];
         cout << endl;
         for (int j = 0; j < n; ++j)
         {
             GR >> arr[i][j];
             cout << arr[i][j] << " ";
         }
     }
     //вывод последовательных вершин до тупиковой
     vector<int> trase = end_top(first, arr, n);
     for (int x : trase) cout << x;




     GR.close();
     delete[] used_top;
     for (int i = 0; i < n; ++i)
         delete[] arr[i];
     delete[] arr;
}

