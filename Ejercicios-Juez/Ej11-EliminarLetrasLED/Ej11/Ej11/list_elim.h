#ifndef list_elim_h
#define list_elim_h

#include <stdexcept>
#include <cassert>
#include "double_linked_list_ed.h"

using namespace std;

template <typename T>
class list_elim : public double_linked_list_ed<T> {
	using Nodo = typename double_linked_list_ed<T>::Nodo;
public:
	list_elim() : double_linked_list_ed<T>() {}

	void print()const {
		Nodo* act = this->fantasma->sig;
		bool primero = true;
		while (act != this->fantasma) {
			if (!primero)
				cout << " ";
			cout << act->elem;
			primero = false;
			act = act->sig;
		}
		cout << "\n";
	}

	list_elim<T> eliminar() {
		list_elim<T> lElim;
		Nodo* act = this->fantasma->sig;

		while (act != this->fantasma && act->sig != this->fantasma) {
			if (act->elem == act->sig->elem) {
				Nodo* aux = act->sig;

				//Creo nuevo enlace entre el actual y el nuevo sig
				act->sig = aux->sig;
				aux->sig->ant = act;

				//Meto el eliminado al final de la lista eliminada
				Nodo* ult = lElim.fantasma->ant;
				ult->sig = aux;
				aux->ant = ult;
				aux->sig = lElim.fantasma;
				lElim.fantasma->ant = aux;
			}
			else
				act = act->sig;
		}
		return lElim;
	}
};

#endif