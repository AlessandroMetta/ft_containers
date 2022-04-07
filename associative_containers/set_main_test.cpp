#include "set.hpp"
#include <iostream>
#include <set>

int main()
{
	typedef	std::string			key_type;
	typedef	ft::set< key_type >	set_type;
	typedef	set_type::iterator	set_iterator;

	set_type	test_set;
	test_set.insert("10");
	test_set.insert("5");
	test_set.insert("15");
	test_set.insert("7");
	test_set.insert("2");
	test_set.insert("12");
	test_set.insert("17");
	test_set.erase("10");

	set_iterator it = test_set.begin();
	while (it != test_set.end())
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

	return 0;
}