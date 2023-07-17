#include<string>
#include<vector>
#include<deque>
#include<memory>
#include <iostream>

class big_integer
{
    std::deque<unsigned> sum(std::deque<unsigned> s, std::deque<unsigned> d){
        this->n_2.clear();
        this->num2.clear();
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
        bring_to_10(a);
        return a;
    }
    std::deque<unsigned>bring_to_10(std::deque<unsigned>a){
        int max =a.size();
        for (int i = max - 1; i > 0; i--)
        {
            if (a[i] > 9) {
                a[i - 1] += a[i] / 10;
                a[i] = a[i] % 10;
            }
        }
        if (a[0] > 9) {int k= a[0] / 10;
        a.push_front(k); a[0] %= 10;
        }
        return a;
    }

    std::deque<unsigned> multiply(unsigned s, std::deque<unsigned> d) {
        this -> n_2.clear();
        this->num2.clear();
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

    std::string num1="", num2="";
    std::deque<unsigned> n_1{}, n_2{};
public:
    big_integer &operator=(const big_integer & other){
        if (num1 == other.num1) return *this;
        else {
            num1 = other.num1;
            n_1 = other.n_1;
        }
        return *this;
    }
    std::string operator *(const unsigned m)
    {
        n_2 = multiply(m,this->n_1);       
        this->num2.clear();
        num2 = change1(this->n_2);     
        return num2;

    }
    std::string &operator +(const big_integer& other)
    {
        this->n_2=sum(this->n_1, other.n_1);
        num2 = change1(n_2);
        return num2;
    }
    big_integer(std::string num) :num1{ num }
    {    
        if(!num1.empty())
        n_1=change(num1);        
    }
    big_integer(big_integer && other) //move конструктор
    {
         num1 = other.num1;              
    }
};

int main()
{
    setlocale(LC_ALL, "RUS");
    auto a = big_integer("123");
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    number1 = std::move(a);
    auto result = number1 + number2; 
    std::cout << "result= " << result << std::endl;
    unsigned g = 215;
    auto g_mult = number1 * g;
    std::cout <<"g_mult=" << g_mult<<std::endl;
    big_integer b( std::move(number1));
}
