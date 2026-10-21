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

#ifndef list_extendida_h
#define list_extendida_h

#include <stdexcept>  // std::domain_error
#include <iostream>
#include "linked_list_ed.h"

using namespace std;

template <typename T>
class list_extendida : public linked_list_ed<T> {
	using Nodo = typename linked_list_ed<T>::Nodo;

public:
	list_extendida() : linked_list_ed<T>() {}

	void mostrar() const {
		Nodo* actual = this->prim;
        bool primero = true;

        while (actual != nullptr) {
            if (!primero) 
                cout << " ";
            std::cout << actual->elem;
            primero = false;
            actual = actual->sig;
        }
        cout << "\n";
	}

    void invertir() {
        Nodo* actual = this->prim;
        Nodo* ant = nullptr;
        Nodo* sig = nullptr;

        this->ult = this->prim;

        while (actual != nullptr) {
            sig = actual->sig;
            actual->sig = ant;
            ant = actual;
            actual = sig;
        }

        this->prim = ant;
    }
};

#endif // linked_list_ed_h
