// #ifndef __RBTREE_HPP__
// # define __RBTREE_HPP__
#include <iostream>
#include <string>

#define NERO 0
#define ROSSO 1

class RBTree
{
	private:
		struct Node
		{
			Node*				padre;
			Node*				minore;
			Node*				maggiore;
			bool				colore;
			int					dato;
		};
		Node* primo_nodo;
		Node* NULL_LEAF;

		void printHelper(Node* primo_nodo, std::string indent, bool last)
		{
			if (primo_nodo != NULL_LEAF) {
				std::cout << indent;
			if (last) {
				std::cout << "R----";
				indent += "   ";
			} else {
				std::cout << "L----";
				indent += "|  ";
			}

			std::string scolore = primo_nodo->colore ? "RED" : "BLACK";
			std::cout << primo_nodo->dato << "(" << scolore << ")" << std::endl;
			printHelper(primo_nodo->minore, indent, false);
			printHelper(primo_nodo->maggiore, indent, true);
			}
		};

		void left_rotation(Node* figlio)
		{
			Node* fratello = figlio->maggiore;
			figlio->maggiore = fratello->minore;
			if (fratello->minore != NULL_LEAF)
				fratello->minore->padre = figlio;
			fratello->padre = figlio->padre;
			if (figlio->padre == nullptr)
				this->primo_nodo = fratello;
			else if (figlio == figlio->padre->maggiore)
				figlio->padre->maggiore = fratello;
			else
				figlio->padre->minore = fratello;
			fratello->minore = figlio;
			figlio->padre = fratello;
		};

		void right_rotation(Node* figlio)
		{
			Node* fratello = figlio->minore;
			figlio->minore = fratello->maggiore;
			if (fratello->maggiore != NULL_LEAF)
				fratello->maggiore->padre = figlio;
			fratello->padre = figlio->padre;
			if (figlio->padre == nullptr)
				this->primo_nodo = fratello;
			else if (figlio == figlio->padre->maggiore)
				figlio->padre->maggiore = fratello;
			else
				figlio->padre->minore = fratello;
			fratello->maggiore = figlio;
			figlio->padre = fratello;
		};

		Node* perform_insert(Node* h, int val, bool sw)
		{
			int v = val;
			if (h == NULL_LEAF)
			{
				Node* new_node = new Node;
				new_node->dato = val;
				new_node->minore = NULL_LEAF;
				new_node->maggiore = NULL_LEAF;
				new_node->padre = nullptr;
				new_node->colore = ROSSO;
				return new_node;
			}
			if (h->minore->colore == ROSSO && h->maggiore->colore == ROSSO)
			{
				h->colore = ROSSO;
				h->minore->colore = NERO;
				h->maggiore->colore = NERO;
			}
			if (v < h->dato)
			{
				h->minore = perform_insert(h->minore, val, 0);
				h->minore->padre = h;
				if (h->colore == ROSSO && h->minore->colore == ROSSO && sw)
					right_rotation(h);
				if (h->minore->colore == ROSSO && h->minore->minore->colore == ROSSO)
				{
					right_rotation(h);
					h->colore = NERO;
					h->maggiore->colore = ROSSO;
				}
			}
			else
			{
				h->maggiore = perform_insert(h->maggiore, val, 1);
				h->maggiore->padre = h;
				if (h->colore == ROSSO && h->maggiore->colore == ROSSO && !sw)
					left_rotation(h);
				if (h->maggiore->colore == ROSSO && h->maggiore->maggiore->colore == ROSSO)
				{
					left_rotation(h);
					h->colore = NERO;
					h->minore->colore = ROSSO;
				}
			}
			return h;
		};

		void flip(Node* h)
		{
			h->colore = NERO;
			h->minore->colore = ROSSO;
			h->maggiore->colore = ROSSO;
		};
		
		#define chg_rb(x)	do{(x)->colore = ((x)->colore == ROSSO) ? NERO : ROSSO;}while(0);

