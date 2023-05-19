#include <clocale>
#include <iostream>
#include <algorithm>
#include <vector>

//actual_size - массив с незаполненной частью.

void append_to_dynamic_array(int* arr, int &logical_size, int &actual_size)
{    
    if (logical_size == actual_size)
    {
        actual_size *= 2;
        int* b = new int[logical_size];
        for (int i = 0; i < logical_size; ++i)
            b[i] = arr[i];
           std::swap(b, arr);
        delete[] arr;       
    }
}

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{  
        for (int i = 0; i < actual_size; ++i)
        {
            if (i < logical_size) std::cout << arr[i] << " ";
            else std::cout << "_ ";
        } std::cout << std::endl;   
}

int main()
{
    int logical_size, actual_size;
    setlocale(LC_ALL, "rus");
    std::cout << "Введите фактический размер массива.\n";
    std::cin >> actual_size;
    std::cout << "Введите логический размер массива.\n";
    std::cin >> logical_size;
    if (logical_size > actual_size)
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!\n";
    else {
        int* a = new int[actual_size];
      

        //Ввод массива до увеличения
        for (int i = 0; i < logical_size; ++i)
        {
            std::cout << "Введите a[" << i << "]:";
            std::cin >> a[i];
            if(a[i]==0)
            {
                std::cout << "Спасибо! Ваш массив: ";
                print_dynamic_array(a, logical_size, actual_size);
                delete[]a;
                return 0;
            }
            std::cout << std::endl;
        }
        std::cout << "Динамический массив: ";
        print_dynamic_array(a, logical_size, actual_size);
        logical_size++;
        //Ввод продолжен
   while (1) 
   {    
       append_to_dynamic_array(a, logical_size, actual_size);
        std::cout<< "\n Введите элемент для добавления: ";
        std::cin >> a[logical_size-1];
        if (a[logical_size-1] == 0)
        {   
            std::cout << "Спасибо! Ваш массив: ";
            print_dynamic_array(a, logical_size, actual_size); 
            delete[]a;
            return 0;
        } 
        std::cout << "Динамический массив: ";
        print_dynamic_array(a, logical_size, actual_size); 
        logical_size++;
   }}}
