// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

using namespace std;

struct Solucion {
    int tamSubArbol;
    int difMinima;
};

int numNodos(const bintree<int>& arbol) {
    if (arbol.empty())
        return 0;

    int nIzqda = numNodos(arbol.left());
    int nDrcha = numNodos(arbol.right());

    return nIzqda + nDrcha + 1;
}

// función que resuelve el problema
Solucion nodo_equilibrado (const bintree<int>& arbol, int N) {
    if (arbol.empty())
        return { 0, 10000 };

    Solucion izqda = nodo_equilibrado(arbol.left(), N);
    Solucion drcha = nodo_equilibrado(arbol.right(), N);

    int tamano = izqda.tamSubArbol + drcha.tamSubArbol + 1;
    int diferencia = abs(2 * tamano - N);
    int minimo = min({ diferencia, izqda.difMinima, drcha.difMinima });

    return{ tamano, minimo };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> arbol = leerArbol(-1);

    int nodos = numNodos(arbol);
    Solucion sol = nodo_equilibrado(arbol, nodos);

    cout << sol.difMinima << "\n";
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