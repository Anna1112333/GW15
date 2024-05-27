#include <thread>
#include <vector>
#include <iostream>
#include <future>
#include <utility>
 using It=std::vector<int>::iterator ;
 int m;

class sorti {
   
    It it0, it1, Im;
    It find(It a, It b) {       
        for (; a < b; a++)
        {
            if (m > *a) {
                m = *a;
                Im = a;
            }
          //  std::cout << *a;
        }
        std::cout << "min = " << m << std::endl;
        return Im;
    }
    public:
    void sort(std::vector<int>& a, int n) {
        Im = a.begin()+n;
        m = a[n];
        
        int s = a.size();
        it0=a.begin()+n;
        if(it0<a.end() - 5)
        it1 = it0 + 4;
        if(s>5)
       while(it1 < a.end()-5)
        {
          // std::future<It> ft = std::async(find, ref(it0), ref(it1));
           find(it0, it1);         
                it1 += 5;
                it0 += 5;
                std::cout<<*Im << std::endl;           
        }
       find(it0, a.end());     
       std::cout << *Im << std::endl;
      //  std::cout << s << std::endl;
        std::swap(a[n], *Im);
        for (auto s : a)
            std::cout << s << " ";
     }
    void sort_all(std::vector<int>& a0) {
        int s = a0.size();
        for (int i = 0; i<s; i++) {
            sort(a0,i);      
        }
    } 
};



int main()
{
    std::vector<int> arr{ 10,7,6,13,8,  4, 19, 20, 5,14 ,   4, 6, 4, 1, 5,    12, 5 };
    sorti a;
   a.sort_all(arr);
   // for (auto x : arr)
      //  std::cout << *it << " ";
}
