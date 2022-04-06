#include "RBTree.hpp"

int main()
{
    ft::RBTree< int > tree;
    tree.insertion(10);
    tree.insertion(5);
    tree.insertion(15);
    tree.insertion(7);
    tree.insertion(2);
    tree.insertion(12);
    tree.insertion(17);
    // tree.deletion(10);

    // ft::RBTree_iterator<int, int&, int*> it = tree.end();
    // try
    // {
    //     ++it;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    ft::RBTree_iterator<int, int&, int*> it2 = tree.begin();
    ft::RBTree_iterator<int, int&, int*> it = tree.end();
    for (; it!=it2; it--)
    {
        try
        {
            std::cout << *it << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    /* try
    {
        std::cout << *(--(tree.begin())) << std::endl;
        std::cout << *(--(tree.begin())) << std::endl;
        std::cout << *(--(tree.begin())) << std::endl;
        std::cout << *(--(tree.begin())) << std::endl;
        std::cout << *(--(tree.begin())) << std::endl;
        std::cout << *(--(tree.begin())) << std::endl;
        std::cout << *(--(tree.begin())) << std::endl;
        // std::cout << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    } */




    /* tree.print(); */

    return 0;
}