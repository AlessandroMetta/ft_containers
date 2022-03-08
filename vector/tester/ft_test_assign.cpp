#include <iostream>
#include "../vector.hpp"

int main()
{
    ft::vector<char> characters;

    characters.assign(5, 'a');
    for (size_t i = 0; i < characters.size(); i++) std::cout << " " << characters[i];
    std::cout << std::endl;

    return 0;
}
