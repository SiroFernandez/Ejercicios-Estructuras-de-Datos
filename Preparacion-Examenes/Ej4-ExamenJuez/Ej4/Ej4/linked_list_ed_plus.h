#ifndef linked_list_ed_plus_h
#define linked_list_ed_plus_h

#include <stdexcept>
#include "linked_list_ed.h"

using namespace std;

template <typename T>
class linked_list_ed_plus : public linked_list_ed<T> {
    using Nodo = typename linked_list_ed<T>::Nodo;

private:
    void intercambiar(Nodo* ant, Nodo* desp) {
        Nodo* mover = ant->sig;
        ant->sig = mover->sig;
        mover->sig = desp->sig;
        desp->sig = mover;
    }

    Nodo* desplazar_maximo(Nodo* tope) {
        if (this->prim == tope || this->prim->sig == tope)
            return this->prim;

        Nodo* ant = nullptr;
        Nodo* act = this->prim;
        Nodo* sig = act->sig;

        while (sig != tope) {
            if (act->elem > sig->elem) {
                act->sig = sig->sig;
                sig->sig = act;

                if (ant == nullptr)
                    this->prim = sig;
                else
                    ant->sig = sig;

                ant = sig;
                sig = act->sig;
            }
            else {
                ant = act;
                act = sig;
                sig = sig->sig;
            }
        }

        return act;
    }

public:
    void ordenar() {
        if (this->prim == nullptr || this->prim->sig == nullptr)
            return;

        Nodo* tope = nullptr;

        while (tope != this->prim) {
            tope = desplazar_maximo(tope);
        }
    }

    void print() const {
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
};

#endif