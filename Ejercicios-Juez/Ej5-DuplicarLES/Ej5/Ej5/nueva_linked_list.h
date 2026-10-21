//
//  linked_list_ed.h
//
//  Implementación del TAD linked_list con nodos enlazados
//  y punteros al primer y  último nodo
//
//  Estructuras de Datos. Grupos A y C. Curso 2021/22
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2021 Isabel Pita 
//  Adaptada de la implementación del queue realizada por Alberto Verdejo

#ifndef nueva_linked_list_h
#define nueva_linked_list_h

#include <stdexcept>  // std::domain_error
#include "linked_list_ed.h"

using namespace std;

template <typename T>
class nueva_linked_list : public linked_list_ed<T>{
	using Nodo = typename linked_list_ed<T>::Nodo;

public:
	nueva_linked_list() : linked_list_ed<T>(){}

	void imprimir()const {
		Nodo* actual = this->prim;
		bool primero = true;

		while (actual != nullptr) {
			if (!primero)
				cout << " ";
			cout << actual->elem;
			primero = false;
			actual = actual->sig;
		}
		cout << "\n";
	}

	void duplicar() {
		Nodo* actual = this->prim;

		while (actual != nullptr) {
			Nodo* clon = new Nodo(actual->elem, actual->sig);
			actual->sig = clon;

			if (this->ult == actual)
				this->ult = clon;

			actual = clon->sig;
		}
	}
};

#endif // linked_list_ed_h