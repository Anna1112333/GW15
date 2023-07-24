#include <iostream>
#include <vector>

template<typename T>
class simple_2array
{ 
    int num1 = 0, num2 = 0; //колличество строк и столбцов
public:
      
    class row {         //класс столбцов таблицы 
        int n_2;
    public:
        std::vector<T> elem;
        row(int i, int num2): n_2(num2) //i-тый ряд num2 элементов
        {
            for (int i = 0; i < num2; i++)
                elem.push_back(0);
        }
        T& operator [] (int i_2) {
            if (i_2 >= 0 && i_2 < n_2)
                return elem[i_2];
            else
                throw std::runtime_error("Index is outside array bounds!");
        }
    };
    std::vector<row> el_row;
    row& operator[](int i_1) {
        if (i_1 >= 0 && i_1 < el_row.size())
           return el_row[i_1];
        else
           throw std::runtime_error("Index is outside array bounds!");
     }
    simple_2array(int elem1, int elem2) :  num1(elem1), num2(elem2)
    {
        for (int i = 0; i < num1; i++)
            el_row.push_back(row(i, elem2));          
    }
     T getElement(int i_1, int i_2) 
    {
       return el_row[i_1][i_2];
    }  
    void setElement(int inIndex1, int inIndex2,  T inValue)
    {       
        el_row[inIndex1][inIndex2] = inValue;
    }    
    void operator = ( simple_2array const &a) = delete; 
    friend int Size(const simple_2array<int>&);  
};
int Size(const simple_2array<int>& h)
{
    int k1 = h.num1;
    int k2 = h.num2;
    return k1 * k2;
}

int main()
{
    unsigned int n = 10, m = 10;
    int x = 4, y = 5;   
    simple_2array<int> n_0(n,m);
     n_0.setElement(x,y, 10);
   std::cout<<"\ngetElem=" <<n_0.getElement(x, y)<<std::endl;
  n_0.el_row[x][y] = 58;
  n_0[1][3] = 187;
  //std::cout << n_0.el_row[x][y] + n_0[1][3]<<std::endl;
   std::cout << "\ngetElem=" << n_0.getElement(x, y);
  std::cout <<"\n Size=" << Size(n_0);
}

