#include <iostream>
template<class T>
class simple_2array
{
    T** elements = nullptr;
    T* elements2 = nullptr;
    int num1 = 0, num2 = 0; //колличество строк и столбцов
    int inIndex1, inIndex2; //индексы элемента таблицы

public:
    class row;

    simple_2array(int elem1, int elem2)
        : num1(elem1), num2(elem2)
    { 
        elements = new  T*[elem1];
        for (int i = 0; i < num1; ++i)
            row elements[i] = new T[elem2];
    }
    T getElement(int inIndex1, int inIndex2) const
    {
        return elements[inIndex1][inIndex2];
    }   

    void setElement(int inIndex1, int inIndex2,  T inValue)
    {
        elements[inIndex1][inIndex2] = inValue;
    }
    
    row& operator [](int a)
    {
        return elements + a;
    }
    ~simple_2array()
    {
        for (int i = 0; i < num1; ++i)
           delete[] elements[i];
        delete[] elements;
    }
private:    
    class row {
    public:
        T* b1;
        row(int by):b1(by){}
        T& operator [] (int b)   {return b1[b];  }
    };
};



int main()
{
    unsigned int n = 0, m = 0;
    std::cin >> n >> m;
    simple_2array<int> table(10,10); //int --- T
    table.setElement(n, m, 'a');
    std::cout << table[0][0]<<std::endl;   
}

