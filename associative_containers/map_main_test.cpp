#include "map.hpp"
#include <iostream>
#include <map>

int main()
{
    ft::map< std::string, int > test_map;
    test_map.insert(ft::pair< std::string, int >("1", 1));
    test_map.insert(ft::pair< std::string, int >("5", 5));
    test_map.insert(ft::pair< std::string, int >("15", 15));
    test_map.insert(ft::pair< std::string, int >("7", 7));
	test_map.insert(ft::pair< std::string, int >("2", 2));
	test_map.insert(ft::pair< std::string, int >("12", 12));
	test_map.insert(ft::pair< std::string, int >("17", 17));
	test_map.insert(ft::pair< std::string, int >("10", 10));
    test_map.erase("10");

    ft::map< std::string, int >::iterator it = test_map.begin();
    for (; it!=test_map.end(); )
    {
        try
        {
            std::cout << it->first << ":" << it->second << std::endl;
            it++;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    // ft::map<int>::iterator it = test_map.end();
    // for (; it!=test_map.begin(); )
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