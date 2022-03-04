#include <iostream>
#include "vector.hpp"

template<class T>
void print(T vect)
{
    for (size_t i = 0; i < vect.size(); i++) std::cout << "ft::vect[" << i << "] = " << vect[i] << std::endl;
}

int main()
{
    ft::vector<int> vect;
    vect.push_back(10);
    vect.push_back(9);
    vect.push_back(8);
    vect.push_back(7);
    vect.push_back(6);
    vect.push_back(5);
    vect.push_back(4);
    vect.push_back(3);
    vect.push_back(2);
    // for (size_t i = 0; i < vect.size(); i++) std::cout << "ft::vect[" << i << "] = " << vect[i] << std::endl;
    print(vect);
    
    ft::vector<int> vect1(vect);
    // for (size_t i = 0; i < vect1.size(); i++) std::cout << "ft::vect1[" << i << "] = " << vect1[i] << std::endl;
    print(vect1);

    ft::vector<int> vect2(5, 999);
    // for (size_t i = 0; i < vect2.size(); i++) std::cout << "ft::vect2[" << i << "] = " << vect2[i] << std::endl;
    print(vect2);
    return 0;
}
