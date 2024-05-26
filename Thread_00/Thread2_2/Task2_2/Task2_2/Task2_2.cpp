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
HANDLE a1 = GetStdHandle(STD_OUTPUT_HANDLE);

static void SetPosition(int x, int y)
{
    COORD point;
    std::lock_guard<std::mutex> lock(m1);
    point.X = x;
    point.Y = y;
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(2ms);
    SetConsoleCursorPosition(a1, point);
    std::cout<< y;
}

void head(int n) {
    using namespace std::chrono_literals;   
    auto no = std::this_thread::get_id();  
    std::lock_guard<std::mutex> lock(m2);
    COORD a2 = { 1,n };   
    std::this_thread::sleep_for(2ms);
    SetConsoleCursorPosition(a1, a2);
    std::cout << "number: " << n << " id " << no;
    std::this_thread::sleep_for(2ms);
count++;
}

void raschet(int n)
{
    using namespace std::chrono_literals;
    head(n);
    while (count < max_count) { std::this_thread::sleep_for(2ms); }
        for (int i = 0; i < 10; i++)
        {
            int ii = i + 30;
        int time = rand() % 1000;
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(1ms * time*n);      
        SetPosition(ii, n);            
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

