#include "../set.hpp"
#include <set>

int main()
{

	typedef	int			key_type;
	typedef	ft::set< key_type >	set_type;
	typedef	set_type::iterator	set_iterator;
	typedef ft::pair<set_iterator, set_iterator> set_pair;

	//		TEST INSERZIONE/DELEZIONE
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
	test_set.erase(10);
	// test_set.print();

	{
		//TEST FIND
		set_iterator it = test_set.find(11);
		std::cout << "test_set.find(11) = " << *it << std::endl;
		it = test_set.find(17);
		std::cout << "test_set.find(17) = " << *it << std::endl;
		it = test_set.find(2);
		std::cout << "test_set.find(2) = " << *it << std::endl;
		it = test_set.find(90);
		std::cout << "test_set.find(90) = " << *it << std::endl;
	}
	{
		//TEST bound
		set_iterator it = test_set.lower_bound(11);
		set_iterator ti = test_set.upper_bound(11);
		std::cout << "test_set.lower_bound(11) = " << *it << std::endl;
		std::cout << "test_set.upper_bound(11) = " << *ti << std::endl;

		set_pair range = test_set.equal_range(11);
		std::cout << "test_set.equal_range(11).first = " << *range.first << std::endl;
		std::cout << "test_set.equal_range(11).second = " << *range.second << std::endl;
	}

}