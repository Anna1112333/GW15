#include<vector>
#include<string>
#include<set>
#include<list>

#include <iostream>

template<typename T>
void  print_container(T& a)
{
    for (std::string g : a)
        std::cout << g<<" ";
    std::cout << std::endl;
}


int main()
{
    std::cout << "Hello World!\n";
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set); // four one three two. помните почему такой порядок? :)

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list); // one, two, three, four

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector); // one, two, three, four
}
