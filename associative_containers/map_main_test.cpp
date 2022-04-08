#include "map.hpp"
#include <iostream>
#include <map>

int main()
{
	typedef std::string							key_type;
	typedef int									mapped_type;
	typedef ft::map < key_type, mapped_type >	map_type;
	typedef ft::pair< key_type, mapped_type >	pair_type;
	typedef map_type::iterator					map_iterator;

	map_type test_map;
	test_map.insert(pair_type("1", 1));
	test_map.insert(pair_type("5", 5));
	test_map.insert(pair_type("15", 15));
	test_map.insert(pair_type("7", 7));
	test_map.insert(pair_type("2", 2));
	test_map.insert(pair_type("12", 12));
	test_map.insert(pair_type("17", 17));
	test_map.insert(pair_type("10", 10));
	test_map.print();
	// test_map.erase("5");

	std::cout << "print map in ascending order" << std::endl;
	map_iterator it = test_map.begin();
	while (it != test_map.end())
	{
		try
		{
			std::cout << it->first << " : " << it->second << std::endl;
			it++;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	return 0;
}