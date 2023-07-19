#include <iostream>
#include <vector>

template<typename T>
class simple_2array
{
 public:
    int num1 = 0, num2 = 0; //колличество строк и столбцов
    int inIndex1, inIndex2; //индексы элемента таблицы   
    T* elements=nullptr;
    class row {         //класс столбцов таблицы
 
        int i_2, i_1;
        int n = 0;
  public:        
        T* elem;
        row(int num2) 
        {            
           // std::cout << "* " << num2<<" ";
            elem = new T[num2]; 
        }
        T& operator [] (int i_2) {  return elem[i_2]; }
    } ;
    std::vector<row> el_row;
   
    simple_2array(int elem1, int elem2) :  num1(elem1), num2(elem2)
    {
        for (int i = 0; i < num1; i++)
        {
            el_row.push_back(row(i));         
        }       
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
   std::cout<<"\ngetElem=" <<n_0.getElement(x, y);
  n_0.el_row[x][y] = 58;
   std::cout << "\ngetElem=" << n_0.getElement(x, y);
  std::cout <<"\n Size=" << Size(n_0);
}

