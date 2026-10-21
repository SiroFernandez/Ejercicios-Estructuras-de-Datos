//
//  list_eda.h
//
//  Implementación del TAD lista heredando de colas dobles
//  y con ReverseIteradores (constantes y no constantes)
//
//  Estructuras de Datos y Algoritmos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2016-2018 Alberto Verdejo
//

#ifndef list_eda_h
#define list_eda_h

#include <stdexcept>
#include <cassert>

#include "deque_eda.h"

template <class T>
class list : public deque<T> {
protected:
    using Nodo = typename deque<T>::Nodo;
public:

    // constructor: lista vacía
    list() {}

    // consultar el elemento en la posición ind, si existe (numeradas desde 0)
    T const& at(size_t ind) const {
        if (ind >= this->nelems)
            throw std::out_of_range("posicion fuera de la lista");

        Nodo* aux = this->fantasma->sig;
        for (size_t i = 0; i < ind; ++i)
            aux = aux->sig;

        return aux->elem;
    }

protected:
    template <class Apuntado>
    class ReverseIterador {
        // puntero al nodo actual del recorrido
        Nodo* act;
        // puntero al nodo fantasma (para saber cuándo estamos fuera)
        Nodo* fan;
    public:
        ReverseIterador() : act(nullptr), fan(nullptr) {}

        // para acceder al elemento apuntado
        Apuntado& operator*() const {
            if (act == fan) throw std::out_of_range("fuera de la lista");
            return act->elem;
        }

        // para acceder a un método del elemento apuntado
        // it->metodo() en vez de (*it).metodo()
        Apuntado* operator->() const {
            return &(operator*());
        }

        ReverseIterador& operator++() { // ++ prefijo (recomendado)
            if (act == fan) throw std::out_of_range("fuera de la lista");
            act = act->ant;
            return *this;
        }

        ReverseIterador operator++(int) { // ++ postfijo
            ReverseIterador ret(*this);
            operator++();
            return ret;
        }

        bool operator==(ReverseIterador const& that) const {
            return act == that.act && fan == that.fan;
        }

        bool operator!=(ReverseIterador const& that) const {
            return !(*this == that);
        }
    private:
        // para que list pueda construir objetos del tipo ReverseIterador
        friend class list;

        // constructora privada
        ReverseIterador(Nodo* ac, Nodo* fa) : act(ac), fan(fa) {}
    };
public:
    /*
     ReverseIteradores que permiten recorrer la lista pero no cambiar sus elementos.
     */
    using const_iterator = ReverseIterador<T const>;

    // devuelven un ReverseIterador constante al principio de la lista
    
    const_iterator rbegin() const {
        return const_iterator(this->fantasma->ant, this->fantasma);
    }

    // devuelven un ReverseIterador constante al final del recorrido y fuera de este
 
    const_iterator rend() const {
        return const_iterator(this->fantasma, this->fantasma);
    }

    /*
     ReverseIteradores que permiten recorrer la lista y cambiar sus elementos.
     */
    using iterator = ReverseIterador<T>;

    // devuelve un ReverseIterador al principio de la lista
    iterator begin() {
        return iterator(this->fantasma->sig, this->fantasma);
    }

    // devuelve un ReverseIterador al final del recorrido y fuera de este
    iterator end() {
        return iterator(this->fantasma, this->fantasma);
    }

    // inserta un elemento delante del apuntado por el ReverseIterador it
    // (it puede estar apuntado detrás del último)
    // devuelve un ReverseIterador al nuevo elemento
    iterator insert(iterator const& it, T const& elem) {
        assert(this->fantasma == it.fan); // comprueba que el ReverseIterador es de esta lista
        Nodo* nuevo = this->inserta_elem(elem, it.act->ant, it.act);
        return iterator(nuevo, this->fantasma);
    }

    // elimina el elemento apuntado por el ReverseIterador (debe haber uno)
    // devuelve un ReverseIterador al siguiente elemento al borrado
    iterator erase(iterator const& it) {
        assert(this->fantasma == it.fan); // comprueba que el ReverseIterador es de esta lista
        if (it.act == this->fantasma)
            throw std::out_of_range("fuera de la lista");
        iterator next(it.act->sig, this->fantasma);
        this->borra_elem(it.act);
        return next;
    }
};

#endif // list_eda_h
#pragma once
