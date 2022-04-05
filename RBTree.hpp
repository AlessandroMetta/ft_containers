#ifndef __RED_BLACK_TREE_HPP__
# define __RED_BLACK_TREE_HPP__

#include <memory>
#include <iostream>

#include "utils.hpp"

#define BLACK 0
#define RED 1

namespace ft
{
	template < class T >
	struct Node
	{
		struct Node<T> * parent;
		struct Node<T> * left;
		struct Node<T> * right;
		T value;
		bool color;

		Node(const T& val) : parent(NULL), left(NULL), right(NULL), value(val), color(RED) {}
	};
	
	template < class T , class Compare = std::less<T>, class Allocator = std::allocator< Node<T> > >
	class RBTree
	{
	public:
		typedef Node<T> * NodePtr;
		// typedef ft::RBT_iterator    iterator;
	
	private: //private member functions


		void printHelper(NodePtr root, std::string indent, bool last) {
			// print the tree structure on the screen
			if (root != NULL) {
			std::cout<<indent;
			if (last) {
				std::cout<<"R----";
				indent += "     ";
			} else {
				std::cout<<"L----";
				indent += "|    ";
			}
				
			std::string sColor = root->color?"RED":"BLACK";
			std::cout<<root->value<<"("<<sColor<<")"<<std::endl;
			printHelper(root->left, indent, false);
			printHelper(root->right, indent, true);
			}
		}

		void deleteAllNodes(NodePtr node)
		{
			if (node)
			{
				if (node->left)
					deleteAllNodes(node->left);
				if (node->right)
					deleteAllNodes(node->right);
				a.destroy(node);
				a.deallocate(node, 1);
			}
		}

		bool isRed(NodePtr k)
		{
			if (!k) return BLACK;
			return k->color == RED;
		};

		NodePtr minimum(NodePtr node) {
			while (node->left != NULL) {
				node = node->left;
			}
			return node;
		}

		void left_rotate(NodePtr x) {
			NodePtr y = x->right;
			x->right = y->left;
			if (y->left != NULL) {
				y->left->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == nullptr) {
				this->root = y;
			} else if (x == x->parent->left) {
				x->parent->left = y;
			} else {
				x->parent->right = y;
			}
			y->left = x;
			x->parent = y;
		}

		void right_rotate(NodePtr x) {
			NodePtr y = x->left;
			x->left = y->right;
			if (y->right != NULL) {
				y->right->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == nullptr) {
				this->root = y;
			} else if (x == x->parent->right) {
				x->parent->right = y;
			} else {
				x->parent->left = y;
			}
			y->right = x;
			x->parent = y;
		}

		void fixOrphan(NodePtr dead, NodePtr orphan)
		{
			if (dead->parent == NULL)
				root = orphan;
			else if (dead == dead->parent->left)
				dead->parent->left = orphan;
			else
				dead->parent->right = orphan;
			if (orphan)
				orphan->parent = dead->parent;
		}

		void balance_after_insetion(NodePtr k)
		{
			NodePtr u;
			while (isRed(k->parent))
			{
				if (k->parent == k->parent->parent->right)
				{
					u = k->parent->parent->left;
					if (isRed(u))
					{
						k->parent->color = BLACK;
						u->color = BLACK;
						k->parent->parent->color = RED;
						k = k->parent->parent;
					}
					else
					{
						if (k == k->parent->left)
						{
							k = k->parent;
							right_rotate(k);
						}
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						left_rotate(k->parent->parent);
					}
				}
				else
				{
					u = k->parent->parent->right;
					if (isRed(u))
					{
						k->parent->color = BLACK;
						u->color = BLACK;
						k->parent->parent->color = RED;
						k = k->parent->parent;
					}
					else
					{
						if (k == k->parent->right)
						{
							k = k->parent;
							left_rotate(k);
						}
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						right_rotate(k->parent->parent);
					}
				}
				if (k == root)
				{
					break;
				}
			}
			root->color = BLACK;
		};

