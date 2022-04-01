#include <iostream>
#include "../iterator.hpp"
#include "../../vector/vector.hpp"

int main () {
  ft::vector<int> myvector;
  for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

  typedef ft::vector<int>::iterator iter_type;

  ft::reverse_iterator<iter_type> rev_i( myvector.rend() );
  ft::reverse_iterator<iter_type> rev_it( rev_i - 3 );

  std::cout << "The fourth element from the end is: " << *rev_it << '\n';

  return 0;
}