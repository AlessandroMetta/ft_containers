#include "../srcs/stack.hpp"
#include <deque>
#include <iostream>

int main()
{
	{
		ft::stack<int> c1;
		c1.push(5);
		std::cout << c1.size() << '\n';
	
		ft::stack<int> c2(c1);
		std::cout << c2.size() << '\n';
	
		std::deque<int> deq;
		deq.push_back(3);
		deq.push_back(1);
		deq.push_back(4);
		deq.push_back(1);
		deq.push_back(5);

		ft::stack< int, std::deque<int> > c3(deq); // overload (2)
		std::cout << c3.size() << '\n';
		std::cout << c3.top() << '\n';
	}
	{
		std::cout << std::boolalpha;
	
		ft::stack<int> container;
	
		std::cout << "Initially, container.empty(): " << container.empty() << '\n';
	
		container.push(42);
		std::cout << "After adding elements, container.empty(): " << container.empty() << '\n';
	}
	{
		ft::stack<int> container;
	
		std::cout << "Initially, container.size(): " << container.size() << '\n';
	
		for (int i = 0; i < 7; ++i)
			container.push(i);
	
		std::cout << "After adding elements, container.size(): " << container.size() << '\n';
	}
}