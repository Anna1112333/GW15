#define _USE_MATH_DEFINES
#include <chrono>
#include <thread>
#include <iostream>
#include <Windows.h>
#include <execution>


int main()
{
   int n = 15; //n - клиеты увеличивающие  счётчик на 1 в секунду один раз
   int count = 0; //начальное значение счётчика
   std::thread t1([&]() {
       while(n!=0){
       using namespace std::chrono_literals;
       //using namespace ConsoleParams; consol_parameter::SetColor(0, 10);
           count--;
           std::this_thread::sleep_for(2s);
           std::cout << " " << count;
       }
       });
   std::thread t2([&]() {
       using namespace std::chrono_literals;
       while(n!=0){
       std::this_thread::sleep_for(1s);      
           count++;
           std::cout << " " << count;
           n--;
       }
       });   
   t1.join();
   t2.join();
   using namespace std::chrono_literals;
  // std::this_thread::sleep_for (20s);
    setlocale(LC_ALL, "RUS");
    std::cout << "\nСчёт завершён!\n";    
}

