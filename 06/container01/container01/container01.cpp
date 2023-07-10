#include<utility>
#include<iomanip>
#include<map>
#include<vector>
#include<deque>
#include <iostream>
#include<algorithm>
class massive
{
    std::pair<char, int> par;
    int max = 0;
public:
    std::map<char, int> simbols;
    massive(std::string mas) 
    {
        for (std::string::iterator i = mas.begin(); i != mas.end(); ++i)
        {
            par=std::make_pair (*i, 1);
            if (simbols.contains(par.first)) simbols[*i]++;
            else simbols.insert(par);
            if (max < simbols[*i]) max = simbols[*i];
        }
        std::cout << "[OUT]: \n";
 for (int i = max; i>0; --i)
        for(std::map<char, int >::iterator it = simbols.begin();it != simbols.end(); ++it)
{
     if(i==it->second)
    std::cout << it->first << ": " << it->second << " " <<  "\n";
}
    }
};
int main()
{
    std::string str;
    setlocale(LC_ALL, "RUS");
    std::cout << "[IN]: ";
    std::cin >> str;
    massive b(str);
}

