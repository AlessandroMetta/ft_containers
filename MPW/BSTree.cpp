#include <iostream>
#include "BSTree.hpp"

int main()
{

/*
	BSTree<int> tree;
	
	tree.BSTree_insertion(5);
	tree.BSTree_insertion(2);
	tree.BSTree_insertion(1);
	tree.BSTree_insertion(3);
	tree.BSTree_insertion(7);
	tree.BSTree_insertion(6);
	tree.BSTree_insertion(8);
*/

	BSTree<char> tree;

	tree.insertion('E');
	tree.insertion('A');
	tree.insertion('C');
	tree.insertion('R');
	tree.insertion('H');
	tree.insertion('N');
	tree.insertion('M');
	tree.insertion('L');
	tree.insertion('P');

	tree.treeprint();
	std::cout << "\ndeletion of E\n";
	tree.deletion('E');

	tree.treeprint();
}
