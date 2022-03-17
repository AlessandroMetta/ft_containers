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

		void printHelper(Node* primo_nodo, std::string indent, bool last)
		{
			if (primo_nodo != nullptr) {
				std::cout << indent;
			if (last) {
				std::cout << "R----";
				indent += "   ";
			} else {
				std::cout << "L----";
				indent += "|  ";
			}

			std::string sColor = primo_nodo->colore ? "RED" : "BLACK";
			std::cout << primo_nodo->dato << "(" << sColor << ")" << std::endl;
			printHelper(primo_nodo->minore, indent, false);
			printHelper(primo_nodo->maggiore, indent, true);
			}
		};

		void left_rotation(Node* nodo_figlio)
		{
			Node* nodo_padre = nodo_figlio->padre;
			Node* nodo_nonno = nodo_padre->padre;
			nodo_padre->maggiore = nodo_figlio->minore;
			if (nodo_figlio->minore != nullptr)
				nodo_figlio->minore->padre = nodo_padre;
			nodo_figlio->padre = nodo_nonno;
			if (nodo_nonno == nullptr)
				primo_nodo = nodo_figlio;
			else if (nodo_padre == nodo_nonno->minore)
				nodo_nonno->minore = nodo_figlio;
			else
				nodo_nonno->maggiore = nodo_figlio;
			nodo_figlio->minore = nodo_padre;
			nodo_padre->padre = nodo_figlio;
		};

		void right_rotation(Node* nodo_figlio)
		{
			Node* nodo_padre = nodo_figlio->padre;
			Node* nodo_nonno = nodo_padre->padre;
			nodo_padre->minore = nodo_figlio->maggiore;
			if (nodo_figlio->maggiore != nullptr)
				nodo_figlio->maggiore->padre = nodo_padre;
			nodo_figlio->padre = nodo_nonno;
			if (nodo_nonno == nullptr)
				primo_nodo = nodo_figlio;
			else if (nodo_padre == nodo_nonno->maggiore)
				nodo_nonno->maggiore = nodo_figlio;
			else
				nodo_nonno->minore = nodo_figlio;
			nodo_figlio->maggiore = nodo_padre;
			nodo_padre->padre = nodo_figlio;
		};

		Node* normal_insert(int val)
		{
			Node* nuovo_nodo = new Node;		//	allocazione del nuovo nodo
			nuovo_nodo->padre = nullptr;		//	inizializzazione del ramo destro del nuovo nodo a NULL
			nuovo_nodo->minore = nullptr;		//	inizializzazione del ramo sinistro del nuovo nodo a NULL
			nuovo_nodo->maggiore = nullptr;		//	inizializzazione del ramo destro del nuovo nodo a NULL
			nuovo_nodo->dato = val;				//	inizializzazione del valore del nuovo nodo a val
			nuovo_nodo->colore = ROSSO;				//	inizializzazione del colore del nuovo nodo a ROSSO

			if (primo_nodo == nullptr)			// se non esistono ancora nodi
			{
				primo_nodo = nuovo_nodo;		// inizializza al nuovo nodo l'albero
				primo_nodo->colore = NERO;			// assegna al nodo il colore nero
				return nuovo_nodo;
			}
			// se ho trovato il primo nodo occupato, vado alla ricerca del primo nodo libero
			Node* nodo_di_ricerca = primo_nodo;
			Node* nodo_corrente = nullptr;		
			while (nodo_di_ricerca != nullptr)
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
					std::cout << figlio->padre->padre << "\n";
					if(figlio->padre->padre->maggiore->colore == ROSSO) // problema nel caso specifico mio, non esiste lo zio
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
		RBTree() : primo_nodo(nullptr) {};
		~RBTree() {};
		
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

	Albero.insert(5);
	Albero.insert(3);
	Albero.printTree();
	std::cout<<"~~~~~~~~~~~~~~~~~~~~\n";
	Albero.insert(2);
	// Albero.insert(7);
	// Albero.insert(8);
	// Albero.insert(4);
	// Albero.insert(6);
	std::cout<<"~~~~~~~~~FINAL~~~~~~~~~~\n";
	Albero.printTree();
}

// #endif
