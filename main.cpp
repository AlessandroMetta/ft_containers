#include "RBTree.hpp"

int main()
{
    ft::RBTree< ft::pair<std::string, std::string> > tree;
    tree.insertion(ft::make_pair("ciao", "saluto comune"));
    tree.insertion(ft::make_pair("mazzo", "saluto comune"));
    tree.insertion(ft::make_pair("albero", "saluto comune"));
    tree.insertion(ft::make_pair("betulla", "saluto comune"));
    tree.insertion(ft::make_pair("abecedario", "saluto comune"));
    tree.insertion(ft::make_pair("libellula", "saluto comune"));
    tree.insertion(ft::make_pair("zebra", "saluto comune"));

    tree.print();

    return 0;
}