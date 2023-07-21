#include<string>
#include<vector>
#include<deque>
#include<memory>
#include <iostream>

class big_integer
{
    std::deque<unsigned> sum(std::deque<unsigned> s, std::deque<unsigned> d){
        this->num1="";
        std::deque<unsigned> a;
        int less, max;
      
        if (s.size() >= d.size()) std::swap(s, d);
        {
            less = d.size() - s.size();
            max = d.size();
            for (int i = 0; i < max; i++)
                if (i < less) a.push_back(d[i]);
                else a.push_back(d[i] + s[i - less]);
        }
       a= bring_to_10(a);
        return a;
    }
    std::deque <unsigned> bring_to_10 (std::deque<unsigned>a) {
        int max =a.size();
        for (int i = max - 1; i > 0; i--)
        {
            if (a[i] > 9) {
                a[i - 1] += a[i] / 10;
                a[i] = a[i] % 10;
            }
        }
        if (a[0] > 9) {int k= a[0] / 10;
        a[0] %= 10;
        a.push_front(k); 
        }
        return a;
    }

    std::deque<unsigned> multiply(unsigned s, std::deque<unsigned> d) {
        this->num1="";
        std::deque<unsigned> m, n, n0;
        unsigned  wr=0;
        int length_d = d.size();
        for (int i = 0; i < length_d; i++) n0.push_back(0);
        while (s != 0)              //переводим s из unsigned в deque
        {    wr =s % 10;       
            s =  s / 10;            
            m.push_front(wr);
        }       
        int length_s = m.size();
        for (int i = length_d-1; i >= 0; i--)
        {
            n.clear(); 
            for (int j = length_d-1; j >= 0; j--) {
                n.push_front(m[ i] * d[j]);
            }
            for (int discharge = length_d - i-1; discharge > 0; discharge--)
                n.push_back(0);
           
            n=bring_to_10(n);
            n0=sum(n0, n);
            n0=bring_to_10(n0);            
        }
        return n0;
    }

    std::deque<unsigned> change(std::string m) //переделываем string в deque
    {      
        int i = 0;
        std::deque<unsigned> v;
        while (m[i]!='\0')
        {            
            v.push_back(static_cast<unsigned>(m[i])-48);//Код в ASCII на 48 больше значения цифр
            i++;
        }
         return v;
    }
    std::string change1(std::deque<unsigned> m)  //переделываем обратно deque в string
    {      
        std::string v="";
        for(auto i : m)
        {
            v.push_back(char(i+48));  
        }
         v.push_back('\0');
         return v;
    }
    std::string num1="";
   
public:
    big_integer& operator=(big_integer&& other) noexcept
    {
        if (num1 == other.num1)
        {
          
            return *this;
        }
        else this->num1 = other.num1;
        return *this;
    }
   
    big_integer operator *(const unsigned m)
    {      
       this->num1 =change1( multiply(m,change(num1)));  
       big_integer p = std::move(*this);
        return p;       
    }
    big_integer operator + (const big_integer& other) // бинарный плюс
    {
        std::deque<unsigned> d = change(this->num1);
        std::deque<unsigned> s = change(other.num1);
       num1 = change1(sum(d, s));
       big_integer t(num1);
       return t;
    }
    big_integer(std::string num)   {   this->num1 = num;   }
    big_integer(big_integer && other) noexcept //move конструктор
    {
         num1 = std::move(other.num1);              
    }
    std::string toString() 
    {
        return this->num1;
    }
};

int main()
{
    setlocale(LC_ALL, "RUS");
    auto a = big_integer("123");
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto number3 = big_integer("51351");
    number1 = std::move(a);

   auto result = number1 + number2 + number3; 
   std::cout << "result= " << result.toString()<< std::endl;
    unsigned g = 215;
    auto g_mult = a * g;
    std::cout <<"g_mult=" << g_mult.toString() <<std::endl;
    big_integer b( std::move(number1));
}
