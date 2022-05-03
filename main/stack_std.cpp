#include <stack>
#include <deque>
#include <iostream>

int main()
{
	{
		std::stack<int> c1;
		c1.push(5);
		std::cout << c1.size() << '\n';
	
		std::stack<int> c2(c1);
		std::cout << c2.size() << '\n';
	
		std::deque<int> deq;
		deq.push_back(3);
		deq.push_back(1);
		deq.push_back(4);
		deq.push_back(1);
		deq.push_back(5);

		std::stack<int> c3(deq); // overload (2)
		std::cout << c3.size() << '\n';
		std::cout << c3.top() << '\n';
	}
	{
		std::cout << std::boolalpha;
	
		std::stack<int> container;
	
		std::cout << "Initially, container.empty(): " << container.empty() << '\n';
	
		container.push(42);
		std::cout << "After adding elements, container.empty(): " << container.empty() << '\n';
	}
	{
		std::stack<int> container;
	
		std::cout << "Initially, container.size(): " << container.size() << '\n';
	
		for (int i = 0; i < 7; ++i)
			container.push(i);
	
		std::cout << "After adding elements, container.size(): " << container.size() << '\n';
	}
}