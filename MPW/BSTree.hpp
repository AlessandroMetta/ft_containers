#ifndef __BSTREE_HPP__
# define __BSTREE_HPP__

template <class T>
struct Node
{
	T	k;
	
	struct Node * p;
	struct Node * r;
	struct Node * l;

	Node( T key ) : k( key ), p( NULL ), r( NULL ), l( NULL ) {};
};

template <class T>
class BSTree{
	public:
		typedef Node<T>* NodePtr;

	private:
		NodePtr head;

		void delete_all_nodes( NodePtr n )
		{
			if (n)
			{
				if (n->l != NULL)
					delete_all_nodes(n->l);
				if (n->r != NULL)
					delete_all_nodes(n->r);
				delete n;
			}
		}

		void printBT( const std::string& prefix, NodePtr n, bool isLeft )
		{
			if( n != nullptr )
			{
				std::cout << prefix;

				std::cout << (isLeft && n->p->r ? "├──" : "└──" );

				std::cout << n->k << std::endl;

				printBT( prefix + (isLeft && n->p->r ? "│  " : "   "), n->l, true);
				printBT( prefix + (isLeft && n->p->r ? "│  " : "   "), n->r, false);
			}
		}

	public:
		BSTree() {
			head = new Node<T>(0);
		};
		
		~BSTree() {
			delete_all_nodes(head->r);
			delete head;
		};

		void treeprint() { printBT("", head->r, false); }

		NodePtr search(T key)
		{
			NodePtr n = head->r;
			while(n != NULL || n->k != key)
			{
				if (key < n->k)
					n = n->l;
				else
					n = n->r;
			}
			return n;
		}

		void insertion(T key)
		{
			NodePtr n = head->r;
			NodePtr p = head;
			while (n != NULL)
			{
				p = n;
				if (key < n->k)
					n = n->l;
				else
					n = n->r;
			}
			NodePtr m = new Node<T>(key);
			if (head->r == NULL)
			{
				head->r = m;
				return ;
			}
			else if (key < p->k)
				p->l = m;
			else
				p->r = m;
			m->p = p;
		}

		void deletion(T key)
		{
			NodePtr n = head->r;
			NodePtr t;
			NodePtr c;
			NodePtr p = head;
			while (key != n->k)
			{
				p = n;
				if (key < n->k)
					n = n->l;
				else
					n = n->r;
			}
			t = n;
			if (t->r == NULL)
				n = n->l;
			else if (t->r->l == NULL)
			{
				n = n->r;
				n->l = t->l;
			}
			else
			{
				c = n->r;
				while (c->l->l != NULL)
					c = c->l;
				n = c->l;
				c->l = n->r;
				n->l = t->l;
				n->r = t->r;
			}
			if (p != head)
				p = t->p;
			delete t;
			if (!p)
				return ;
			if (key < p->k)
				p->l = n;
			else
				p->r = n;
		}
};

#endif