#include "../set.hpp"
#include <set>

int main()
{
	typedef	int									key_type;
	typedef	ft::set< key_type >					set_type;
	typedef	set_type::iterator					set_iterator;
	typedef	set_type::const_iterator			set_const_iterator;


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
	// test_set.print();

	set_iterator first = test_set.begin();
	set_iterator last = test_set.end();
	set_const_iterator const_first = test_set.begin();
	set_const_iterator const_last = test_set.end();

	std::cout << "set.begin() = " << *first << std::endl;
	std::cout << "set.begin()(const) = " << *const_first << std::endl;
	std::cout << "set.end() = " << *last << std::endl;
	std::cout << "set.end()(const) = " << *const_last << std::endl;
	
	typedef	set_type::reverse_iterator			set_reverse_iterator;
	typedef	set_type::const_reverse_iterator	set_const_reverse_iterator;

	set_reverse_iterator rev_first = test_set.rbegin();
	set_reverse_iterator rev_last = test_set.rend();
	set_const_reverse_iterator const_rev_first = test_set.rbegin();
	set_const_reverse_iterator const_rev_last = test_set.rend();
	
	std::cout << "set.rbegin() = " << *rev_first << std::endl;
	std::cout << "set.rbegin()(const) = " << *const_rev_first << std::endl;
	std::cout << "set.rend() = " << *rev_last << std::endl;
	std::cout << "set.rend()(const) = " << *const_rev_last << std::endl;
	
	return 0;
}