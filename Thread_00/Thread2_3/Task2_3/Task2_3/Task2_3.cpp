//#define __cpp_lib_scoped_lock
#include <iostream>
#include <thread>
#include <mutex>

//#include <functional>
//using namespace std;
class Data
{
public:
    Data(int a1, std::string str1) : a{ a1 }, str{ str1 } {};
   std::mutex mt;
   void get() {
       std::cout << a << "  " << str << std::endl;
   }  
    int a;
    std::string str;    
};

void swap(Data& n, Data& m) {    
   std::lock(n.mt, m.mt);
   int k;
   k = n.a;   n.a = m.a;   m.a = k;
   std::string st;
   st = n.str;   n.str = m.str;   m.str = st;
   m.mt.unlock();   n.mt.unlock();
}
void swap1(Data& n, Data& m) {
    std::lock_guard<std::mutex>lock(n.mt);
    std::lock_guard<std::mutex>lock1(m.mt);
    int k;
    k = n.a;   n.a = m.a;   m.a = k;
    std::string st;
    st = n.str;   n.str = m.str;   m.str = st;   
}
void swap2(Data& n, Data& m) { 
    std::unique_lock<std::mutex> lk1(n.mt, std::defer_lock);
   std::unique_lock<std::mutex> lk2(m.mt, std::defer_lock);
     int k;
    k = n.a;   n.a = m.a;   m.a = k;
    std::string st;
    std::lock(lk1, lk2);
    st = n.str;   n.str = m.str;   m.str = st;
  
}

void swap3(Data& n, Data& m) {  
   std::scoped_lock lk(n.mt, m.mt);  
    int k;
    k = n.a;   n.a = m.a;   m.a = k;
    std::string st;   
    st = n.str;   n.str = m.str;   m.str = st;  
}

int main()
{
    Data n0(1, "an"), m0(2, "am");
    n0.get();
    swap3(n0, m0);
    n0.get();   
   
}

