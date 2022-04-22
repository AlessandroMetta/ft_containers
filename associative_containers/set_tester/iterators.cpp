#include "../set.hpp"
#include <set>

int main()
{
	typedef	int									key_type;

	typedef	std::set< key_type >				std_set;
	typedef	std_set::iterator					std_set_it;
	typedef	std_set::const_iterator				std_set_const_it;

	typedef	ft::set< key_type >					your_set;
	typedef	your_set::iterator					your_set_it;
	typedef	your_set::const_iterator			your_set_const_it;

	your_set	test_your_set;
	test_your_set.insert(10);
	test_your_set.insert(5);
	test_your_set.insert(15);
	test_your_set.insert(7);
	test_your_set.insert(2);
	test_your_set.insert(12);
	test_your_set.insert(17);
	test_your_set.insert(11);
	test_your_set.insert(13);

	std_set		test_std_set;
	test_std_set.insert(10);
	test_std_set.insert(5);
	test_std_set.insert(15);
	test_std_set.insert(7);
	test_std_set.insert(2);
	test_std_set.insert(12);
	test_std_set.insert(17);
	test_std_set.insert(11);
	test_std_set.insert(13);

	std::cout << "testing iterator" << std::endl;

	your_set_it your_first = test_your_set.begin();
	your_set_it your_last = test_your_set.end();
	your_set_const_it your_const_first = test_your_set.begin();
	your_set_const_it your_const_last = test_your_set.end();

	std_set_it std_first = test_std_set.begin();
	std_set_it std_last = test_std_set.end();
	std_set_const_it std_const_first = test_std_set.begin();
	std_set_const_it std_const_last = test_std_set.end();

	std::cout << "your_set.begin() = " << *your_first << "; std_set.begin() = " << *std_first << std::endl;
	std::cout << "your_set.begin()(const) = " << *your_const_first << "; std_set.begin()(const) = " << *std_const_first << std::endl;
	std::cout << "your_set.end() = " << *your_last << "; std_set.end() = " << *std_last << std::endl;
	std::cout << "your_set.end()(const) = " << *your_const_last << "; std_set.end()(const) = " << *std_const_last << std::endl;
	
	std::cout << "\nyour_set print all element in ascending order" << std::endl;
	while (your_first != your_last)
	{
		std::cout << *your_first++ << ", ";
	}

	std::cout << "\nstd_set print all element in ascending order" << std::endl;
	while (std_first != std_last)
	{
		std::cout << *std_first++ << ", ";
	}
	
	std::cout << "\n\ntesting reverse_iterator" << std::endl;
	
	typedef	your_set::reverse_iterator			your_set_reverse_it;
	typedef	your_set::const_reverse_iterator	your_set_const_reverse_it;
	typedef	std_set::reverse_iterator			std_set_reverse_it;
	typedef	std_set::const_reverse_iterator		std_set_const_reverse_it;

	your_set_reverse_it			your_rev_first = test_your_set.rbegin();
	your_set_reverse_it			your_rev_last = test_your_set.rend();
	your_set_const_reverse_it	your_const_rev_first = test_your_set.rbegin();
	your_set_const_reverse_it	your_const_rev_last = test_your_set.rend();
	
	std_set_reverse_it			std_rev_first = test_std_set.rbegin();
	std_set_reverse_it			std_rev_last = test_std_set.rend();
	std_set_const_reverse_it	std_const_rev_first = test_std_set.rbegin();
	std_set_const_reverse_it	std_const_rev_last = test_std_set.rend();

	std::cout << "your_set.rbegin() = " << *your_rev_first  << "; std_set.rbegin() = " << *std_rev_first << std::endl;
	std::cout << "your_set.rbegin()(const) = " << *your_const_rev_first  << "; std_set.rbegin()(const) = " << *std_const_rev_first << std::endl;
	std::cout << "your_set.rend() = " << *--your_rev_last << "; std_set.rend() = " << *--std_rev_last << std::endl;
	std::cout << "your_set.rend()(const) = " << *--your_const_rev_last  << "; std_set.rend()(const) = " << *--std_const_rev_last << std::endl;

	your_rev_last++;
	std::cout << "\nyour_set print all element in discending order" << std::endl;
	while (your_rev_first != your_rev_last)
	{
		std::cout << *your_rev_first++ << ", ";
	}

	std_rev_last++;
	std::cout << "\nstd_set print all element in discending order" << std::endl;
	while (std_rev_first != std_rev_last)
	{
		std::cout << *std_rev_first++ << ", ";
	}

	return 0;
}