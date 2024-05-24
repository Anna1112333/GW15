#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>
#include <sstream>
#include <Windows.h>
#include <mutex>
#include <vector>
std::mutex m1, m2;
std::vector<HANDLE>a01(10);
std::vector<std::mutex> mm(10);
std::atomic_int count=0, max_count=0;


void head(int n) {
   count++;
    auto no = std::this_thread::get_id();
    HANDLE a1 = GetStdHandle(STD_OUTPUT_HANDLE); 
    std::lock_guard<std::mutex> lock(m1);
    COORD a2 = { 1,n };      
    SetConsoleCursorPosition(a1, a2);
    std::cout << "number: " << n << " " << no ;
   
}

void raschet(int n)
{
    using namespace std::chrono_literals;
    head(n);
    while (count < max_count) {  }  
        for (int i = 0; i < 10; i++)
        {     int t = rand()%3;          
            while (t < 1000)
            {                  
                t = t * (rand() % 10 + 1) + 1;
                std::this_thread::sleep_for(200ms);               
            }           
            HANDLE a11 = GetStdHandle(STD_OUTPUT_HANDLE);            
            {
            std::lock_guard<std::mutex> lock(m2);
            COORD a22 = { i + 30, n };
            SetConsoleCursorPosition(a11, a22); }
                std::cout << n;
        }
}


int main()
{   
    std::vector<std::thread> th;

    int n = 5;

    max_count = n;
    for (int i = 1; i <= n; i++) {
        th.emplace_back(std::thread(raschet, i));       
    }   
    for (int i = 0; i < n; i++)
        th[i].join();
   // for (int i = 5; i >0; i--)
      //  raschet(i);
    HANDLE a1 = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD a2;
    a2.X = 1;
    a2.Y = 10;
    SetConsoleCursorPosition(a1, a2);
}

