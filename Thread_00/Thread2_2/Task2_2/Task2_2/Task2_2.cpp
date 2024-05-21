#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>
#include <sstream>
#include <Windows.h>
#include <mutex>
int m0 = 0;
std::mutex mu1;
void raschet(int n)
{
    auto no = std::this_thread::get_id;
    HANDLE a1 = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD a2;
    {
        std::lock_guard<std::mutex> lock(mu1);
        m0++;
        a2.X = 1;
        a2.Y = n;
        SetConsoleCursorPosition(a1, a2);       
        std::cout << "number: " << m0 << " " << no << std::endl;
          }
        for (int i = 0; i < 10; i++)
        {         
            a2.X = i + 30;
            a2.Y = n;
            SetConsoleCursorPosition(a1, a2);
            int t = 0;
            std::cout << t;
            using namespace std::chrono_literals;
            while (t < 1000)
            {               
                t = t * (rand() % 10 + 1) + 1;
                std::this_thread::sleep_for(200ms);
            }
        }
}


int main()
{   
    int n = 1, m=2;
    std::thread t1(raschet, n);
    std::cout << std::endl;
    std::thread t2(raschet, m);
    t1.join();
    t2.join();
    HANDLE a1 = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD a2;
    a2.X = 1;
    a2.Y = 10;
    SetConsoleCursorPosition(a1, a2);
}

