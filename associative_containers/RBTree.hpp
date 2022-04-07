#ifndef __RED_BLACK_TREE_HPP__
# define __RED_BLACK_TREE_HPP__

#include <memory>
#include <iostream>
#include "../utils.hpp"

#define BLACK 0
#define RED 1

namespace ft
{
	template < class T > struct Node	{
		typedef	struct Node< T >*	NodePtr;

		T value;
		NodePtr parent;
		NodePtr left;
		NodePtr right;
		bool color;

		Node(const T& val, NodePtr parent) : value(val), parent(parent), left(NULL), right(NULL), color(RED) {}
	}; // end of Node structure

	template < class T > struct RBTree_iterator	{

		typedef	Node< T >*				NodePtr;
		typedef	RBTree_iterator< T >	Self;
		typedef T&						Ref;
		typedef T*						Ptr;

		NodePtr father;
		NodePtr node;

		RBTree_iterator(NodePtr node) : node(node), father(NULL) {}
		RBTree_iterator(NodePtr end, NodePtr last) : node(end), father(last) {}

		Ref operator*()
		{
			if (node == NULL)
				throw std::out_of_range("Out of range");
			return node->value;
		}
		Ptr operator->()
		{
			if (node == NULL)
				throw std::out_of_range("Out of range");
			return &node->value;
		}
		bool operator!=(const Self& s) const
		{
			return node != s.node;
		} 
		bool operator==(const Self& s) const
		{
			return node == s.node;
		}
		Self& operator++()
		{
			if (node == NULL)
				throw std::out_of_range("Out of range");
			else if (node->right)
			{
				NodePtr left = node->right;
				while (left->left)
					left = left->left;
				node = left;
			}
			else
			{
				NodePtr cur = node;
				NodePtr father = cur->parent;
				while (father && cur == father->right)
				{
					cur = cur->parent;
					father = father->parent;
				}
				node = father;
			}
			return *this;
		}
		Self& operator--()
		{
			if (node == NULL)
			{
				if (father != NULL)
					node = father;
				else
					throw std::out_of_range("Out of range");
			}
			else if (node->left)
			{
				NodePtr right = node->left;
				while (right->right)
					right = right->right;
				node = right;
			}
			else
			{
				NodePtr cur = node;
				NodePtr father = cur->parent;
				while (father && cur == father->left)
				{
					cur = cur->parent;
					father = father->parent;
				}
				node = father;
			}
			return *this;
		}
		Self operator++(int)
		{
			Self tmp = *this;
			++(*this);
			return tmp;
		}
		Self operator--(int)
		{
			Self tmp = *this;
			--(*this);
			return tmp;
		}
	}; // end of RBTree_iterator structure
	
	template < class K ,
				class T ,
				class Compare = std::less< T >,
				class Allocator = std::allocator< Node< T > >
				> class RBTree	{
	public:
		typedef ft::Node< T > *			NodePtr;
		typedef RBTree_iterator< T >	iterator;
	
	private:
		NodePtr root;
		Allocator a;
		Compare	compare_function;

		Compare comparison() const {
			return compare_function;
		}

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
			if (nodeFather(dead) == NULL)
				root = orphan;
			else if (dead == nodeFather(dead)->left)
				nodeFather(dead)->left = orphan;
			else
				nodeFather(dead)->right = orphan;
			if (orphan)
				orphan->parent = nodeFather(dead);
		}

		NodePtr nodeFather(NodePtr k)
		{
			return k->parent;
		}

		NodePtr nodeGranfather(NodePtr k)
		{
			return k->parent->parent;
		}

