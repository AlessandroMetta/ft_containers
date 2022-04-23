#include "map.hpp"
#include <iostream>
#include <map>

int main()
{
	typedef int									key_type;
	typedef int									mapped_type;
	typedef ft::map < key_type, mapped_type >	map_type;
	typedef ft::pair< key_type, mapped_type >	pair_type;
	typedef map_type::iterator					map_iterator;
	// typedef map_type::reverse_iterator			map_rev_iterator;

	map_type test_map;
	test_map.insert(pair_type(1, 1));
	test_map.insert(pair_type(5, 5));
	test_map.insert(pair_type(15, 15));
	test_map.insert(pair_type(7, 7));
	test_map.insert(pair_type(2, 2));
	test_map.insert(pair_type(12, 12));
	test_map.insert(pair_type(17, 17));
	test_map.insert(pair_type(10, 10));
	// test_map.print();
	// test_map.erase(5); // numeri che danno problemi: 10, 5 e 15

	/*
	{ // test at []
		try
		{
			std::cout << "test at: " << test_map.at(10) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			test_map[10] = 11;
			std::cout << "test at after [] modification: " << test_map.at(10) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{ // test empty, size and max_size
		std::cout << "test empty: " << (test_map.empty() ? "yes" : "no") << std::endl;
		std::cout << "test size: " << test_map.size() << std::endl;
		std::cout << "test max_size: " << test_map.max_size() << std::endl;
	}
	*/
	
	
	/* ERRORS 
	{ // test clear
		map_type clear_test(test_map);
		clear_test.clear();
		std::cout << "test clear: is empty? " << (clear_test.empty() ? "yes" : "no") << std::endl;
	}

	{ // copy constructor test
		map_type test_map_copy(test_map);
		{
			std::cout << "print map in ascending order" << std::endl;
			map_iterator it = test_map_copy.begin();
			while (it != test_map_copy.end())
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
		}
		{
			std::cout << "\n..and in discending order" << std::endl;
			map_rev_iterator it = test_map_copy.rbegin();
			while (it != test_map_copy.rend())
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
		}
	}
 
	{ // assign test
		map_type test_map_assign = test_map;
		{
			std::cout << "print map in ascending order" << std::endl;
			map_iterator it = test_map_assign.begin();
			while (it != test_map_assign.end())
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
		}
		{
			std::cout << "\n..and in discending order" << std::endl;
			map_rev_iterator it = test_map_assign.rbegin();
			while (it != test_map_assign.rend())
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
		}
	}
	*/
	
	if (test_map.count(10))
		std::cout << "test_map.count(10) = é presente" << std::endl;
	else
		std::cout << "test_map.count(10) = non lo é" << std::endl;

	map_iterator it = test_map.find(10);
	std::cout << "it value = " << it->first << std::endl;
	it = test_map.find(90);
	if (it == test_map.end())
		std::cout << "test_map.find(90) == test_map.end()" << std::endl;



	/*
	{
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
	}
	{
		std::cout << "\n..and in discending order" << std::endl;
		map_rev_iterator it = test_map.rbegin();
		while (it != test_map.rend())
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
	}
	*/

	return 0;
}