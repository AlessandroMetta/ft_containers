// reverse_iterator::operator- example
#include <iostream>
#include "../../vector/vector.hpp"
#include "../iterator.hpp"

int main () {
  ft::vector<int> myvector;
  for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

  typedef ft::vector<int>::iterator iter_type;

  ft::reverse_iterator<iter_type> rev_iterator;

  rev_iterator = myvector.rend() - 3;

  std::cout << "rev_iterator now points to: " << *rev_iterator << '\n';

  return 0;
}