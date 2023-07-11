#include<algorithm>
#include<vector>
#include <iostream>
void vec(std::vector<int> m)
{
    std::sort(m.begin(), m.end());
    std::vector<int>::iterator i;
    i = m.begin();
    int t = *(m.end()-1);
    std::unique(i, m.end());
   do {
        i++;
    } while (*i != t);
    m.erase(i+1, m.end());
    std::cout << "[OUT]: ";
    for (int q : m) std::cout << q << " ";
    std::cout << std::endl;
}


int main()
{
    std::vector<int>a{5, 55, 6, 8, 5, 6, 4, 8, 4, 1, 2, 6, 6, 4, 22};
    std::cout << "[IN]: ";
    for (int i : a)
        std::cout << i << " "; 
    std::cout<<std::endl;
    vec(a);

}
