#ifndef nueva_linked_list_h
#define nueva_linked_list_h

#include <stdexcept>  // std::domain_error
#include <iostream>
#include "linked_list_ed.h"

using namespace std;

template <typename T>
class nueva_linked_list : public linked_list_ed<T> {
	using Nodo = typename linked_list_ed<T>::Nodo;

public:
    using linked_list_ed<T>::linked_list_ed;

    template <typename Predicate>
    void mostrar(Predicate pred) const {
        Nodo* actual = this->prim;
        bool primero = false;

        while (actual != nullptr) {
            if (pred(actual->elem)) {
                if (primero) cout << " ";
                cout << actual->elem;
                primero = true;
            }
            actual = actual->sig;
        }
        cout << '\n';
    }
};

#endif // linked_list_ed_h
