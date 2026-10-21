#ifndef linked_list_plus_h
#define linked_list_plus_h

#include <stdexcept>
#include "linked_list_ed.h"

template <class T>
class linked_list_plus : public linked_list_ed<T> {
	using Nodo = typename linked_list_ed < T > ::Nodo;

public:
	void intercambiar(T const& elem) {
		if (this->prim == nullptr)
			return;

		Nodo* pos = this->prim;
		while (pos != nullptr && pos->elem != elem) {
			pos = pos->sig;
		}

		if (pos != nullptr) {
			// 2. Saltamos todos los elementos iguales iniciales para añadir los nuevos
			// detrás de la posición de pos
			while (pos->sig != nullptr && pos->sig->elem == elem) {
				pos = pos->sig;
			}

			// 3. Busca elementos posteriores para agruparlos
			Nodo* otro = pos;
			while (otro->sig != nullptr) {
				if (otro->sig->elem == ch) {
					moverNodo(pos, otro);  // Desplaza el nodo usando la función privada
					pos = pos->sig;        // Avanzamos pos para que quede detrás del último elemento agrupado
				}
				else {
					otro = otro->sig;      // Si no coincide, simplemente avanzamos el rastreador
				}
			}

			// TRUCO DE EXAMEN: Si se ha movido el último elemento de la lista,
			// tenemos que actualizar a mano el puntero 'this->ult' de la clase padre
			if (this->ult == pos) {
				this->ult = otro;
			}
		}
	}

private:
	// Función privada que cambia los enlaces de los nodos
	void moverNodo(Nodo* pos, Nodo* antMover) {
		Nodo* mover = antMover->sig;  // 1. Identificamos el nodo que queremos trasladar
		antMover->sig = mover->sig;   // 2. Lo desconectamos de su sitio original en la lista
		mover->sig = pos->sig;        // 3. Hacemos que apunte a lo que iba después de nuestra ancla
		pos->sig = mover;             // 4. Conectamos nuestra ancla al nodo trasladado
	}

};

};


#endif