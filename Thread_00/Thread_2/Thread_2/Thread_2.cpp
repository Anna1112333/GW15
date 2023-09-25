#define _USE_MATH_DEFINES
#include <cmath>
#include <thread>
#include <chrono>
#include <cstdio>
#include <iostream>
#include <Windows.h>
#include <vector>
#include <random>
#include <execution>
#include <algorithm>

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

                va[j] = rand() % 10;
                vb[j] = rand() % 10;
            }
            a.push_back(va); b.push_back(vb); s.push_back(vs);
        }
    }

    void summa(int x, int y) //x-число потоков y-номер первого складываемого вектора
    {
        int i = 0, j = 0, n1=n;
        if (x != 1) {
            n1 = (n / x + 1)*y; i = (n / x)*y;
        }
        if (x == y) n1 = n;
      
        for (; i < n1; i++)
        {
          for (; j < m; j++)   s[i][j] = b[i][j] + a[i][j];
        }
       
     }
};


 int main()
 {
     setlocale(LC_ALL, "RUS");
     std::cout << std::thread::hardware_concurrency() << std::endl;
    // std::vector<std::thread> t; t.resize(16);
     const int n = 10, m = 100;    
     int x1=1, y1;  //x1 - количество потоков, y1 - номер выборки векторов в матрице 
     for_thread a(1), b(2), c(3), d(4), e(5);
     std::vector<for_thread> aaa;   
     aaa.push_back(a); aaa.push_back(b); aaa.push_back(c); aaa.push_back(d); 
     printf("%-*s%-*s%-*s%-*s%-*s",25, "Потоки \\ элементы", 10, "1000", 10, "10000", 10, " 100000", 10, " 1000000");
    
     std::cout << std::endl << "1 поток";
    printf("%-*s", 12, "");
    for (int i = 0; i < 4; i++) {
        auto start = std::chrono::steady_clock::now();
        aaa[i].summa(1, 1); 
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> some = end - start;
        printf("%-*s", 5, ""); 
        std::cout << some.count();
    }
    

     std::vector<std::chrono::duration<double, std::milli>> some(4);
     some.resize(4);

     std::cout << std::endl << "2 потокa";
     printf("%-*s", 12, "");
     
     std::thread t1(([&]() {
         for (int i = 0; i < 4; i++) {
             auto start = std::chrono::steady_clock::now();
             aaa[i].summa(2, 1);
             auto end = std::chrono::steady_clock::now();
             some[i] = max(end - start, some[i]);          
         }}));
     std::thread t2(([&]() {
         for (int i = 0; i < 4; i++) {
             auto start = std::chrono::steady_clock::now();
             aaa[i].summa(2, 2);
             auto end = std::chrono::steady_clock::now();
             some[i] = max(end - start, some[i]);           
         }}));
     for (int i = 0; i < 4; i++) {
         printf("%-*s", 6, "");
         std::cout << some[i].count();
     }     
    
     t1.join();
     t2.join();
 }