		void balance_after_deletion(NodePtr x)
		{
			NodePtr s;
			while (x != root && x->color == BLACK)
			{
				if(x == x->parent->left)
				{
					s = x->parent->right;
					if (isRed(s))
					{
						s->color = BLACK;
						x->parent->color = RED;
						left_rotate(x->parent);
						s = x->parent->right;
					}
					if (((s->left && !isRed(s->left)) || !s->left)
						&& ((s->right && !isRed(s->right)) || !s->right))
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if ((s->right && !isRed(s->right)) || !s->right)
						{
							s->color = RED;
							if (s->left)
								s->left->color = BLACK;
							right_rotate(s);
							s = x->parent->right;
						}
						s->color = x->parent->color;
						x->parent->color = BLACK;
						if (s->right)
							s->right->color = BLACK;
						left_rotate(x->parent);
						x = root;
					}
				}
				else
				{
					s = x->parent->left;
					if (isRed(s))
					{
						s->color = BLACK;
						x->parent->color = RED;
						right_rotate(x->parent);
						s = x->parent->left;
					}
					if (((s->left && !isRed(s->left)) || !s->left)
						&& ((s->right && !isRed(s->right)) || !s->right))
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if ((s->left && !isRed(s->left)) || !s->left)
						{
							s->color = RED;
							if (s->right)
								s->right->color = BLACK;
							left_rotate(s);
							s = x->parent->left;
						}
						s->color = x->parent->color;
						x->parent->color = BLACK;
						if (s->left)
							s->left->color = BLACK;
						right_rotate(x->parent);
						x = root;
					}
				}
			}
			x->color = BLACK;
		};

	public:

		RBTree(const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : root(NULL), a(alloc) {};
		~RBTree()
		{
			deleteAllNodes(root);
		};

		// void insertion(T z)
		ft::pair<NodePtr, bool> insertion(T z)
		{
			NodePtr father = NULL;
			NodePtr search = root;
			while (search != NULL)
			{
				father = search;
				if (z == search->value)
					return ft::make_pair(search, false);
				// if(!value_compare()(search->value, z))
				if(z < search->value)
					search = search->left;
				else
					search = search->right;
			}
			search = a.allocate( 1 );
			a.construct( search, Node<T>(z) );
			search->parent = father;
			if (father == NULL)
				root = search;
			else if(z < father->value)
				father->left = search;
			else
				father->right = search;
			balance_after_insetion(search);
			return ft::make_pair(search, true);
		}

		void deletion(T z)
		{
			NodePtr toDelete = root;
			NodePtr toBalance = NULL;
			while (toDelete != NULL && z != toDelete->value)
			{
				if(z < toDelete->value)
					toDelete = toDelete->left;
				else
					toDelete = toDelete->right;
			}
			if  (toDelete == NULL)
				return ;
			bool original_color = toDelete->color;
			if (toDelete->left == NULL)
			{
				toBalance = toDelete->right;
				fixOrphan(toDelete, toDelete->right);
			}
			else if (toDelete->right == NULL)
			{
				toBalance = toDelete->left;
				fixOrphan(toDelete, toDelete->left);
			}
			else
			{
				NodePtr tmp = minimum(toDelete->right);
				original_color = tmp->color;
				toBalance = tmp->right;
				if (tmp->parent == toDelete)
					toBalance->parent = tmp;
				else
				{
					fixOrphan(tmp, tmp->right);
					tmp->right = toDelete->right;
					tmp->right->parent = tmp;
				}
				fixOrphan(toDelete, tmp);
				tmp->left = toDelete->left;
				tmp->left->parent = tmp;
				tmp->color = toDelete->color;
			}
			a.destroy(toDelete);
			a.deallocate(toDelete, 1);
			if (original_color == BLACK && toBalance != NULL)
				balance_after_deletion(toBalance);
		}

		void print()
		{
			if (root) {
				printHelper(this->root, "", true);
		}
	}
	
	private:
		NodePtr root;
		Allocator a;
		Compare	comparison;
	};
	
} // namespace ft


#endif