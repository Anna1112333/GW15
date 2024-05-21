#define _USE_MATH_DEFINES
#include <chrono>
#include <thread>
#include <iostream>
#include <Windows.h>
#include <execution>


int main()
{
    std::atomic_int n = 15; //n - клиеты увеличивающие  счётчик на 1 в секунду один раз
    std::atomic_int count = 0; //начальное значение счётчика
    std::thread t1([&]() {
        while (n != 0) {
            using namespace std::chrono_literals;           
            count--;
            std::this_thread::sleep_for(2s);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); //Меняет цвет вывода в коноль
            std::cout << " " << count;
        }
        });
    std::thread t2([&]() {
        using namespace std::chrono_literals;
        while (n != 0) {
            std::this_thread::sleep_for(1s);
            count++;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 46);
            std::cout << " " << count;
            n--;
        }
        });
    t1.join();
    t2.join();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    setlocale(LC_ALL, "RUS");
    std::cout << "\nСчёт завершён!\n";
}