#include "set.hpp"
#include <iostream>
#include <set>

int main()
{
    ft::set<int> test_set;
    test_set.insert(10);
    test_set.insert(5);
    test_set.insert(15);
    test_set.insert(7);
    test_set.insert(2);
    test_set.insert(12);
    test_set.insert(17);
    test_set.erase(10);

    ft::set<int>::iterator it = test_set.begin();
    for (; it!=test_set.end(); )
    {
        try
        {
            std::cout << *(it) << std::endl;
            it++;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    // ft::set<int>::iterator it = test_set.end();
    // for (; it!=test_set.begin(); )
    // {
    //     --it;
    //     try
    //     {
    //         std::cout << *(it) << std::endl;
    //     }
    //     catch(const std::exception& e)
    //     {
    //         std::cerr << e.what() << '\n';
    //     }
    // }

    return 0;
}