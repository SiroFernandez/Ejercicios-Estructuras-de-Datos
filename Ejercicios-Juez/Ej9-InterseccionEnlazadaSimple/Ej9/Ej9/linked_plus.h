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

#ifndef linked_plus_h
#define linked_plus_h

#include <stdexcept>  // std::domain_error
#include "linked_list_ed.h"
#include <iostream>

using namespace std;

template <typename T>
class linked_plus : public linked_list_ed<T>{
	using Nodo = typename linked_list_ed<T>::Nodo;
public:
	linked_plus(): linked_list_ed<T>(){}

	void interseccion(const linked_plus<T>& l) {
		Nodo* n1 = this->prim;
		Nodo* n2 = l.prim;

		this->prim = nullptr;
		this->ult = nullptr;

		while (n1 != nullptr && n2 != nullptr) {
			if (n1->elem < n2->elem) {
				Nodo* borrado = n1;
				n1 = n1->sig;
				delete borrado;
			}
			else if (n2->elem < n1->elem) {
				n2 = n2->sig;
			}
			else {
				if (this->prim == nullptr) {
					this->prim = n1;
					this->ult = n1;
				}
				else {
					this->ult->sig = n1;
					this->ult = n1;
				}
				n1 = n1->sig;
				n2 = n2->sig;
			}
		}

		while (n1 != nullptr) {
			Nodo* borrado = n1;
			n1 = n1->sig;
			delete borrado;
		}

		if (this->ult != nullptr) {
			this->ult->sig = nullptr;
		}
	}

	void print() const {
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

};

#endif // linked_list_ed_h
