#define _USE_MATH_DEFINES
#include <cmath>
#include <thread>
#include <chrono>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <random>
#include <execution>
#include <algorithm>
//using namespace std;

struct for_thread
{
    int n = 10, m=100;
    std::vector<std::vector<int>> a;
    std::vector<std::vector<int>> b;
    std::vector<std::vector<int>> s;
    for_thread(int k)       //- число элементов в массиве равно n*m*k
    {
        std::cout << "Конструктор\n";
        m = m * k;
        for (int i = 0; i < n; i++)
        {
            std::vector<int> va, vb, vs; //временный вектор в области видимости
            va.resize(m); vb.resize(m), vs.resize(m); //нужно заранее уквзать длину, чтоб не выходить за границы при заполнении
            for (int j = 0; j < m; j++)
            {

                /*   mt19937 gen;   //не находит
                   uniform_int_distribution<int> dis(0, 1'000'000);
                      auto rand_num([=]() mutable {return dis(gen); });
                       generate(va.begin(), va.end(), rand_num);*/
                va[j] = rand() % 10;
                vb[j] = rand() % 10;
            }
            a.push_back(va); b.push_back(vb); s.push_back(vs);
        }
    }

    void summa(int x, int y) //x-число потоков y-номер первого складываемого вектора
    {

       // if (k1 == 1) std::this_thread::sleep_for(std::chrono::seconds(10));
        auto start = std::chrono::steady_clock::now();
        for (int i = 0; i < n; i++)
        {
          for (int j = 0; j < m; j++)   s[i][j] = b[i][j] + a[i][j];
        }
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> some = end - start;
       // std::cout << "time is " << some.count() << std::endl;
     }
};


 int main()
 {
     setlocale(LC_ALL, "RUS");
     std::cout << std::thread::hardware_concurrency() << std::endl;
     std::vector<std::thread> t; t.resize(16);
     const int n = 10, m = 100;    
     int x1=1, y1;  //x1 - количество потоков, y1 - номер выборки векторов в матрице 
     std::vector<for_thread> aaa(4, 1);        
         
     for (int k = 0; k < 4; k++) {
         x1 *= 2;
         // t.push_back( std::thread (&for_thread::summa, a[k], x1, y1));
         t.push_back(std::thread([&]() {aaa[0].summa(1, 1);  aaa[1].summa(1, 1); }));
            std::cout << " поток для " << 100 * pow(10, k) <<" элементов" << std::endl;
            
             } 
     for (int k = 0; k < 4; k++) t[k].join();
 }

