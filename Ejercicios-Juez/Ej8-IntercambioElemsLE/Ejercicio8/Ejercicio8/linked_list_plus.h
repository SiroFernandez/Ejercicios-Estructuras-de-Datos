#ifndef linked_list_plus_h
#define linked_list_plus_h

#include "linked_list_ed.h"
#include <iostream>

using namespace std;

template <typename T>
class linked_list_plus : public linked_list_ed<T> {
	using Nodo = typename linked_list_ed<T> ::Nodo;

public:
	linked_list_plus() : linked_list_ed<T>() {}

	void mostrar() const{
		Nodo* act = this->prim;
		bool primero = true;
		while (act != nullptr) {
			if (!primero)
				cout << " ";
			cout << act->elem;
			primero = false;
			act = act->sig;
		}
		cout << "\n";
	}

	void intercambio() {
		Nodo* act = this->prim;
		Nodo* ant = nullptr;

		while (act != nullptr && act->sig != nullptr) {
			Nodo* nodo1 = act;
			Nodo* nodo2 = act->sig;
			Nodo* aux = nodo2->sig;

			nodo1->sig = aux;
			nodo2->sig = nodo1;

			if (ant == nullptr)
				this->prim = nodo2;
			else
				ant->sig = nodo2;

			ant = nodo1;
			act = aux;
		}

		if (act != nullptr)
			this->ult = act;
		else
			this->ult = ant;
	}
};

#endif