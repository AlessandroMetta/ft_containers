#include <iostream>
#include <vector>
#include "vector.hpp"

template<class T>
void print(T& vect)
{
    for (size_t i = 0; i < vect.size(); i++) std::cout << "ft::vect[" << i << "] = " << vect[i] << std::endl;
}

int main()
{/*
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
    print(vect);
    std::cout << vect.size() << std::endl;
    std::cout << vect.capacity() << std::endl;
    vect.pop_back();
    std::cout << vect.size() << std::endl;
    std::cout << vect.capacity() << std::endl;
    print(vect);

    
    std::cout << vect.max_size() << std::endl;

    ft::vector<int> vect1(vect);
    print(vect1);

    ft::vector<int> vect2(5, 999);
    print(vect2);*/

    ft::vector<int> myvector;

    // set some initial content:
    for (int i=1;i<10;i++) myvector.push_back(i);

    myvector.resize(5);
    myvector.resize(8,100);
    myvector.resize(12);

    std::cout << "myvector contains:";
    for (size_t i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
    std::cout << '\n';

    return 0;
}