		Node* perform_delete(Node* h, int v)
		{
			if (h == primo_nodo	&& h->minore->colore == NERO && h->maggiore->colore == NERO)
				h->colore = ROSSO;

			if (h->dato == v) {
				if (h->minore == NULL_LEAF || h->maggiore == NULL_LEAF) {
					Node* x;
					if (h->minore != NULL_LEAF)
						x = h->minore;
					else
						x = h->maggiore;
					if (x != NULL_LEAF)
						x->padre = h->padre;
					if (h->padre == NULL_LEAF)
						return NULL_LEAF;
					else if (h == h->padre->minore)
						h->padre->minore = x;
					else
						h->padre->maggiore = x;

					if (h->colore == NERO) {
						x->colore = NERO;
					}
					return x;
				} else {
					Node* x;
					for (x = h->maggiore; x->minore != NULL_LEAF; x = x->minore) {}
					h->dato = x->dato;
					v = x->dato;
				}
			}

			/* It's possible to get here even if the ``v'' has been found:
			 *         when (h has two children) and (SUCCESSOR(h)->val == v).
			 * Therefore, we'd use (h->val <= v), not (h->val < v).
			 */
			if (h->dato <= v) {
				/* transform if the right child is a 2-node */
				if (h->maggiore->colore == NERO && h->maggiore->minore->colore == NERO && h->maggiore->maggiore->colore == NERO) {
					if (h->colore == NERO) {
						right_rotation(h);
						chg_rb(h);
						chg_rb(h->maggiore);
					} else {
						if (h->minore->colore == NERO && h->minore->minore->colore == NERO && h->minore->maggiore->colore == NERO)
							flip(h);
						else {
							if (h->minore->maggiore->colore == NERO) {
								left_rotation(h);
								chg_rb(h);
								chg_rb(h->minore);
								chg_rb(h->maggiore);
								chg_rb(h->maggiore->maggiore);
							} else {
								h = h->minore;
								left_rotation(h);
								h = h->padre;
								right_rotation(h);
								chg_rb(h->maggiore);
								chg_rb(h->maggiore->maggiore);
							}
						}
					}
				}
				h->maggiore = perform_delete(h->maggiore, v);
			} else if (v < h->dato) {
				/* transform if the left child is a 2-node */
				if (h->minore->colore == NERO && h->minore->minore->colore == NERO && h->minore->maggiore->colore == NERO) {
					if (h->colore == NERO) {
						left_rotation(h);
						chg_rb(h);
						chg_rb(h->minore);
					} else {
						if (h->maggiore->colore == NERO && h->minore->maggiore->colore == NERO && h->maggiore->maggiore->colore == NERO)
							flip(h);
						else {
							if (h->minore->maggiore->colore == NERO) {
								left_rotation(h);
								chg_rb(h);
								chg_rb(h->maggiore);
								chg_rb(h->minore);
								chg_rb(h->minore->minore);
							} else {
								h = h->maggiore;
								right_rotation(h);
								h = h->padre;
								left_rotation(h);
								chg_rb(h->minore);
								chg_rb(h->minore->minore);
							}
						}
					}
				}
				/* the left child is no longer a 2-node */
				h->minore = perform_delete(h->minore, v);
			}
			return h;
		};

	public:
		RBTree()
		{
			NULL_LEAF = new Node;
			NULL_LEAF->colore = NERO;
			NULL_LEAF->minore = nullptr;
			NULL_LEAF->maggiore = nullptr;
			primo_nodo = NULL_LEAF;
		};

		~RBTree()
		{
			delete_all(primo_nodo);
			delete NULL_LEAF;
		};
		
		void delete_all(Node* nodo)
		{
			if (nodo->minore)
				delete_all(nodo->minore);
			if (nodo->maggiore) 
				delete_all(nodo->maggiore);
			delete nodo;
		};

		void rb_insert(int val)
		{
			primo_nodo = perform_insert(primo_nodo, val, 0);
			primo_nodo->colore = NERO;
		};

		void rb_delete(int v)
		{
			primo_nodo = perform_delete(primo_nodo, v);
			primo_nodo->colore = NERO;
		};

		void printTree() 
		{
			if (primo_nodo)
				printHelper(primo_nodo, "", true);
		};
};

int main()
{
	RBTree Albero;

	Albero.rb_insert(5);
	Albero.rb_insert(3);
	Albero.rb_insert(2);
	Albero.rb_insert(4);
	Albero.rb_insert(7);
	Albero.rb_insert(6);
	Albero.rb_insert(8);
	Albero.rb_insert(9);
	Albero.rb_insert(1);
	std::cout<<"~~~~~~~~~~~~~~~~~~~\n";
	Albero.printTree();
	Albero.rb_delete(6);
	std::cout<<"~~~~~~~~~FINAL~~~~~~~~~~\n";
	Albero.printTree();
}

// #endif