		void balance_after_insetion(NodePtr k)
		{
			NodePtr u;
			while (isRed(nodeFather(k)))
			{
				if (nodeFather(k) == nodeGranfather(k)->right)
				{
					u = nodeGranfather(k)->left;
					if (isRed(u))
					{
						nodeFather(k)->color = BLACK;
						u->color = BLACK;
						nodeGranfather(k)->color = RED;
						k = nodeGranfather(k);
					}
					else
					{
						if (k == nodeFather(k)->left)
						{
							k = nodeFather(k);
							right_rotate(k);
						}
						nodeFather(k)->color = BLACK;
						nodeGranfather(k)->color = RED;
						left_rotate(nodeGranfather(k));
					}
				}
				else
				{
					u = nodeGranfather(k)->right;
					if (isRed(u))
					{
						nodeFather(k)->color = BLACK;
						u->color = BLACK;
						nodeGranfather(k)->color = RED;
						k = nodeGranfather(k);
					}
					else
					{
						if (k == nodeFather(k)->right)
						{
							k = nodeFather(k);
							left_rotate(k);
						}
						nodeFather(k)->color = BLACK;
						nodeGranfather(k)->color = RED;
						right_rotate(nodeGranfather(k));
					}
				}
				if (k == root)
					break;
			}
			root->color = BLACK;
		};	// END INSERTION BALANCE

		void balance_after_deletion(NodePtr x)
		{
			NodePtr s;
			while (x != root && x->color == BLACK)
			{
				if(x == nodeFather(x)->left)
				{
					s = nodeFather(x)->right;
					if (isRed(s))
					{
						s->color = BLACK;
						nodeFather(x)->color = RED;
						left_rotate(nodeFather(x));
						s = nodeFather(x)->right;
					}
					if (((s->left && !isRed(s->left)) || !s->left)
						&& ((s->right && !isRed(s->right)) || !s->right))
					{
						s->color = RED;
						x = nodeFather(x);
					}
					else
					{
						if ((s->right && !isRed(s->right)) || !s->right)
						{
							s->color = RED;
							if (s->left)
								s->left->color = BLACK;
							right_rotate(s);
							s = nodeFather(x)->right;
						}
						s->color = nodeFather(x)->color;
						nodeFather(x)->color = BLACK;
						if (s->right)
							s->right->color = BLACK;
						left_rotate(nodeFather(x));
						x = root;
					}
				}
				else
				{
					s = nodeFather(x)->left;
					if (isRed(s))
					{
						s->color = BLACK;
						nodeFather(x)->color = RED;
						right_rotate(nodeFather(x));
						s = nodeFather(x)->left;
					}
					if (((s->left && !isRed(s->left)) || !s->left)
						&& ((s->right && !isRed(s->right)) || !s->right))
					{
						s->color = RED;
						x = nodeFather(x);
					}
					else
					{
						if ((s->left && !isRed(s->left)) || !s->left)
						{
							s->color = RED;
							if (s->right)
								s->right->color = BLACK;
							left_rotate(s);
							s = nodeFather(x)->left;
						}
						s->color = nodeFather(x)->color;
						nodeFather(x)->color = BLACK;
						if (s->left)
							s->left->color = BLACK;
						right_rotate(nodeFather(x));
						x = root;
					}
				}
			}
			x->color = BLACK;
		};	// END DELETION BALANCE

	public:

		RBTree() : root(NULL), compare_function(Compare()), a(Allocator()) {};

		~RBTree()
		{
			deleteAllNodes(root);
		};

		ft::pair<iterator, bool> insertion(K z)
		{
			NodePtr father = NULL;
			NodePtr search = root;
			while (search != NULL)
			{
				father = search;
				if (z == search->value)
					return ft::make_pair(iterator(search), false);
				if(comparison()(z, search->value))
					search = search->left;
				else
					search = search->right;
			}
			search = a.allocate( 1 );
			a.construct( search, Node< T >(z, father) );
			if (father == NULL)
				root = search;
			else if (comparison()(z, father->value))
				father->left = search;
			else
				father->right = search;
			balance_after_insetion(search);
			return ft::make_pair(iterator(search), true);
		} // END INSERTION

		void deletion(K z)
		{
			NodePtr toDelete = root;
			NodePtr toBalance = NULL;
			while (toDelete != NULL && z != toDelete->value)
			{
				if (comparison()(z, toDelete->value))
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
		} // END NODE DELETION

		iterator begin()
		{
			NodePtr left = root;
			while (left->left != NULL)
				left = left->left;
			return iterator(left);
		}

		iterator end()
		{
			NodePtr right = root;
			while (right->right != NULL)
				right = right->right;
			return iterator(NULL, right);
		}

		void print()
		{
			if (root) {
				printHelper(this->root, "", true);
		}
	}
	}; // END OF CLASS RBTREE
	
} // namespace ft

#endif