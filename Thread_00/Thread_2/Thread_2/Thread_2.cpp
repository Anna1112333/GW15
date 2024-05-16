#define _USE_MATH_DEFINES       //распараллеоить программу сложения матриц на 1, 2, 4, 8, 16 потоков.
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

using namespace std::literals::chrono_literals;

struct for_thread
{  
   
    int n = 10, m=100;
    std::vector<std::vector<int>> a;
    std::vector<std::vector<int>> b;
    std::vector<std::vector<int>> s;
    for_thread(int k)       //- число элементов в массиве равно n*(m*k)
    {    
        m = m *pow(10, k);
        std::cout << m << " ";
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

    void summa(int x, int y) //x-число потоков y-номер операции сложения от 1 до х
    {
     
       // auto h1 = std::chrono::steady_clock::now();      
        int i = 0, j = 0, n1=n; //потоки складывают вектора с i по n1
        if (x != 1 && x!=y) {
            n1 = (n / x )*y; i = (n / x)*(y-1);
        }     
        for (; i < n1; i++)
        {
          for (; j < m; j++)   s[i][j] = b[i][j] + a[i][j];
        }    
       // auto h2 = std::chrono::steady_clock::now();
       // std::chrono::duration<double, std::milli> some =h2 - h1 ;    
      //std::cout << some.count()<<" ";        
     }
};


 int main()
 {
    
     setlocale(LC_ALL, "RUS");
     std::cout << std::thread::hardware_concurrency() << std::endl;   
     const int n = 10, m = 100;    
     int x1=1, y1;  //x1 - количество потоков, y1 - номер выборки векторов в матрице 0-(х1-1)
     for_thread a(1), b(2), c(3), d(4);
     std::vector<for_thread> aaa;   
     aaa.emplace_back(a); aaa.emplace_back(b); 
     aaa.emplace_back(c); aaa.emplace_back(d); 
     printf("%-*s%-*s%-*s%-*s%-*s",25, "Потоки \\ элементы", 10, "1000", 10, "10 000", 10, " 100 000", 10, " 1 000 000");
    
     std::cout << std::endl << "1 поток";
    printf("%-*s", 12, "");
    for (int i = 0; i < 4; i++) { 
        auto h1 = std::chrono::steady_clock::now();
        aaa[i].summa(1, 1);  
        auto h2 = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> some = h2 - h1;
        std::cout << some.count() << " ";
        printf("%-*s", 5, "");       
    }
    std::cout << std::endl << "2 потока"; 
    size_t threads[]{ 1, 2, 4, 8, 16, 32 };
    printf("%-*s", 12, "");
std::vector<std::thread> t;
    {
        
       std::vector<std::chrono::duration<double, std::milli>> some(4);
        
       for (int i = 0; i < 4; i++)
       {
           auto t0 = std::chrono::steady_clock::now();
           t.emplace_back(std::thread(&for_thread::summa, a, 4, i));
          
           auto t1 = std::chrono::steady_clock::now();
           some[i] = t1 - t0;
           std::cout << "t10 = " << some[i].count()<<"  ";
       }    
    }
       t[1].join();
       t[2].join();
       t[3].join();
       t[0].join();    
} 