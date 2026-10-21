//
//  double_linked_list_ed.h
//
//  Implementación del TAD double_linked_list con nodos doblemente
//   enlazados, circular, nodo cabecera (nodo fantasma) y puntero 
//   al nodo cabecera
//
//  Estructuras de Datos. Grupos A y C. Curso 2021/22
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2021 Isabel Pita 
//  Adaptada de la implementación del deque realizada por Alberto Verdejo

#ifndef double_plus_h
#define double_plus_h

#include <stdexcept>
#include <cassert>
#include "double_linked_list_ed.h"

using namespace std;

template <typename T>
class double_plus : public double_linked_list_ed<T> {
	using Nodo = typename double_linked_list_ed<T>::Nodo;
public:
	double_plus() : double_linked_list_ed<T>(){}

	void print(ostream& o) const {
		Nodo* act = this->fantasma->sig;
		bool primero = true;
		while (act != this->fantasma) {
			if (!primero)
				cout << " ";
			o << act->elem;
			primero = false;
			act = act - < sig;
		}
	}

	void agrupar(int hora) {
		Nodo* act = this->fantasma->sig;
		while(act != this->fantasma && act->elem.get)
	}

};

template <typename T>
ostream& operator<<(ostream& o, double_plus<T> const& lista) {
	lista.print(o);
	return o;
}

#endif // double_linked_list_ed_h
