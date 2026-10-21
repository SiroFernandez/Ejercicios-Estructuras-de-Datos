// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

using namespace std;

struct Solucion {
    bool equilibrado;
    int altura;
};

template <class T>
Solucion equilibrado(bintree<T> const& arbol) {
    if (arbol.empty())
        return { true, 0 };

    Solucion sumaIzqda = equilibrado(arbol.left());
    Solucion sumaDrcha = equilibrado(arbol.right());

    bool soyEquilibrado = izq.equilibrado && der.equilibrado && abs(izq.altura - der.altura) <= 1;

    // ¿Cuál es nuestra altura? El más alto de los dos hijos + 1
    int miAltura = max(izq.altura, der.altura) + 1;

    // Devolvemos el paquete completo
    return { soyEquilibrado, miAltura };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<char> arbol = leerArbol('.');

    Solucion sol = equilibrado(arbol);

    if (sol.equilibrado) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}