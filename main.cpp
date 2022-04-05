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
    tree.deletion(10);


    tree.print();

    return 0;
}