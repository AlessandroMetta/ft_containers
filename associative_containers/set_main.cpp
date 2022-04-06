#include <vector>
#include <iostream>

int main()
{
    std::vector<int> tree;
    tree.push_back(10);
    tree.push_back(5);
    tree.push_back(15);
    tree.push_back(7);
    tree.push_back(2);
    tree.push_back(12);
    tree.push_back(17);
    // tree.deletion(10);

    std::vector<int>::iterator it = tree.end();
    // it++;
    for (; it!=tree.begin(); --it)
        std::cout << *(it) << std::endl;
    // std::cout << *it << std::endl;
    // std::cout << *(--(tree.end())) << std::endl;


    // tree.print();

    return 0;
}