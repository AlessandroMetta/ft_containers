#include "set.hpp"

int main()
{
	ft::set<int> uno;
	uno.insert(10);
	uno.insert(20);
	uno.insert(30);
	ft::set<int> due = uno;
	ft::set<int>::iterator first = uno.begin();
	std::cout << "print all element in ascending order" << std::endl;
	while (first != uno.end())
	{
		std::cout << *first++ << ", ";
	}
	return 0;
}