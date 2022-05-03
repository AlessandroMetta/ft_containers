#include "../srcs/map.hpp"
#include <iostream>
#include <map>

int main()
{
	typedef int									key_type;
	typedef int									mapped_type;
	typedef ft::map < key_type, mapped_type >	map_type;
	typedef ft::pair< key_type, mapped_type >	pair_type;
	typedef map_type::iterator					map_iterator;
	typedef map_type::reverse_iterator			map_rev_iterator;

	map_type ft_map;
	ft_map.insert(pair_type(1, 1));
	ft_map.insert(pair_type(5, 5));
	ft_map.insert(pair_type(15, 15));
	ft_map.insert(pair_type(7, 7));
	ft_map.insert(pair_type(2, 2));
	ft_map.insert(pair_type(12, 12));
	ft_map.insert(pair_type(17, 17));
	ft_map.insert(pair_type(10, 10));
	ft_map.erase(5);
	
	{ // test at []
		try
		{
			std::cout << "testing AT(10): " << ft_map.at(10) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			ft_map[10] = 11;
			std::cout << "testing [10] = 11: " << ft_map.at(10) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			ft_map[90] = 11;
			std::cout << "testing [90] = 11, ps 90 does not exist: " << ft_map.at(90) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{ // test empty, size and max_size
		std::cout << "test empty: " << (ft_map.empty() ? "yes" : "no") << std::endl;
		std::cout << "test size: " << ft_map.size()<< std::endl;
	}

	{ // test clear
		map_type clear_test(ft_map);
		clear_test.clear();
		std::cout << "test clear: is empty? " << (clear_test.empty() ? "yes" : "no") << std::endl;
		std::cout << "test clear: is empty? " << clear_test.size() << std::endl;
	}

	{ // copy constructor test
		map_type ft_map_copy(ft_map);
		{
			std::cout << "print map in ascending order" << std::endl;
			map_iterator it = ft_map_copy.begin();
			while (it != ft_map_copy.end())
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
			map_rev_iterator it = ft_map_copy.rbegin();
			while (it != ft_map_copy.rend())
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
		map_type ft_map_assign = ft_map;
		{
			std::cout << "print map in ascending order" << std::endl;
			map_iterator it = ft_map_assign.begin();
			while (it != ft_map_assign.end())
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
			map_rev_iterator it = ft_map_assign.rbegin();
			while (it != ft_map_assign.rend())
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
	
	{
		// Test count and find
		if (ft_map.count(10))
			std::cout << "test count(10) = é presente" << std::endl;
		else
			std::cout << "test count(10) = non é presente" << std::endl;

		map_iterator it = ft_map.find(10);
		std::cout << "it value = " << it->first << std::endl;
		it = ft_map.find(90);
		if (it == ft_map.end())
			std::cout << "ft_map.find(90) == ft_map.end()" << std::endl;
	}
	{
		// TEST bound
		std::cout << "\nTEST bound" << std::endl;
		map_iterator it = ft_map.lower_bound(1);
		map_iterator ti = ft_map.upper_bound(1);
		std::cout << "test_set.lower_bound(1) = " << it->first << std::endl;
		std::cout << "test_set.upper_bound(1) = " << ti->first << std::endl;

		ft::pair<map_iterator, map_iterator> range = ft_map.equal_range(1);
		std::cout << "test_set.equal_range(1).first = " << range.first->first << std::endl;
		std::cout << "test_set.equal_range(1).second = " << range.second->first << std::endl;
	}

    std::cout << "TESTING RELATIONAL OPERATOR\n";
    ft::map<int, char> alice;
	alice.insert(pair_type(1, 'a'));
	alice.insert(pair_type(2, 'b'));
	alice.insert(pair_type(3, 'c'));

    ft::map<int, char> bob;
	bob.insert(pair_type(7, 'Z'));
	bob.insert(pair_type(8, 'Y'));
	bob.insert(pair_type(9, 'X'));
	bob.insert(pair_type(10, 'W'));
	
    ft::map<int, char> eve;
	eve.insert(pair_type(1, 'a'));
	eve.insert(pair_type(2, 'b'));
	eve.insert(pair_type(3, 'c'));

 
    std::cout << std::boolalpha;
 
    // Compare non equal containers
    std::cout << "alice == bob returns " << (alice == bob) << '\n';
    std::cout << "alice != bob returns " << (alice != bob) << '\n';
    std::cout << "alice <  bob returns " << (alice < bob) << '\n';
    std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
    std::cout << "alice >  bob returns " << (alice > bob) << '\n';
    std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
 
    std::cout << '\n';
 
    // Compare equal containers
    std::cout << "alice == eve returns " << (alice == eve) << '\n';
    std::cout << "alice != eve returns " << (alice != eve) << '\n';
    std::cout << "alice <  eve returns " << (alice < eve) << '\n';
    std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
    std::cout << "alice >  eve returns " << (alice > eve) << '\n';
    std::cout << "alice >= eve returns " << (alice >= eve) << '\n';

	return 0;
}