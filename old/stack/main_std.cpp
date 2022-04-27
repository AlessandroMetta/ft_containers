#include <stack>
#include <iostream>

int main()
{
    std::stack<int> c1;
    c1.push(5);
    c1.push(2);
    c1.push(51);
    std::cout << "c1.size(): " << c1.size() << '\n';
    std::cout << "c1.top(): " << c1.top() << '\n';
 
    std::stack<int> c2(c1);
    c1.push(8);
    c2.push(9);
    std::stack<int> c3;
	c3 = c1;
    std::cout << "c2.size(): " << c2.size() << '\n';
    std::cout << "c2.top(): " << c2.top() << '\n';
    std::cout << "c1 == c2: " << (c1 == c2 ? "true" : "false") << '\n';
    std::cout << "c1 != c2: " << (c1 != c2 ? "true" : "false") << '\n';
    std::cout << "c1 < c2: " << (c1 < c2 ? "true" : "false") << '\n';
    std::cout << "c1 > c2: " << (c1 > c2 ? "true" : "false") << '\n';
    std::cout << "c1 <= c2: " << (c1 <= c2 ? "true" : "false") << '\n';
    std::cout << "c1 >= c2: " << (c1 >= c2 ? "true" : "false") << '\n';
}