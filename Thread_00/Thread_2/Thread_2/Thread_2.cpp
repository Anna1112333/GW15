#include <thread>
#include <chrono>
#include <iostream>
#include <Windows.h>
#include <vector>

 void summa(std::vector<std::vector<int>> a, std::vector<std::vector<int>> b, int n, int m)
 {
     for (int k = 0; k < 5; k++) {

         for (int i = 0; i < n; i++)
         {
             std::vector<int> va, vb; //временный вектор в области видимости
             va.resize(m); vb.resize(m); //нужно заранее уквзать длину, чтоб не выходить за границы при заполнении
             for (int j = 0; j < m; j++)
             {
                 va[j] = rand() % 10;
                 vb[j] = rand() % 10;
                 //  std::cout <<va[j]<< " + " << vb[j] << "\t";
             }   // std::cout << "\n";
             a.push_back(va); b.push_back(vb);
         }

         std::vector < std::vector<int>>s;
         auto start = std::chrono::steady_clock::now();
         for (int i = 0; i < n; i++)
         {
             std::vector<int> s1;
             s1.resize(m);
             for (int j = 0; j < m; j++)
             {
                 s1[j] = b[i][j] + a[i][j];
             }
             s.push_back(s1);
         }
         /*  for (int i = 0; i < n; i++)
           {
               for (int j = 0; j < m; j++)
               {
                   std::cout << s[i][j] << "\t";
               } std::cout << std::endl;}*/


         auto end = std::chrono::steady_clock::now();
         std::chrono::duration<double, std::milli> some = end - start;
         std::cout << "time is " << some.count() << std::endl;
         n = n * 10;
     } std::cout << "\t";
}

 int main()
 {
     std::cout << std::thread::hardware_concurrency() << std::endl;
     const int n = 10, m = 100;
    
     std::vector<std::vector<int>> a, b;
    std::vector<int> a1, b1;
   
   
   
     /*   for (int i = 0; i < n; i++)
        {
            std::vector<int> va, vb; //временный вектор в области видимости
            va.resize(m); vb.resize(m); //нужно заранее уквзать длину, чтоб не выходить за границы при заполнении
            for (int j = 0; j < m; j++)
            {
                va[j] = rand() % 10;
                vb[j] = rand() % 10;
                //  std::cout <<va[j]<< " + " << vb[j] << "\t";
            }   // std::cout << "\n";
            a.push_back(va); b.push_back(vb);
        }*/
        std::thread t1(summa, b, a, n, m);
    
    //std::thread t2(summa, s[0], b[0], a[0], m, n);
   // summa(s[0], b[0], a[0], m, n );
   
     
    t1.join();
    //t2.join();    
}

