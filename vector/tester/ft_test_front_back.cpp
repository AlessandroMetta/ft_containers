#include "../vector.hpp"
#include <iostream>
 
int main()
{
    ft::vector<char> letters;

    letters.push_back('o');
    letters.push_back('m');
    letters.push_back('g');
    letters.push_back('w');
    letters.push_back('t');
    letters.push_back('f');

    if (!letters.empty()) {
        std::cout << "The first character is '" << letters.front() << "'.\n";
        std::cout << "The last character is '" << letters.back() << "'.\n";
    }
}
