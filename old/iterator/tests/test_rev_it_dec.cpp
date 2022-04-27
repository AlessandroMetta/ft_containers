// reverse_iterator::operator-- example
#include <iostream>     // std::cout
// #include <vector>       // std::vector
#include "../../vector/vector.hpp"

// #include <iterator>     // std::reverse_iterator
#include "../iterator.hpp"     // std::reverse_iterator

int main () {
  ft::vector<int> myvector;
  for (int i=0; i<10; i++) myvector.push_back(i);

  typedef ft::vector<int>::iterator iter_type;

  ft::reverse_iterator<iter_type> rev_begin (myvector.end());
  ft::reverse_iterator<iter_type> rev_end (myvector.begin());

  ft::reverse_iterator<iter_type> rev_iterator(rev_begin);
  while ( rev_iterator != rev_end )
    std::cout << *rev_iterator++ << ' ';
  std::cout << '\n';

  while ( rev_iterator != rev_begin )
    std::cout << *(--rev_iterator) << ' ';
  std::cout << '\n';
  std::cout << '\n';

    std::cout << *rev_iterator << ' ';
  while ( rev_iterator != rev_end - 1 )
    std::cout << *(++rev_iterator) << ' ';
  std::cout << '\n';

    // rev_iterator--;
  while ( rev_iterator != rev_begin - 1 )
    std::cout << *(rev_iterator--) << ' ';
  std::cout << '\n';

  return 0;
}
