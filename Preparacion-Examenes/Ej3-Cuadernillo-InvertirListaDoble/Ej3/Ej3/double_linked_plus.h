
#ifndef double_linked_plus_h
#define double_linked_plus_h

#include <stdexcept>
#include <cassert>
#include "double_linked_list_ed.h"

template <typename T>
class double_linked_plus : public double_linked_list_ed<T> {
	using Nodo = typename double_linked_list_ed < T > ::Nodo;

public:
	void invertir() {
		Nodo* actual = this->fantasma;

		do {
			Nodo* aux = actual->sig;
			actual->sig = actual->ant;
			actual->ant = aux;
			actual = aux;
		} while (actual != this->fantasma);
	}

	void print() const {
		Nodo* actual = this->fantasma->prim;
		bool primero = true;

		while (actual != this->fantasma) {
			if (!primero)
				cout << " ";
			cout << actual->elem;
			primero = false;
			actual = actual->sig;
		}

		cout << "\n";
	}

};

#endif