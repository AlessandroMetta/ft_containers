#ifndef __BSTREE_HPP__
# define __BSTREE_HPP__

#include <memory>

template <class T>
struct Node
{
	T	key;
	
	struct Node * parent;
	struct Node * right;
	struct Node * left;

	Node( T key ) : key( key ), parent( NULL ), right( NULL ), left( NULL ) {};
};

template <class T, class Allocator = std::allocator< Node<T> > >
class BSTree
{
	public:
		typedef Node<T>* NodePtr;

	private:
		NodePtr head;
		Allocator alloc;

		void delete_all_nodes( NodePtr n )
		{
			if (n)
			{
				if (n->left != NULL)
					delete_all_nodes(n->left);
				if (n->right != NULL)
					delete_all_nodes(n->right);
				alloc.destroy(n);
				alloc.deallocate(n, 1);
				n = NULL;
			}
		}

		void printBT( const std::string& prefix, NodePtr n, bool isLeft )
		{
			if( n != nullptr )
			{
				std::cout << prefix;

				std::cout << (isLeft ? "├──" : "└──" );

				std::cout << n->key << std::endl;

				printBT( prefix + (isLeft ? "│  " : "   "), n->left, true);
				printBT( prefix + (isLeft ? "│  " : "   "), n->right, false);
			}
		}

	public:
		BSTree() {
			head = alloc.allocate( 1 );
			alloc.construct(head, 0);
		};
		
		~BSTree() {
			delete_all_nodes(head->right);
			alloc.deallocate(head, 1);
		};

		void treeprint() { printBT("", head->right, false); }

		NodePtr search(T key)
		{
			NodePtr n = head->right;
			while(n != NULL || n->key != key)
			{
				if (key < n->key)
					n = n->left;
				else
					n = n->right;
			}
			return n;
		}

		void insertion(T key)
		{
			NodePtr n = head->right;
			NodePtr p = head;
			NodePtr m;
			while (n != NULL)
			{
				p = n;
				if (key < n->key)
					n = n->left;
				else
					n = n->right;
			}
			m = alloc.allocate( 1 );
			alloc.construct(m, key);
			if (head->right == NULL)
			{
				head->right = m;
				return ;
			}
			else if (key < p->key)
				p->left = m;
			else
				p->right = m;
			m->parent = p;
		}

		void deletion(T key)
		{
			NodePtr n = head->right;
			NodePtr t;
			NodePtr c;
			NodePtr p = head;

			while (n != NULL && key != n->key)
			{
				p = n;
				if (key < n->key)
					n = n->left;
				else
					n = n->right;
			}
			if (n == NULL) return ;
			t = n;
			if (t->right == NULL)
				n = n->left;
		else if (t->right->left == NULL)
			{
				n = n->right;
				n->left = t->left;
			}
			else
			{
				c = n->right;
				while (c->left->left != NULL)
					c = c->left;
				n = c->left;
				c->left = n->right;
				n->left = t->left;
				n->right = t->right;
			}
			if (p != head)
				p = t->parent;

			alloc.destroy(t);
			alloc.deallocate(t, 1);

			if (!p)
				return ;
			if (key < p->key)
				p->left = n;
			else
				p->right = n;
		}
};

#endif
