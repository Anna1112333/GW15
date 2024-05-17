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
    std::vector<std::vector<int>> a; //n векторов по m элементов
    std::vector<std::vector<int>> b;
    std::vector<std::vector<int>> s;
    for_thread(int k)       //- число элементов в массиве равно n*(m*10^k)
    {    
        m = m *pow(10, k);
       // std::cout << "k =   " << k << "m =   "<<m<<std::endl;
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
        int i = 0,  n1=n; //потоки складывают вектора с i по n1
        if (x != 1 ) {
            if(x!=y)
            n1 = (n / x )*y; 
          
            i = (n / x)*(y-1);
        }     
        for (; i < n1; i++)
        {
          for (int j=0; j < m; j++)   s[i][j] = b[i][j] + a[i][j];
        }                
     }
};


int main()
{
     setlocale(LC_ALL, "RUS");
     std::cout <<"Колличество ядер: " << std::thread::hardware_concurrency() << std::endl;
     const int n = 10, m = 100;
     int x1=1, y1;  //x1 - количество потоков, y1 - номер выборки векторов в матрице 0-(х1-1)
     for_thread a(1), b(2), c(3), d(4);
     std::vector<for_thread> aaa;
     aaa.emplace_back(a); aaa.emplace_back(b);
     aaa.emplace_back(c); aaa.emplace_back(d);
     printf("%-*s%-*s%-*s%-*s%-*s",25, "Потоки \\ элементы", 13, "1000", 11, "10 000", 11, " 100 000", 14, " 1 000 000");

     std::cout << std::endl << "1 поток";
    printf("%-*s", 19, "");
    for (int i = 0; i < 4; i++) {
        auto h1 = std::chrono::steady_clock::now();
        aaa[i].summa(1, 1);
        auto h2 = std::chrono::steady_clock::now();
        std::chrono::duration<double, std::milli> some = h2 - h1;
        std::cout << some.count() << " ";
        printf("%-*s", 5, "");
    }
    std::cout << std::endl << "2 потока";
   
    printf("%-*s", 16, "");
std::vector<std::thread> t;
    {
         for (int u = 0; u < 4; u++)
         {
            auto t0 = std::chrono::steady_clock::now();
             for (int i = 1; i < 3; i++) //потоки 1 и 2
             {
                 t.emplace_back(std::thread(&for_thread::summa, aaa[u], 2, i));
             }
             auto t1 = std::chrono::steady_clock::now();
             std::chrono::duration<double, std::milli> t10 = t1 - t0;
             std::cout << "   " << t10.count() << "  ";
         }
       

    }
    for (int i = 0; i < 8; i++)
        t[i].join();

    std::cout << std::endl << "4 потока";

    printf("%-*s", 16, "");
    std::vector<std::thread> tt;
    {
        
        for (int u = 0; u < 4; u++)
        {
            auto t0 = std::chrono::steady_clock::now();
            for (int i = 1; i < 5; i++) //потоки 1 - 4
            {
                tt.emplace_back(std::thread(&for_thread::summa, aaa[u], 4, i));
            }
            auto t1 = std::chrono::steady_clock::now();
            std::chrono::duration<double, std::milli> t10 = t1 - t0;
            std::cout << "   " << t10.count() << "  ";
        }
    }
    for (int i = 0; i < 16; i++)
        tt[i].join();
   
    std::cout << std::endl << "8 потоков";

    printf("%-*s", 15, "");
    std::vector<std::thread> ttt;
    {

        for (int u = 0; u < 4; u++)
        {
            auto t0 = std::chrono::steady_clock::now();
            for (int i = 1; i < 9; i++) //потоки 1 - 4
            {
                ttt.emplace_back(std::thread(&for_thread::summa, aaa[u], 8, i));
            }
            auto t1 = std::chrono::steady_clock::now();
            std::chrono::duration<double, std::milli> t10 = t1 - t0;
            std::cout << "   " << t10.count() << "  ";
        }
    }
    for (int i = 0; i < 32; i++)
        ttt[i].join();

    std::cout << std::endl << "16 потоков";

    printf("%-*s", 14, "");
    std::vector<std::thread> tttt;
    {

        for (int u = 0; u < 4; u++)
        {
            auto t0 = std::chrono::steady_clock::now();
            for (int i = 1; i < 17; i++) //потоки 1 - 4
            {
                tttt.emplace_back(std::thread(&for_thread::summa, aaa[u], 16, i));
            }
            auto t1 = std::chrono::steady_clock::now();
            std::chrono::duration<double, std::milli> t10 = t1 - t0;
            std::cout << "   " << t10.count() << "  ";
        }
    }
    for (int i = 0; i < 64; i++)
        tttt[i].join();

        
}