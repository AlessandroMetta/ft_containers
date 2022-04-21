#include "set.hpp"
#include <iostream>
#include <set>
#include <vector>

int main()
{
	// typedef	int			key_type;
	typedef	std::string			key_type;
	typedef	ft::set< key_type >	set_type;
	// typedef	set_type::iterator	set_iterator;
	// typedef	set_type::reverse_iterator	set_reverse_iterator;

	/* TEST ERASE
	set_type	test_set;
	set_iterator it = test_set.insert(10).first;
	test_set.insert(5);
	test_set.insert(15);
	test_set.insert(7);
	test_set.insert(2);
	test_set.insert(12);
	test_set.insert(17);
	test_set.insert(11);
	test_set.insert(13);
	std::cout << "17 erased\n";
	test_set.erase(17);
	test_set.print();
	std::cout << "\nfirst element erased\n";
	test_set.erase(test_set.begin());
	test_set.print();
	std::cout << "half of the set erased" << std::endl;
	test_set.erase(test_set.begin(), it);
	test_set.print();
	*/
	
	/* TEST ITERATOR SET
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

	/* TEST SWAP SET
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
	*/

	/*	TEST INSERTION WITH HINT
	set_type set1;

	set1.insert("set2_uno");
	set1.insert("set2_due");

	set_iterator it2 = set1.begin();

	set1.insert(it2, "set2_tre");

	set_reverse_iterator it = set1.rbegin();
	
	std::cout << "elementi in set1:\n";
	while (it != set1.rend())
		std::cout << *it++ << std::endl;
	*/
	
	/*  TEST RANGE INSERTION 
	set_type set1;
	
	std::vector<std::string> words;
	words.push_back("sky");
	words.push_back("cloud");
	words.push_back("rainbow");
	words.push_back("wind");
	std::vector<std::string>::iterator it_b = words.begin();
	std::vector<std::string>::iterator it_e = words.end();

	// set_type set2;
	// set2.insert("sky");
	// set2.insert("cloud");
	// set2.insert("rainbow");
	// set2.insert("wind");
	// set_iterator it_b = set2.begin();
	// set_iterator it_e = set2.end();

	set1.insert(it_b, it_e);
	
	set_iterator it = set1.begin();
	std::cout << "elementi in set1:\n";
	while (it != set1.end())
		std::cout << *it++ << std::endl;
	*/

	/* TEST CLEAR
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
	test_set.clear();
	test_set.print();
	*/

	/* TEST CLEAR */
	set_type	test_set;
	test_set.insert("10");
	test_set.insert("5");
	test_set.insert("15");
	test_set.insert("7");
	test_set.insert("2");
	test_set.insert("12");
	test_set.insert("17");
	test_set.insert("11");
	test_set.insert("13");
	test_set.erase("5");
	test_set.erase("2");
	test_set.erase("11");
	test_set.erase("11");
	test_set.print();
	// */
	
	return 0;
}