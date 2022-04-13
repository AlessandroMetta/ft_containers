#include "set.hpp"
#include <iostream>
#include <set>

int main()
{
	typedef	int			key_type;
	typedef	ft::set< key_type >	set_type;
	typedef	set_type::iterator	set_iterator;

	set_type	test_set;
	test_set.insert(10);
	test_set.insert(5);
	test_set.insert(15);
	test_set.insert(7);
	test_set.insert(2);
	test_set.insert(12);
	test_set.insert(17);
	test_set.insert(11);
	test_set.insert(13);
	test_set.print();
	test_set.erase(10);  // numeri che danno problemi: 10 xk root

	test_set.print();
	/*set_iterator it = test_set.begin();
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
	}*/

	return 0;
}