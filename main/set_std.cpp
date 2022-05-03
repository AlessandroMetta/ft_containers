#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> test_set;
	test_set.insert(10);
	test_set.insert(5);
	test_set.insert(15);
	test_set.insert(7);
	test_set.insert(2);
	test_set.insert(12);
	test_set.insert(17);
	test_set.insert(11);
	test_set.insert(13);
	{
		cout << "testing iterator" << endl;
		set<int>::iterator first = test_set.begin();
		set<int>::iterator last = test_set.end();
		set<int>::const_iterator const_first = test_set.begin();
		set<int>::const_iterator const_last = test_set.end();

		cout << "set.begin() = " << *first << endl;
		cout << "set.begin()(const) = " << *const_first << endl;
		cout << "set.end() = " << *last << endl;
		cout << "set.end()(const) = " << *const_last << endl;
		
		cout << "print all element in ascending order" << endl;
		while (first != last)
		{
			cout << *first++ << ", ";
		}
	}
	{	
		cout << "\n\ntesting reverse_iterator" << endl;
		set<int>::reverse_iterator			rev_first = test_set.rbegin();
		set<int>::reverse_iterator			rev_last = test_set.rend();
		set<int>::const_reverse_iterator	const_rev_first = test_set.rbegin();
		set<int>::const_reverse_iterator	const_rev_last = test_set.rend();

		cout << "set.rbegin() = " << *rev_first  << endl;
		cout << "set.rbegin()(const) = " << *const_rev_first  << endl;
		cout << "set.rend() = " << *--rev_last << endl;
		cout << "set.rend()(const) = " << *--const_rev_last  << endl;

		rev_last++;
		cout << "print all element in discending order" << endl;
		while (rev_first != rev_last)
		{
			cout << *rev_first++ << ", ";
		}
	}
	{
		//TEST FIND
		std::cout << "\n\nTEST FIND" << std::endl;
		set<int>::iterator it = test_set.find(11);
		cout << "test_set.find(11) = " << *it << endl;
		it = test_set.find(17);
		cout << "test_set.find(17) = " << *it << endl;
		it = test_set.find(2);
		cout << "test_set.find(2) = " << *it << endl;
		it = test_set.find(90);
		cout << "test_set.find(90) = " << *it << endl;
	}
	{
		//TEST bound
		std::cout << "\nTEST bound" << std::endl;
		set<int>::iterator it = test_set.lower_bound(11);
		set<int>::iterator ti = test_set.upper_bound(11);
		cout << "test_set.lower_bound(11) = " << *it << endl;
		cout << "test_set.upper_bound(11) = " << *ti << endl;

		pair<set<int>::iterator, set<int>::iterator> range = test_set.equal_range(11);
		cout << "test_set.equal_range(11).first = " << *range.first << endl;
		cout << "test_set.equal_range(11).second = " << *range.second << endl;
	}
	{
		std::cout << "\ntest find/count" << std::endl;
		set<std::string> set1;
		set1.insert("set1_uno");
		set1.insert("set1_due");
		set<std::string>::iterator it = set1.find("set1_uno");
		std::cout << "it value = " << *it << std::endl;
		it = set1.find("set1_tre");
		if (it == set1.end())
			std::cout << "(set1.find(\"set1_tre\") == set1.end())" << std::endl;
		if (set1.count("set1_tre"))
			std::cout << "set1.count(\"set1_tre\") = é presente" << std::endl;
		else
			std::cout << "set1.count(\"set1_tre\") = non lo é" << std::endl;
	}
	{
		std::cout << "\ntest erase" << std::endl;
		test_set.erase(5);
		test_set.erase(2);
		std::cout << "tring to erase 11, result: " << test_set.erase(11) << std::endl;
		std::cout << "tring to erase 11, result: " << test_set.erase(11) << std::endl;
	}
	{
		set<int> alice;
		set<int> bob;
		set<int> eve;

		alice.insert(1);
		alice.insert(2);
		alice.insert(3);
		bob.insert(7);
		bob.insert(8);
		bob.insert(9);
		bob.insert(10);
		eve.insert(1);
		eve.insert(2);
		eve.insert(3);
	
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
	}
	return 0;
}