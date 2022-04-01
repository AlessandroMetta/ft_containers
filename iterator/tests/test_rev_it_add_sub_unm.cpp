#include <iostream>     // std::cout
// #include <vector>       // std::vector
#include "../../vector/vector.hpp"
#include "../iterator.hpp"     // std::reverse_iterator

int main () {
  ft::vector<int> myvector;
  for (int i=0; i<10; i++) myvector.push_back(i);

  typedef ft::vector<int>::iterator iter_type;

  ft::reverse_iterator<ft::vector<int>::iterator> from,until;

  from = myvector.rbegin();
  until = myvector.rend(); 
  std::cout << "myvector has " << (until-from) << " elements.\n";


  ft::reverse_iterator<iter_type> it (myvector.end());
  ft::reverse_iterator<iter_type> rev_it (3 + it);

  std::cout << "The fourth element from the end is: " << *rev_it << '\n';

  return 0;
}