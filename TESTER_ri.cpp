#include <iostream>
#include <iterator>
#include <vector>
 
int main()
{
    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
 
    using RevIt = std::reverse_iterator<std::vector<int>::iterator>;
 
    const auto it = v.begin() + 3;
    RevIt r_it{it};
 
    std::cout << "*it == " << *it << '\n'
              << "*r_it == " << *r_it << '\n'
              << "*r_it.base() == " << *r_it.base() << '\n'
              << "*(r_it.base()-1) == " << *(r_it.base() - 1) << '\n';
 
    RevIt r_end{v.begin()};
    RevIt r_begin{v.end()};
 
    for (auto it = r_end.base(); it != r_begin.base(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
 
    for (auto it = r_begin; it != r_end; ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}
