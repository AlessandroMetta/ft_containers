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
		bool	color;

		bool	_TNULL;
		int		endflag;
		NodePtr	endptr;

		Node(const T& val) : value(val), parent(nullptr), color(RED),  _TNULL(false), endflag(0), endptr(nullptr){}
		Node() : parent(nullptr), color(RED),  _TNULL(false), endflag(0), endptr(nullptr){}
	}; // end of Node structure

	template < class T > struct RBTree_iterator	{

		typedef	Node< T >*				NodePtr;
		typedef	RBTree_iterator< T >	Self;
		typedef T&						Ref;
		typedef T*						Ptr;

		NodePtr father;
		NodePtr TNULL;
		NodePtr node;

		RBTree_iterator(NodePtr node) : node(node), father(NULL) {}
		RBTree_iterator(NodePtr node, NodePtr TNULL) : node(node), TNULL(TNULL) {}
		//RBTree_iterator(NodePtr end, NodePtr last) : node(end), father(last) {}

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
		/*Self& operator++()
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
		}*/

		Self& operator++()
		{
			if (node->endflag)
			{
				if (node->endflag == 2) // se flag == 2 sono in end
					throw std::out_of_range("Out of range");
				node = node->endptr;
				return(*this);
			}
			if (!node->right->_TNULL)
			{
				node = node->right;
				while(!node->left->_TNULL)
					node = node->left;
				return *this;
			}
			NodePtr next = node->parent;
			while(!next->_TNULL && node == next->right){
				node = next;
				next = next->parent;
			}
			node = next;
			return *this;
		}
		
		/*Self& operator--()
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
		}*/

		Self& operator--(){
			if (node->endflag == 2)
			{
				node = node->parent;
				return *this;
			}
			/*
			if (!node->parent)
				lancia eccezione
			*/
			if (!node->left->_TNULL){
				node = node->left;
				while(!node->right->_TNULL)
					node = node->right;
				return *this;
			}
			NodePtr prec = node->parent;
			while(!prec->_TNULL && node == prec->left){
				node = prec;
				prec = prec->parent;
			}
			node = prec;
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
		NodePtr		root;
		NodePtr		TNULL;
		Allocator	a;
		Compare		compare_function;
		size_t		_RBTsize;

		//-------prova-------//
		NodePtr		_LAST;
		NodePtr		_END;

		void update_END()
		{
			NodePtr iter = root;
			while(iter->right && !iter->right->_TNULL)
				iter = iter->right;
			if (_LAST != _END)
			{
				_LAST->endflag = 0;
				_LAST->endptr = NULL;
			}
			_LAST = iter;
			_LAST->endflag = 1;
			_LAST->endptr = _END;
			_END->parent = _LAST;
		}
		//

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
				if (node != TNULL)
				{
					a.destroy(node);
					a.deallocate(node, 1);
				}
			}
		}

		bool isRed(NodePtr k)
		{
			if (!k) return BLACK;
			return k->color == RED;
		};

		NodePtr minimum(NodePtr node) {
			while (node->left != TNULL) {
				node = node->left;
			}
			return node;
		}

		void left_rotate(NodePtr x) {
			NodePtr y = x->right;
			x->right = y->left;
			if (y->left != TNULL) {
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
			if (y->right != TNULL) {
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
				root = orphan; //QUI!!!!!
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

		//ok sembra
		void balance_after_insetion(NodePtr k)
		{
			NodePtr u;
			while (k->parent->color == 1)
			{
				if (k->parent == k->parent->parent->right)
				{
					u = k->parent->parent->left;
					if (isRed(u))
					{
						u->color = BLACK;
						k->parent->color = BLACK;
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
					u = k->parent->parent->right;;
					if (isRed(u))
					{
						u->color = BLACK;
						k->parent->color = BLACK;
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
					break;
			}
			root->color = BLACK;
		};	// END INSERTION BALANCE

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
					if (s->left->color == 0 && s->right->color == 0)
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s->right->color == 0)
						{
							s->left->color = BLACK;
							s->color = RED;
							right_rotate(s);
							s = x->parent->right;
						}
						s->color = x->parent->color;
						x->parent->color = BLACK;
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
					if (s->right->color == 0 && s->right->color == 0)
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s->left->color == 0)
						{
							s->right->color = BLACK;
							s->color = RED;
							left_rotate(s);
							s = x->parent->left;
						}
						s->color = x->parent->color;
						x->parent->color = BLACK;
						s->left->color = BLACK;
						right_rotate(x->parent);
						x = root;
					}
				}
			}
			x->color = BLACK;
		};	// END DELETION BALANCE

	public:

		//RBTree ok
		explicit RBTree(const Compare& comp, const Allocator& alloc = Allocator()) : compare_function(comp), a(alloc){
			TNULL = a.allocate(1);
			a.construct(TNULL);
			TNULL->color = 0;
			TNULL->left = nullptr;
			TNULL->right = nullptr;
			TNULL->_TNULL = true;
			
			_END = a.allocate(1);
			a.construct(_END);
			_END->color = 0;
			_END->left = nullptr;
			_END->right = nullptr;
			_END->_TNULL = true;
			_END->endflag = 2;
			_LAST = _END;

			_RBTsize = 0;
			root = TNULL;
		};

		~RBTree()
		{
			deleteAllNodes(root);
			a.destroy(TNULL);
			a.deallocate(TNULL, 1);
			//_END ???
		};

		//insertion ok
		ft::pair<iterator, bool> insertion(T z)
		{
			NodePtr father = nullptr;
			NodePtr search = root;
			while (search != TNULL)
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
			a.construct( search, Node< T >(z));
			search->parent = father;
			search->left = TNULL;
			search->right = TNULL;
			if (father == nullptr)
			{
				root = search;
				search->color = 0;
				_RBTsize++;
				update_END();
				return ft::make_pair(iterator(search), true);
			}
			else if (comparison()(z, father->value))
				father->left = search;
			else
				father->right = search;
			if (search->parent->parent == nullptr)
			{
				_RBTsize++;
				update_END();
				return ft::make_pair(iterator(search), true);
			}
			balance_after_insetion(search);
			_RBTsize++;
			update_END();
			return ft::make_pair(iterator(search), true);
		} // END INSERTION

		//deletion ok
		void deletion(T z)
		{
			NodePtr nodeIter = root;
			NodePtr toDelete = TNULL;
			NodePtr toBalance = NULL;
			while (nodeIter != TNULL)
			{
				if (comparison()(z, nodeIter->value) && !comparison()(nodeIter->value, z))
					nodeIter = nodeIter->left;
				else if (!comparison()(z, nodeIter->value) && comparison()(nodeIter->value, z))
					nodeIter = nodeIter->right;
				else
				{
					toDelete = nodeIter;
					break ;
				}
			}
			if  (toDelete == TNULL)
				return ;
			NodePtr y = toDelete;
			bool original_color = y->color;
			if (toDelete->left == TNULL)
			{
				toBalance = toDelete->right;
				fixOrphan(toDelete, toDelete->right);
			}
			else if (toDelete->right == TNULL)
			{
				toBalance = toDelete->left;
				fixOrphan(toDelete, toDelete->left);
			}
			else
			{
				y = minimum(toDelete->right);
				original_color = y->color;
				toBalance = y->right;
				if (y->parent == toDelete)
					toBalance->parent = y;
				else
				{
					fixOrphan(y, y->right);
					y->right = toDelete->right;
					y->right->parent = y;
				}
				fixOrphan(toDelete, y);
				y->left = toDelete->left;
				y->left->parent = y;
				y->color = toDelete->color;
			}
			a.destroy(toDelete);
			a.deallocate(toDelete, 1);
			if (original_color == BLACK)
				balance_after_deletion(toBalance);
			_RBTsize--;
			update_END();
		} // END NODE DELETION

		iterator begin()
		{
			NodePtr left = root;
			/*while (left->left != NULL)
				left = left->left;
			return iterator(left);*/
			if (!_RBTsize)
				return (end());
			while(left->left != TNULL)
				left = left->left;
			return iterator(left);
		}

		iterator end()
		{
			/*NodePtr right = root;
			while (right->right != TNULL)
				right = right->right;
			return iterator(NULL, right);*/
			return iterator(_END);
		}

		//support function
		void print()
		{
			if (root)
				printHelper(this->root, "", true);
		}

		size_t size(){
			return _RBTsize;
		}

		size_t max_size(){
			return (a.max_size());
		}
		//-----------------------//
	}; // END OF CLASS RBTREE
	
} // namespace ft

#endif