// #ifndef __RBTREE_HPP__
// # define __RBTREE_HPP__
#include <iostream>
#include <string>

/*

ROTAZIONE SINISTRA
|--------------|---------------|-------------------------------------------------|
|   prima      |     dopo      |                  pseudocode                     |
|--------------|---------------|-------------------------------------------------|
|      N       |        N      |    P->DX = F->SX                                |
|      |       |        |      |    F->SX->U = P                                 |
|      P       |        F      |    F->U = N                                     |
|     / \      |       / \     |    SE !N, ALLORA ROOT = F                       |
|    α   F     |      P   ∂    |    ALTRIMENTI SE P == N->SX, ALLORA N->SX = F   |
|       / \    |     / \       |    ALTRIMENTI SE P == N->DX, ALLORA N->DX = F   |
|      ß   ∂   |    α   ß      |    F->SX = P                                    |
|              |               |    P->U = F                                     |
|--------------|---------------|-------------------------------------------------|

ROTAZIONE DESTRA
|--------------|---------------|-------------------------------------------------|
|   prima      |     dopo      |                  pseudocode                     |
|--------------|---------------|-------------------------------------------------|
|       N      |       N       |    P->SX = F->DX                                |
|       |      |       |       |    F->DX->U = P                                 |
|       P      |       F       |    F->U = N                                     |
|      / \     |      / \      |    SE !N, ALLORA ROOT = F                       |
|     F   ∂    |     α   P     |    ALTRIMENTI SE P == N->SX, ALLORA N->SX = F   |
|    / \       |        / \    |    ALTRIMENTI SE P == N->DX, ALLORA N->DX = F   |
|   α   ß      |       ß   ∂   |    F->DX = P                                    |
|              |               |    P->U = F                                     |
|--------------|---------------|-------------------------------------------------|

*/

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

		Node* normal_insert(int val)
		{
			Node* nuovo_nodo = new Node;		//	allocazione del nuovo nodo
			nuovo_nodo->padre = nullptr;		//	inizializzazione del ramo destro del nuovo nodo a NULL
			nuovo_nodo->minore = NULL_LEAF;		//	inizializzazione del ramo sinistro del nuovo nodo a NULL
			nuovo_nodo->maggiore = NULL_LEAF;		//	inizializzazione del ramo destro del nuovo nodo a NULL
			nuovo_nodo->dato = val;				//	inizializzazione del valore del nuovo nodo a val
			nuovo_nodo->colore = ROSSO;			//	inizializzazione del coloree del nuovo nodo a ROSSO

			// se ho trovato il primo nodo occupato, vado alla ricerca del primo nodo libero
			Node* nodo_di_ricerca = primo_nodo;
			Node* nodo_corrente = nullptr;		
			while (nodo_di_ricerca != NULL_LEAF)
			{
				nodo_corrente = nodo_di_ricerca;
				if (nodo_di_ricerca->dato > nuovo_nodo->dato)
					nodo_di_ricerca = nodo_di_ricerca->minore;
				else
					nodo_di_ricerca = nodo_di_ricerca->maggiore;
			}
			nuovo_nodo->padre = nodo_corrente;
			if (nodo_corrente == nullptr)
				primo_nodo = nuovo_nodo;
			else if (nodo_corrente->dato > nuovo_nodo->dato)
				nodo_corrente->minore = nuovo_nodo;
			else
				nodo_corrente->maggiore = nuovo_nodo;
			return nuovo_nodo;
		};

		void insert_rebalance (Node* figlio)
		{
			while (figlio->padre->colore == 1)
			{
				if (figlio->padre == figlio->padre->padre->minore)
				{
					if(figlio->padre->padre->maggiore->colore == ROSSO)
					{
						figlio->padre->padre->maggiore->colore = NERO;
						figlio->padre->padre->minore->colore = NERO;
						figlio->padre->padre->colore = ROSSO;
						figlio = figlio->padre->padre;
					}
					else
					{
						if (figlio == figlio->padre->maggiore)
						{
							figlio = figlio->padre;
							left_rotation(figlio);
						}
						figlio->padre->colore = NERO;
						figlio->padre->padre->colore = ROSSO;
						right_rotation(figlio->padre->padre);
					}
				}
				else
				{
					if (figlio->padre->padre->minore->colore == ROSSO)
					{
						figlio->padre->padre->minore->colore = NERO;
						figlio->padre->colore = NERO;
						figlio->padre->padre->colore = ROSSO;
						figlio = figlio->padre->padre;
					}
					else
					{
						if (figlio == figlio->padre->minore)
						{
							figlio = figlio->padre;
							right_rotation(figlio);
						}
						figlio->padre->colore = NERO;
						figlio->padre->padre->colore = ROSSO;
						left_rotation(figlio->padre->padre);
					}
				}
				if (figlio == primo_nodo)
					break;
			}
			primo_nodo->colore = NERO;
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
			if (nodo->minore != NULL_LEAF)
				delete_all(nodo->minore);
			if (nodo->maggiore != NULL_LEAF) 
				delete_all(nodo->maggiore);
			delete nodo;
		};

/*
L'inserzione è composta principalmente da tre fasi:
	- l'inizializzazione del primo nodo e il suo posizionamento all'interno dell'albero
	- prima di proseguire con il bilanciamento, distinguiamo i casi in cui il padre o il nonno non puntino a nulla
	- ribilanciamento;
		caso 1: il padre del nodo aggiunto è rosso.
			caso 1.1: controllo sul nodo zio, se è rosso  
*/

		void insert(int val)
		{
			Node* nuovo_figlio = normal_insert(val);
			if (nuovo_figlio->padre == nullptr)
			{
				nuovo_figlio->colore = 0;
				return ;
			}
			if (nuovo_figlio->padre->padre == nullptr)
				return;
			
			insert_rebalance(nuovo_figlio);
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

	// Albero.printTree();
	// std::cout<<"~~~~~~~~~~~~~~~~~~~~\n";
	Albero.insert(5);
	Albero.insert(3);
	Albero.insert(2);
	Albero.insert(4);
	Albero.insert(7);
	Albero.insert(6);
	Albero.insert(8);
	Albero.insert(9);
	Albero.insert(1);
	std::cout<<"~~~~~~~~~FINAL~~~~~~~~~~\n";
	Albero.printTree();
}

// #endif
