#include <iostream>
#include "BSTree.hpp"

int main()
{


	BSTree<int> tree;
	
	tree.insertion(5);
	tree.insertion(2);
	tree.insertion(1);
	tree.insertion(3);
	tree.insertion(7);
	tree.insertion(6);
	tree.insertion(8);

	tree.treeprint();
	std::cout << "\ndeletion of 5\n";
	tree.deletion(5);

/*
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
*/
	tree.treeprint();
}
