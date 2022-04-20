#include "set.hpp"
#include <iostream>
#include <set>

int main()
{
	typedef	std::string			key_type;
	typedef	ft::set< key_type >	set_type;
	typedef	set_type::iterator	set_iterator;

	//		TEST INSERZIONE/DELEZIONE
	/*set_type	test_set;
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
	test_set.print();
	

	//		TEST ITERATOR SET
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

	it = test_set.end();
	while (it != test_set.begin())
	{
		try
		{
			std::cout << *(it) << std::endl;
			it--;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}*/


	/*set_type testo;
	testo.insert("ciao");
	testo.insert("casa");
	std::cout << "altezza albero == " << testo.size() << std::endl;
	testo.erase("ciao");
	std::cout << "altezza albero == " << testo.size() << std::endl;
	testo.erase("casa");
	if (testo.empty())
			std::cout << "altezza albero vuoto :c" << std::endl;*/

	// TEST SWAP SET

	set_type set1;
	set_type set2;

	set1.insert("set1_uno");
	set1.insert("set1_due");
	set2.insert("set2_uno");
	set2.insert("set2_due");
	

	set1.swap(set2);
	set_iterator it = set1.begin();
	
	std::cout << "elementi in set1:\n" << *it << "\n" << *(++it) << std::endl;
	//std::cout << "elementi in set2:\n" << set2[0] << "\n" << set2[1] << std::endl;
	

	return 0;
}