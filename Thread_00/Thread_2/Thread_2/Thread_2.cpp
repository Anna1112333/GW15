#define _USE_MATH_DEFINES
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
    std::vector<std::vector<int>> a;
    std::vector<std::vector<int>> b;
    std::vector<std::vector<int>> s;
    for_thread(std::vector<std::vector<int>> a, std::vector<std::vector<int>> b, std::vector<std::vector<int>> s)
    {
        this->a = a; this->b = b; this->s = s;
    }
};



   
void summa(std::vector<std::vector<int>> a, std::vector<std::vector<int>> b, std::vector<std::vector<int>> s,  int n, int m, int k1)
    {   
    
    if (k1==1) std::this_thread::sleep_for(std::chrono::seconds(10)); 
    if (k1 == 2) std::this_thread::sleep_for(std::chrono::seconds(1));
            auto start = std::chrono::steady_clock::now();
            for (int i = 0; i < n; i++)
            { 
                for (int j = 0; j < m; j++)   s[i][j] = b[i][j] + a[i][j];                       
            }      
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double, std::milli> some = end - start;
            std::cout << "time is " << some.count() << std::endl;
            n = n * 10;  
            
    }


 int main()
 {
     std::cout << std::thread::hardware_concurrency() << std::endl;
     const int n = 10, m = 100;    
     std::vector<std::vector<int>> a, b, s;      
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
       summa(a, b, s, n, m, 1);
       int m1 = 100;
        std::thread t1(summa, a, b, s, n, m, 2); 
       
        std::thread t3(summa, a, b, s, n , m, 3);
        summa(a, b, s, n, m/4, 1);
    t1.join();
   
    t3.join();
}

