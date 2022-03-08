#include <iostream>
#include <vector>

template<class T>
void print(T& vect)
{
    for (size_t i = 0; i < vect.size(); i++) std::cout << " " << vect[i];
    std::cout << std::endl;
}

int main()
{
    std::vector<char> characters;
 
    characters.assign(5, 'a');
    print(characters);
 
    const std::string extra(6, 'b');
    characters.assign(extra.begin(), extra.end());
    print(characters);

    return 0;
}
