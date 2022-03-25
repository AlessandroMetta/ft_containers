#include <iostream>

#define RED 1
#define BLACK 0

template <class T>
struct Node
{
	struct Node * p;
	struct Node * r;
	struct Node * l;
	T	k;
	bool c;

	Node( T key ) : k( key ), c( BLACK ), p( NULL ), r( NULL ), l( NULL ) {};

	bool isLeft(){ return p && p->l == this; }

	bool isRight(){ return p && p->r == this; }

	Node * uncle() const {
		if ( p->p && p->isLeft() )
			return p->p->r;
		if ( p->p && p->isRight() )
			return p->p->l;
		return NULL;
	}

	Node * sibling() const {
		if ( this->isLeft() && p->r != NULL )
			return p->r;
		if ( this->isRight() && p->l != NULL )
			return p->l;
		return NULL;
	}
};

template <class T>
class BSTree{
	private:
		Node<T> * head;
	public:
		BSTree() {
			head = new Node<T>(0);
		};
		
		~BSTree() {
			delete_all_nodes(head->r);
			delete head;
		};

		void delete_all_nodes(Node<T> * n)
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

		Node<T> * search(T key)
		{
			Node<T> * n = head->r;
			while(n != NULL || n->k != key)
			{
				if (key < n->k)
					n = n->l;
				else
					n = n->r;
			}
			return n;
		}

		void BSTree_insertion(T key)
		{
			Node<T> * n = head->r;
			Node<T> * p = head;
			while (n != NULL)
			{
				p = n;
				if (key < n->k)
					n = n->l;
				else
					n = n->r;
			}
			Node<T> * m = new Node<T>(key);
			m->c = RED;
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

		void BSTree_deletion(T key)
		{
			Node<T> * n = head->r;
			Node<T> * t;
			Node<T> * c;
			Node<T> * p = head;
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

	void printBT(const std::string& prefix, Node<T>* node, bool isLeft)
	{
	    if( node != nullptr )
	    {
	        std::cout << prefix;

	        std::cout << (node->isLeft() && node->p->r ? "├──" : "└──" );

	        // print the value of the node
	        std::cout << node->k << std::endl;

	        // enter the next tree level - left and right branch
	        printBT( prefix + (node->isLeft() && node->p->r ? "│  " : "   "), node->l, true);
	        printBT( prefix + (node->isLeft() && node->p->r ? "│  " : "   "), node->r, false);
	    }
	}

	void treeprint() { printBT("", head->r, false); }
};

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

	tree.BSTree_insertion('E');
	tree.BSTree_insertion('A');
	tree.BSTree_insertion('C');
	tree.BSTree_insertion('R');
	tree.BSTree_insertion('H');
	tree.BSTree_insertion('N');
	tree.BSTree_insertion('M');
	tree.BSTree_insertion('L');
	tree.BSTree_insertion('P');

	// tree.treeprint();
	// std::cout << "\ndeletion of E\n";
	// tree.BSTree_deletion('E');

	tree.treeprint();
}
